cmake_minimum_required(VERSION 3.9)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

project(act CXX)

#### PROJECT SOURCE FILES ####

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SRC_FILE lexertk.hpp)

foreach(src ${SRC_FILE})
    list(APPEND SRC_FILES ${SOURCE_DIR}/${src})
endforeach(src ${SRC_FILE})

add_library(act_common ${SRC_FILES})

set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(TEST_FILE main.cpp lexer_tests.cpp)

foreach(test ${TEST_FILE})
    list(APPEND TEST_FILES ${TEST_DIR}/${test})
endforeach(test ${TEST_FILE})

add_executable(tests ${TEST_FILES})

#### PROJECT LINKED LIBRARIES ####

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(ACT_LIBS -lgcov)
else ()
    set(ACT_LIBS )
endif ()

target_link_libraries(act_common ${ACT_LIBS})
    
target_link_libraries(act ${ACT_LIBS} act_common)

target_link_libraries(tests ${ACT_LIBS} act_common)

#### PROJECT INCLUDE DIRECTORIES ####

set(ACT_INCLUDES
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src/util
    SYSTEM
        ${CMAKE_CURRENT_SOURCE_DIR}/external)

target_include_directories(act_common ${ACT_INCLUDES})
target_include_directories(act ${ACT_INCLUDES})
target_include_directories(tests ${ACT_INCLUDES} PRIVATE ${TEST_DIR})

#### PROJECT COMPILE OPTIONS ####

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    set(ACT_COMPILE_OPTIONS
        PUBLIC
            -Wall 
            -Wextra 
            -Werror=return-type
            -Werror=switch
            -Wshadow
        )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(ACT_COMPILE_OPTIONS
        PUBLIC
            -Wall 
            -Wextra 
            -Werror=return-type
            -Werror=switch
            -Wfatal-errors
            -Wshadow
            -Wnon-virtual-dtor
            -Wold-style-cast
            -Wcast-align
            -Wunused
            -Woverloaded-virtual
            -Wpedantic
            -Wconversion
            -Wsign-conversion
            -Wmisleading-indentation
            -Wduplicated-cond
            -Wlogical-op
            -Wnull-dereference
            -Wdouble-promotion
            -Wformat=2
            -fprofile-arcs 
            -ftest-coverage
            -Wno-unknown-pragmas
        )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(ACT_COMPILE_OPTIONS
        PUBLIC
            /W4
        )
endif()
   
# Assume same opts for all.
target_compile_options(dflat_common ${ACT_COMPILE_OPTIONS})
target_compile_options(dflat ${ACT_COMPILE_OPTIONS})
target_compile_options(tests ${ACT_COMPILE_OPTIONS})