# manager1 files
set(MANAGER1_SRC
    "src/manager1/manager1.cpp"
)
set(MANAGER1_INC
    "include/manager1"
    "src/manager1"
)

# manager2 files
set(MANAGER2_SRC
    "src/manager2/fibonacci.cpp"
    "src/manager2/manager2.cpp"
)
set(MANAGER2_INC
    "include/manager2"
)

# combined files
set(ZP_SRC
    ${MANAGER1_SRC}
    ${MANAGER2_SRC}
)
set(ZP_INC
    "include/driver_ifaces"
    ${MANAGER1_INC}
    ${MANAGER2_INC}
)