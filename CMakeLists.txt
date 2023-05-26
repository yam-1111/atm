cmake_minimum_required(VERSION 3.0)
project(atm2 C)

# Set the compiler based on the selected option


# Add the executable and specify the source files
add_executable(
    atm2 source/ATM-main-edited.c
    source/functions/ATM-functions-edited.c
    source/functions/ATM-functions-edited.h
    )

# cross-compatibility with windows os
if (NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("running on LINUX")
    target_link_libraries(atm2 ncurses)
endif()

# Include the directories containing the header files
target_include_directories(atm2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/source)
