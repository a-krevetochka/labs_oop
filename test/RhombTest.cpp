//
// Created by meteo on 20.10.2023.
//
#include "Rhomb.h"
#include "gtest/gtest.h"
class rhombTest : public ::testing::Test{
protected:
    void SetUp() override{
        _rhomb.setPeaks({Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1)});
    }
    void TearDown() override{}
    Rhomb _rhomb;
};

TEST_F(rhombTest, areaTest){
    double area = double (_rhomb);
    ASSERT_DOUBLE_EQ(4, area);
}

TEST_F(rhombTest, centerOfRoundingTest){
    Point centerOfRoundingTest = _rhomb.centerOfRounding();
    ASSERT_EQ(Point(2, 2), centerOfRoundingTest);
}

TEST_F(rhombTest, setterTest){
    Vector<Point> peaks = {Point(2, 2), Point(2, 4), Point(4, 4), Point(4, 2)};

    _rhomb.setPeaks(peaks);

    Vector<Point> result = _rhomb.getPeaks();
    ASSERT_EQ(peaks, result);
}

TEST_F(rhombTest, equalsTest){
    Vector<Point> peaks = {Point(2, 2), Point(2, 4), Point(4, 4), Point(4, 2)};
    Rhomb rhomb(peaks);

    bool result = _rhomb == rhomb;

    ASSERT_TRUE(result);
}

TEST_F(rhombTest, parametrizeConstructorTest){
    Vector<Point> peaks = {Point(2, 2), Point(2, 4), Point(4, 4), Point(4, 2)};
    Rhomb rhomb(peaks);

    ASSERT_EQ(peaks, rhomb.getPeaks());
}
