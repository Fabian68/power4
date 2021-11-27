#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Board.h"
#include "Canvas.h"
#include "graphics.h"

TEST_CASE("Testing the board") {
    Board b = Board();
    for (int i = 0;i < b.getCols();i++) {
        for (int j = 0;j < b.getRows();j++) {
            CHECK_EQ(b.getValue(i, j), 0);
        }
    }
   
    b.addDisc(0);
    CHECK_EQ(b.getValue(0, 0),PLAYER_1);
    
    b.addDisc(0);
    CHECK_EQ(b.getValue(0, 1), PLAYER_1);

    b.addDisc(0);
    CHECK_EQ(b.getValue(0, 2), PLAYER_1);

    b.addDisc(0);
    CHECK_EQ(b.getValue(0, 3), PLAYER_1);

    b.addDisc(0);
    CHECK_EQ(b.getValue(0, 4), PLAYER_1);

    CHECK_EQ(b.isFilled(0), false);

    b.addDisc(0);
    CHECK_EQ(b.getValue(0, 5), PLAYER_1);

    //b.addDisc(0, 1);
    CHECK_EQ(b.isFilled(0), true);
}

TEST_CASE("Tesing the canvas") {
    Board b = Board{};
    Canvas v = Canvas{ b };

    CHECK_EQ(v.getBoard()->getCols(), b.getCols());
    CHECK_EQ(v.getBoard()->getCols(), 7);

    CHECK_EQ(v.getBoard()->getRows(), b.getRows());
    CHECK_EQ(v.getBoard()->getRows(), 6);

    CHECK_EQ(v.getBoard()->getConnectedTokensToWin(), b.getConnectedTokensToWin());
    CHECK_EQ(v.getBoard()->getConnectedTokensToWin(), 4);
    
    v.drawDisc(0, 0, GREEN);
    v.drawDisc(5, 0, RED);
    while (!kbhit())
    {
        delay(200);
    }
}