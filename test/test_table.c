#include <ctest.h>
#include <stdio.h>
#include <table/parse.h>

// TODO: get some parseCell property tests / fuzzes going
// TODO: cases for different DataTypes

CTEST(parseTableSuite, valid) {
    int rows = 3, cols = 3;
    char *path = "test/res/valid.csv"; // assuming working directory is project directory
    char *actual[3][3] = {
            {"wait", "it's", "all"},
            {"a", "csv", "file?"},
            {"always", "has", "been."}
    };

    FILE *handle = fopen(path, "r");
    if (handle == NULL) {
        CTEST_LOG("failed to open valid.csv");
        ASSERT_FAIL();
    }

    Table *t = parseTable(path, rows, cols);
    ASSERT_NOT_NULL(t);
    ASSERT_EQUAL(t->height, rows);
    ASSERT_EQUAL(t->width, cols);
    for (int y = 0; y < t->height; ++y) {
        for (int x = 0; x < t->width; ++x) {
            ASSERT_EQUAL(t->table[y * cols + x]->kind, str);
            ASSERT_STR(t->table[y * cols + x]->data.str, actual[y][x]);
        }
    }
}

CTEST_SKIP(parseTableSuite, uneven) {
    // bug: strtok seperates "Impossible.,,,," into "Impossible." and "\n"
    // maybe use strsep loop instead? idk
    int rows = 3, cols = 5;
    char *path = "test/res/uneven.csv"; // assuming working directory is project directory
    char *actual[3][5] = {
            {"this","file","has","empty","cells"},
            {"Impossible.","","","",""},
            {"Perhaps","the","archives","are","incomplete."}
    };

    FILE *handle = fopen(path, "r");
    if (handle == NULL) {
        CTEST_LOG("failed to open uneven.csv");
        ASSERT_FAIL();
    }

    Table *t = parseTable(path, rows, cols);
    ASSERT_NOT_NULL(t);
    ASSERT_EQUAL(rows, t->height);
    ASSERT_EQUAL(cols, t->width);
    for (int y = 0; y < t->height; ++y) {
        for (int x = 0; x < t->width; ++x) {
            ASSERT_EQUAL(str, t->table[y * cols + x]->kind);
            ASSERT_STR(actual[y][x], t->table[y * cols + x]->data.str);
        }
    }
}

CTEST(parseTableSuite, empty) {
    int rows = 0, cols = 0;
    char *path = "test/res/empty.csv"; // assuming working directory is project directory

    FILE *handle = fopen(path, "r");
    if (handle == NULL) {
        CTEST_LOG("failed to open empty.csv");
        ASSERT_FAIL();
    }

    Table *t = parseTable(path, rows, cols);
    ASSERT_NULL(t);
}

// TODO: file für \r und \r\n