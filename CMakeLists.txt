##
# Jakob Janzen
# jakob.janzen80@gmail.com
# 2022-09-24
##
set(__MINIMUM_VERSION 3.15)
cmake_minimum_required(VERSION ${__MINIMUM_VERSION} FATAL_ERROR)

project(MinUnit
    VERSION
        1.0.0
    DESCRIPTION
        "A minimal untit testing framework for C/C++ with examples."
    LANGUAGES
        C;CXX
)

set(PRJ_DIR_ "${PROJECT_SOURCE_DIR}")
set(PRJ_INCLUDE_DIR_ "${PRJ_DIR_}/include")
set(PRJ_SOURCE_DIR_ "${PRJ_DIR_}/src")
set(PRJ_BINARY_DIR_ "${PRJ_DIR_}/bin")

message(STATUS "[PROJECT] - ${PROJECT_NAME} ${PROJECT_VERSION}")
message(STATUS "\t${PROJECT_DESCRIPTION}")
message(STATUS "Project root directory: ${PRJ_DIR_}")
message(STATUS "Project include directory: ${PRJ_INCLUDE_DIR_}")
message(STATUS "Project source directory: ${PRJ_SOURCE_DIR_}")
message(STATUS "Project binary directory: ${PRJ_BINARY_DIR_}")

add_executable(minunit_example_c)
target_sources(minunit_example_c PRIVATE "${PRJ_SOURCE_DIR_}/minunit_example.c")
target_include_directories(minunit_example_c PRIVATE "${PRJ_INCLUDE_DIR_}")
set_target_properties(minunit_example_c PROPERTIES
    LINKER_LANGUAGE C
    C_STANDARD 11
    RUNTIME_OUTPUT_DIRECTORY ${PRJ_BINARY_DIR_}
)

add_executable(minunit_example_cxx)
target_sources(minunit_example_cxx PRIVATE "${PRJ_SOURCE_DIR_}/minunit_example.cxx")
target_include_directories(minunit_example_cxx PRIVATE "${PRJ_INCLUDE_DIR_}")
set_target_properties(minunit_example_cxx PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    RUNTIME_OUTPUT_DIRECTORY ${PRJ_BINARY_DIR_}
)