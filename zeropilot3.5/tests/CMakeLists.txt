cmake_minimum_required(VERSION 3.18)
project(gtestzeropilot3.5)

# ========== test files begin ==========
# manager1 test files
set(MANAGER1_TSRC
    "${CMAKE_SOURCE_DIR}/manager1/11001_blink_order.cpp"
)

# manager2 test files
set(MANAGER2_TSRC
    "${CMAKE_SOURCE_DIR}/manager2/21001_fib_counter.cpp"
)

# all test files
set(ALL_TSRC
    ${MANAGER1_TSRC}
    ${MANAGER2_TSRC}
)
# ========== test files end ==========

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
enable_testing()

include(${CMAKE_SOURCE_DIR}/../common.cmake)
include(GoogleTest)

set(RELATIVE_ZP_SRC)
foreach(SRC_FILE IN LISTS ZP_SRC)
    string(PREPEND SRC_FILE "${CMAKE_SOURCE_DIR}/../")
    list(APPEND RELATIVE_ZP_SRC ${SRC_FILE})
endforeach()

set(RELATIVE_ZP_INC)
foreach(INC_FILE IN LISTS ZP_INC)
    string(PREPEND INC_FILE "${CMAKE_SOURCE_DIR}/../")
    list(APPEND RELATIVE_ZP_INC ${INC_FILE})
endforeach()

add_executable(${PROJECT_NAME} 
    ${RELATIVE_ZP_SRC} 
    ${ALL_TSRC}
)
target_include_directories(${PROJECT_NAME} 
    PRIVATE ${RELATIVE_ZP_INC} 
    PRIVATE "${CMAKE_SOURCE_DIR}/driver_mocks"
)
target_link_libraries(${PROJECT_NAME} GTest::gmock_main)

gtest_discover_tests(${PROJECT_NAME})
