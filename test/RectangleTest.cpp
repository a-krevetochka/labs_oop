//
// Created by meteo on 20.10.2023.
//
#include "Rectangle.h"
#include "gtest/gtest.h"
class RectangleTest : public ::testing::Test{
protected:
    void SetUp() override{
        _rectangle.setPeaks({Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1)});
    }
    void TearDown() override{}
    Rectangle<int> _rectangle;
};

TEST_F(RectangleTest, areaTest){
    double area = double (_rectangle);
    ASSERT_DOUBLE_EQ(4, area);
}

TEST_F(RectangleTest, centerOfRoundingTest){
    Point centerOfRoundingTest = _rectangle.centerOfRounding();
    ASSERT_EQ(Point(2, 2), centerOfRoundingTest);
}

TEST_F(RectangleTest, setterTest){
    Vector<Point<int>> peaks = {Point(2, 2), Point(2, 4), Point(4, 4), Point(4, 2)};

    _rectangle.setPeaks(peaks);

    Vector<Point<int>> result = _rectangle.getPeaks();
    ASSERT_EQ(peaks, result);
}

TEST_F(RectangleTest, equalsTest){
    Vector<Point<int>> peaks = {Point(2, 2), Point(2, 4), Point(4, 4), Point(4, 2)};
    Rectangle rectangle(peaks);

    bool result = _rectangle == rectangle;

    ASSERT_TRUE(result);
}

TEST_F(RectangleTest, parametrizeConstructorTest){
    Vector<Point<int>> peaks = {Point(2, 2), Point(2, 4), Point(4, 4), Point(4, 2)};
    Rectangle rectangle(peaks);

    Vector<Point<int>> result = rectangle.getPeaks();

    ASSERT_EQ(peaks, result);
}