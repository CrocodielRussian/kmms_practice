#include <gtest/gtest.h>

#include "long_number.hpp"
#include <iostream>

TEST(get_digits_number, check_positive) {
	IBusko::LongNumber x("12345");
	ASSERT_EQ(5, x.get_digits_number())
		<< "Is not equals length of positive number" << x.get_digits_number();
}
TEST(get_digits_number, check_negative) {
    IBusko::LongNumber x("-1");
    ASSERT_EQ(1, x.get_digits_number())
        << "Is not equals length of negative number " << x.get_digits_number() << x;
}
TEST(get_numbers, check_sum1) {
	IBusko::LongNumber x("12345");
	ASSERT_EQ(12345, x.get_sum())
		<< "Trouble with write positive num " << x.get_sum();
}
TEST(get_numbers, check_sum2) {
    IBusko::LongNumber x("-12345");
    ASSERT_EQ(12345, x.get_sum())
    << "Trouble with write negative num " << x.get_sum();
}
//TEST(check_operator, first){
//
//}
//TEST(check_operator, second){
//
//}
//TEST(check_operator, third){
//
//}
class EqualityFixture : public testing::Test {
	public:
		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
        IBusko::LongNumber one_hundred_three = IBusko::LongNumber("103");
        IBusko::LongNumber one_hundred_two = IBusko::LongNumber("102");
};

TEST_F(EqualityFixture, equal) {
	ASSERT_TRUE(one_v1 == one_v2) << "Equal numbers is not equal " << one_v1.get_sum() << " != " << one_v2.get_sum();
}

TEST_F(EqualityFixture, not_equal) {
	ASSERT_FALSE(one_v1 == twelve) << "Not equal numbers is equal " << one_v1.get_sum() << " == " << twelve.get_sum();
}

TEST_F(EqualityFixture, not_equal_negative_var) {
	ASSERT_FALSE(one_v1 == negative_one)
		<< "Negative five equal to positive " << one_v1.get_sum() << " == " << negative_one.get_sum();
}
TEST_F(EqualityFixture, different_numbers_with_equal_length) {
    ASSERT_FALSE(one_hundred_three == one_hundred_two)
        << "It's not equal numbers " << one_hundred_three.get_sum() << " == " << one_hundred_two.get_sum();
}

class MoreFixture : public testing::Test {
public:
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber one_hundred_three = IBusko::LongNumber("103");
    IBusko::LongNumber one_hundred_two = IBusko::LongNumber("102");
};

TEST_F(MoreFixture, eq_nums){
    ASSERT_FALSE(one_v1 > one_v2)
        << "It's equal nums " << one_v1.get_sum() << " > " << one_v2.get_sum();
}
TEST_F(MoreFixture, pos_more_then_neg){
    ASSERT_TRUE(one_v1 > negative_one)
        << "A positive num less then a negative num " << negative_one.get_sum() << " > " << one_v1.get_sum();
}
TEST_F(MoreFixture, different_numbers_with_equal_length){
    ASSERT_TRUE(one_hundred_three > one_hundred_two)
        << "An One hundred three less then an one hundred two " << one_hundred_two.get_sum() << " > " << one_hundred_three.get_sum();
}

class LessFixture : public testing::Test {
public:
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber one_hundred_three = IBusko::LongNumber("103");
    IBusko::LongNumber one_hundred_two = IBusko::LongNumber("102");
};

TEST_F(LessFixture, eq_nums){
    ASSERT_FALSE(one_v1 < one_v2)
        << "It's equal nums " << one_v1.get_sum() << " > " << one_v2.get_sum();
}
TEST_F(LessFixture, pos_more_then_neg){
    ASSERT_TRUE(negative_one < one_v1)
        << "A negative num more then a positive num " << negative_one.get_sum() << " > " << one_v1.get_sum();
}
TEST_F(LessFixture, different_numbers_with_equal_length){
    ASSERT_TRUE(one_hundred_two < one_hundred_three)
        << "An One hundred two more then an one hundred three " << one_hundred_three.get_sum() << " < " << one_hundred_two.get_sum();
}

class SumFixture : public testing::Test {
    public:
        IBusko::LongNumber one = IBusko::LongNumber("1");
        IBusko::LongNumber two = IBusko::LongNumber("2");
        IBusko::LongNumber nine = IBusko::LongNumber("9");
        IBusko::LongNumber thirteen = IBusko::LongNumber("13");
        IBusko::LongNumber ninety_nine_pos = IBusko::LongNumber("99");
        IBusko::LongNumber ninety_nine_neg = IBusko::LongNumber("-99");
};

TEST_F(SumFixture, simple_sum){
    IBusko::LongNumber a = one + two;
    ASSERT_EQ(3, a.get_sum())
        << "It's not three";
}
TEST_F(SumFixture, next_capacity){
    IBusko::LongNumber a = two + nine;
    ASSERT_EQ(11, a.get_sum())
        << "It's not eleven";
}
TEST_F(SumFixture, negative_plus_positive){
    IBusko::LongNumber a = ninety_nine_pos + ninety_nine_neg;
    ASSERT_EQ(0, a.get_sum())
        << "It's not 0";
}
TEST_F(SumFixture, associated){
    IBusko::LongNumber a = thirteen + nine;
    ASSERT_EQ(22, a.get_sum())
        << "It's not 22";
}


int main(int argc, char **argv) {
//    IBusko::LongNumber x("102");
//    IBusko::LongNumber y("103");
//
//    std::cout << (x == y) << "\n";
//
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

    return 0;
}
