cmake_minimum_required(VERSION 3.15)
project(tabelle LANGUAGES C)

set(CMAKE_C_STANDARD 99)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    message("building for debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")
endif ()

# build
add_executable(tabelle
        src/main.c
        src/table/parse.c src/table/parse.h
        src/file.c src/file.h src/table/print.c src/table/print.h src/table/modify.c src/table/modify.h src/table/types.h src/cli/cli.c src/cli/cli.h src/cli/commands/printCommand.c src/cli/commands/printCommand.h src/cli/commands/setCommand.c src/cli/commands/setCommand.h src/cli/commands/saveCommand.c src/cli/commands/saveCommand.h src/cli/commands/sumColCommand.c src/cli/commands/sumColCommand.h src/table/sort.c src/table/sort.h src/cli/commands/sortCommand.c src/cli/commands/sortCommand.h)


# tests
add_executable(tabelle_test
        vendor/ctest.h
        test/test_main.c
        test/test_table.c src/table/parse.c src/table/parse.h
        test/test_file.c src/file.c src/file.h src/table/modify.c src/table/modify.h)
target_include_directories(tabelle_test PRIVATE vendor src)