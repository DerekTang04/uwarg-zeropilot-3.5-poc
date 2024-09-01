cmake_minimum_required(VERSION 3.12)
project(zeropilot3.5)

add_library(zeropilot3.5 STATIC
    src/manager1/manager1.cpp
    src/manager2/fibonacci.cpp
    src/manager2/manager2.cpp
)
target_include_directories(zeropilot3.5 
    PRIVATE include/driver_ifaces
    PRIVATE include/manager1
    PRIVATE include/manager2
    PRIVATE src/manager1
)

include(GNUInstallDirs)
set(ARTIFACTS_DIR "artifacts")
set(INC_DIR "${ARTIFACTS_DIR}/${CMAKE_INSTALL_INCLUDEDIR}")
set(LIB_DIR "${ARTIFACTS_DIR}/${CMAKE_INSTALL_LIBDIR}")

install(DIRECTORY include/driver_ifaces/
    DESTINATION "${INC_DIR}/driver_ifaces"
    FILES_MATCHING PATTERN "*.hpp"
)

install(DIRECTORY include/manager1/
    DESTINATION "${INC_DIR}/manager1"
    FILES_MATCHING PATTERN "*.hpp"
)

install(DIRECTORY include/manager2/
    DESTINATION "${INC_DIR}/manager2"
    FILES_MATCHING PATTERN "*.hpp"
)

install(TARGETS zeropilot3.5
    ARCHIVE DESTINATION "${LIB_DIR}"
)
