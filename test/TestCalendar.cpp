#include <gtest/gtest.h>
#include "calendar.h"

// 测试合法日期的情况
TEST(JulDayTest, ValidDates) {
    EXPECT_EQ(JulDay(3, 15, 2023), 2460024);  // 2023年3月15日
    EXPECT_EQ(JulDay(1, 1, 2000), 2451545);   // 2000年1月1日 (新千年)
    EXPECT_EQ(JulDay(12, 31, -500), 1355671); // 公元前500年12月31日
}

// 测试格里高利历改革后的日期
TEST(JulDayTest, GregorianReform) {
    EXPECT_EQ(JulDay(10, 15, 1582), 2299161); // 1582年10月15日（格里高利历开始）
    EXPECT_EQ(JulDay(10, 4, 1582), 2299150);  // 1582年10月4日（格里高利历改革前）
}

// 测试错误输入（年份为0）
TEST(JulDayTest, YearZero) {
    EXPECT_THROW(JulDay(3, 15, 0), std::runtime_error); // 年份为0，不存在
}

// 测试不同月份的转换
TEST(JulDayTest, MonthConversion) {
    EXPECT_EQ(JulDay(2, 28, 2023), 2460018); // 2023年2月28日
    EXPECT_EQ(JulDay(3, 1, 2023), 2460019);  // 2023年3月1日
}

// 测试公元前年份的处理
TEST(JulDayTest, NegativeYearHandling) {
    EXPECT_EQ(JulDay(7, 4, -44), 1706306); // 公元前44年7月4日
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
