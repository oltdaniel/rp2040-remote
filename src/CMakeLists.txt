add_executable(main
    main.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(main pico_stdlib hardware_irq)

# Add USB serial output
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)