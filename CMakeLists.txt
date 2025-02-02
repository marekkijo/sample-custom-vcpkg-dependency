cmake_minimum_required(VERSION 3.15)

project(libdependency CXX)

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
  target_compile_definitions(${PROJECT_NAME} PRIVATE LIBDEPENDENCY_EXPORTS)
  target_compile_definitions(${PROJECT_NAME} PUBLIC LIBDEPENDENCY_SHARED)
else()
  target_compile_definitions(${PROJECT_NAME} PUBLIC LIBDEPENDENCY_STATIC)
endif()

install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dependency
)
