#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Board.h"
#include "Canvas.h"
#include "graphics.h"

TEST_CASE("Testing the board") {
    Board b = Board();
    for (int i = 0;i < b.numbersOfColumn();i++) {
        for (int j = 0;j < b.numbersOfLine();j++) {
            CHECK_EQ(b.value(i, j), 0);
        }
    }
    
    b.addDisc(0, 1);
    CHECK_EQ(b.value(0, 0), 1);

    b.addDisc(0, 1);
    CHECK_EQ(b.value(0, 1), 1);

    b.addDisc(0, 1);
    CHECK_EQ(b.value(0, 2), 1);

    b.addDisc(0, 1);
    CHECK_EQ(b.value(0, 3), 1);

    b.addDisc(0, 1);
    CHECK_EQ(b.value(0, 4), 1);

    CHECK_EQ(b.isFilled(0), false);

    b.addDisc(0, 1);
    CHECK_EQ(b.value(0, 5), 1);

    //b.addDisc(0, 1);
    CHECK_EQ(b.isFilled(0), true);
}

TEST_CASE("Tesing the canvas") {
    Canvas v = Canvas(7,6);
    v.drawDisc(0, 0, GREEN);
    v.drawDisc(5, 0, RED);
    while (!kbhit())
    {
        delay(200);
    }
}