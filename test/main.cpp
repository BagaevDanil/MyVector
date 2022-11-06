#include "gtest/gtest.h"
#include "../src/TMyVector.h"

TEST(TMyVector, GetSize) {
    TMyVector<int> vec(15);
    EXPECT_EQ(vec.GetSize(), 0);
}

TEST(TMyVector, GetReservSize) {
    TMyVector<int> vec(15);
    EXPECT_EQ(vec.GetReservSize(), 15);
}

TEST(TMyVector, Insert) {
    TMyVector<int> vec(15);
    EXPECT_EQ(vec.GetSize(), 0);
    EXPECT_EQ(vec.GetReservSize(), 15);

    vec.Insert(0, 10); // 10
    vec.Insert(0, 1); // 1 10
    vec.Insert(1, 23); // 1 23 10
    vec.Insert(3, 43); // 1 23 10 43

    EXPECT_EQ(vec.GetValue(0), 1);
    EXPECT_EQ(vec.GetValue(1), 23);
    EXPECT_EQ(vec.GetValue(2), 10);
    EXPECT_EQ(vec.GetValue(3), 43);
}

TEST(TMyVector, Reserv) {
    TMyVector<int> vec(15);
    EXPECT_EQ(vec.GetSize(), 0);
    EXPECT_EQ(vec.GetReservSize(), 15);

    vec.Reserv(101);

    EXPECT_EQ(vec.GetSize(), 0);
    EXPECT_EQ(vec.GetReservSize(), 101);
}

TEST(TMyVector, Delete) {
    TMyVector<int> vec(15);
    EXPECT_EQ(vec.GetSize(), 0);
    EXPECT_EQ(vec.GetReservSize(), 15);

    for (int i = 0; i < 10; i++) {
        vec.PushBack(i);
    } // 0 1 2 3 4 5 6 7 8 9 # # # # #

    vec.Delete(0); // 1 2 3 4 5 6 7 8 9
    vec.Delete(0); // 2 3 4 5 6 7 8 9
    vec.Delete(4); // 2 3 4 5 7 8 9
    vec.Delete(6); // 2 3 4 5 7 8
    vec.Delete(0); // 3 4 5 7 8
    vec.Delete(3); // 3 4 5 8

    EXPECT_EQ(vec.GetValue(0), 3);
    EXPECT_EQ(vec.GetValue(1), 4);
    EXPECT_EQ(vec.GetValue(2), 5);
    EXPECT_EQ(vec.GetValue(3), 8);
}

int main()
{
    testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}