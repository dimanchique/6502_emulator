cmake_minimum_required(VERSION 3.16)
project(CPU_Emulator)

set(CMAKE_CXX_STANDARD 17)

option(print_tests_performance "Enable performance data output on ASM tests" OFF)

# Add the preprocessor definition based on the user's choice
if(print_tests_performance)
    add_compile_definitions(TEST_EXECUTION_PERFORMANCE)
endif()

include_directories(inc)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/Operations/*.cpp)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)

set(DATA_DIRECTORY "${CMAKE_SOURCE_DIR}/tools/asm_tests")
file(GLOB subdirectories "${DATA_DIRECTORY}/*")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

foreach(subdirectory ${subdirectories})
    if(IS_DIRECTORY ${subdirectory})
        # Get the name of the subdirectory
        get_filename_component(subdir_name ${subdirectory} NAME)

        # Specify the destination folder in the build directory
        set(destination "${BINARY_DIR}/tools/asm_tests/${subdir_name}")

        # Copy only the files matching the pattern *.bin
        file(GLOB files_to_copy CONFIGURE_DEPENDS "${subdirectory}/*.bin")

        # Copy the files to the destination
        foreach(file ${files_to_copy})
            get_filename_component(filename ${file} NAME)
            configure_file(${file} ${destination}/${filename} COPYONLY)
        endforeach()
    endif()
endforeach()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(tests/MOS6502)
add_executable(CPU_Emulator main.cpp ${SRC_FILES})
