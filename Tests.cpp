#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Board.h"



TEST_CASE("Testing the board") {
    Board b = Board();
    for (int i = 0;i < b.getCols();i++) {
        for (int j = 0;j < b.getRows();j++) {
            CHECK_EQ(b.getValue(i, j), 0);
        }
    }
    
    b.addDisc(0, 1);
    CHECK_EQ(b.getValue(0, 0), 1);

    b.addDisc(0, 1);
    CHECK_EQ(b.getValue(0, 1), 1);

    b.addDisc(0, 1);
    CHECK_EQ(b.getValue(0, 2), 1);

    b.addDisc(0, 1);
    CHECK_EQ(b.getValue(0, 3), 1);

    b.addDisc(0, 1);
    CHECK_EQ(b.getValue(0, 4), 1);

    CHECK_EQ(b.isFilled(0), false);

    b.addDisc(0, 1);
    CHECK_EQ(b.getValue(0, 5), 1);

    //b.addDisc(0, 1);
    CHECK_EQ(b.isFilled(0), true);
}