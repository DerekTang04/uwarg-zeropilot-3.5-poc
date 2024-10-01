cmake_minimum_required(VERSION 3.12)
project(zeropilot3.5)

include(${CMAKE_SOURCE_DIR}/common.cmake)

set(MODIFIED_ZP_SRC)
foreach(SRC_FILE IN LISTS ZP_SRC)
    string(PREPEND SRC_FILE "${CMAKE_SOURCE_DIR}/")
    list(APPEND MODIFIED_ZP_SRC ${SRC_FILE})
endforeach()

set(MODIFIED_ZP_INC)
foreach(INC_FILE IN LISTS ZP_INC)
    string(PREPEND INC_FILE "${CMAKE_SOURCE_DIR}/")
    list(APPEND MODIFIED_ZP_INC ${INC_FILE})
endforeach()

add_library(${PROJECT_NAME} STATIC ${ZP_SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${ZP_INC})
