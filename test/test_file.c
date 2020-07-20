#include <ctest.h>
#include <stdio.h>
#include <file.h>

CTEST(countSuite, valid) {
    char *path = "test/res/valid.csv"; // assuming working directory is project directory

    FILE *handle = fopen(path, "r");
    if (handle == NULL) {
        CTEST_LOG("failed to open valid.csv");
        ASSERT_FAIL();
    }

    int rows, cols;
    ASSERT_EQUAL(countRowsAndColumns(path, &rows, &cols), 0);
    ASSERT_EQUAL(3, rows);
    ASSERT_EQUAL(3, cols);
}

CTEST(countSuite, uneven) {
    char *path = "test/res/uneven.csv"; // assuming working directory is project directory

    FILE *handle = fopen(path, "r");
    if (handle == NULL) {
        CTEST_LOG("failed to open uneven.csv");
        ASSERT_FAIL();
    }

    int rows, cols;
    ASSERT_EQUAL(countRowsAndColumns(path, &rows, &cols), 0);
    ASSERT_EQUAL(3, rows);
    ASSERT_EQUAL(5, cols);
}

CTEST(countSuite, empty) {
    char *path = "test/res/empty.csv"; // assuming working directory is project directory

    FILE *handle = fopen(path, "r");
    if (handle == NULL) {
        CTEST_LOG("failed to open empty.csv");
        ASSERT_FAIL();
    }

    int rows, cols;
    ASSERT_EQUAL(countRowsAndColumns(path, &rows, &cols), 0);
    ASSERT_EQUAL(0, rows);
    ASSERT_EQUAL(0, cols);
}