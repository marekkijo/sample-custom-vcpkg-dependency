cmake_minimum_required(VERSION 3.15)

project(libdependency VERSION 0.0.3 LANGUAGES CXX)

include(GNUInstallDirs)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

set(LIBDEPENDENCY_SOURCES
  src/dependency/dependency.cpp
)

set(LIBDEPENDENCY_HEADERS
  src/dependency/dependency_export.hpp
  src/dependency/dependency.hpp
)

add_library(${PROJECT_NAME} ${LIBDEPENDENCY_SOURCES} ${LIBDEPENDENCY_HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE src)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_INSTALL_INCLUDEDIR})

set_target_properties(
  ${PROJECT_NAME} PROPERTIES
    PUBLIC_HEADER "${LIBDEPENDENCY_HEADERS}"
)

if(BUILD_SHARED_LIBS)
  target_compile_definitions(${PROJECT_NAME} PRIVATE LIBDEPENDENCY_EXPORTS INTERFACE LIBDEPENDENCY_IMPORTS)
endif()

install(
  TARGETS ${PROJECT_NAME}
  EXPORT libdependencyTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dependency
)

install(
  EXPORT libdependencyTargets
  FILE libdependencyTargets.cmake
  NAMESPACE libdependency::
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/share/${PROJECT_NAME}/cmake
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  libdependencyConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

configure_file(
  libdependencyConfig.cmake.in
  libdependencyConfig.cmake
  @ONLY
)

install(
  FILES
  libdependencyConfig.cmake
  libdependencyConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/share/${PROJECT_NAME}/cmake
)

#file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
