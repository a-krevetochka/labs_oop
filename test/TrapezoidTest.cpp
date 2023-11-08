//
// Created by meteo on 20.10.2023.
//
#include "Trapezoid.h"
#include "gtest/gtest.h"
class TrapezoidTest : public ::testing::Test{
protected:
    void SetUp() override{
        _trapezoid.setPeaks({Point(0, 0), Point(2, 6), Point(8, 6), Point(10, 0)});
    }
    void TearDown() override{}
    Trapezoid<int> _trapezoid;
};

TEST_F(TrapezoidTest, areaTest){
    double area = double (_trapezoid);
    ASSERT_DOUBLE_EQ(48, area);
}

TEST_F(TrapezoidTest, centerOfRoundingTest){
    Point centerOfRoundingTest = _trapezoid.centerOfRounding();
    ASSERT_EQ(Point(5, 3), centerOfRoundingTest);
}

TEST_F(TrapezoidTest, setterTest){
    Vector<Point<int>> peaks = {Point(1, 1), Point(3, 7), Point(9, 7), Point(11, 1)};

    _trapezoid.setPeaks(peaks);

    Vector<Point<int>> result = _trapezoid.getPeaks();
    ASSERT_EQ(peaks, result);
}

TEST_F(TrapezoidTest, equalsTest){
    Vector<Point<int>> peaks = {Point(1, 1), Point(3, 7), Point(9, 7), Point(11, 1)};
    Trapezoid trapezoid(peaks);

    bool result = _trapezoid == trapezoid;

    ASSERT_TRUE(result);
}

TEST_F(TrapezoidTest, parametrizeConstructorTest){
    Vector<Point<int>> peaks = {Point(1, 1), Point(3, 7), Point(9, 7), Point(11, 1)};
    Trapezoid trapezoid(peaks);

    Vector<Point<int>> result = trapezoid.getPeaks();

    ASSERT_EQ(peaks, result);
}