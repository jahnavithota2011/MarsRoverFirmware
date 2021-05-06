add_executable(test-limit-switch.${TARGET}-board.elf)
target_sources(test-limit-switch.${TARGET}-board.elf PRIVATE src/main.cpp)
target_link_libraries(test-limit-switch.${TARGET}-board.elf PRIVATE LimitSwitch Logger)
target_set_firmware_properties(test-limit-switch.${TARGET}-board.elf)
