cmake_minimum_required(VERSION 3.15)

project(libdependency CXX)

set(LIBDEPENDENCY_SOURCES
    src/dependency/dependency.cpp
)

set(LIBDEPENDENCY_HEADERS
    src/dependency/dependency.hpp
)

add_library(${PROJECT_NAME} SHARED ${LIBDEPENDENCY_SOURCES} ${LIBDEPENDENCY_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC src)

set_target_properties(
  ${PROJECT_NAME} PROPERTIES
    PUBLIC_HEADER "${LIBDEPENDENCY_HEADERS}"
)

install(
  TARGETS ${PROJECT_NAME}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dependency
)
