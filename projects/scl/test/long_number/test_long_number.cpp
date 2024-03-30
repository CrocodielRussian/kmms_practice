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
	ASSERT_TRUE(one_v1 == one_v2) << "Equal numbers is not equal " << one_v1<< " != " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
	ASSERT_FALSE(one_v1 == twelve) << "Not equal numbers is equal " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
	ASSERT_FALSE(one_v1 == negative_one)
		<< "Negative five equal to positive " << one_v1 << " == " << negative_one;
}
TEST_F(EqualityFixture, different_numbers_with_equal_length) {
    ASSERT_FALSE(one_hundred_three == one_hundred_two)
        << "It's not equal numbers " << one_hundred_three << " == " << one_hundred_two;
}

class MoreFixture : public testing::Test {
public:
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber one_hundred_three = IBusko::LongNumber("103");
    IBusko::LongNumber one_hundred_two = IBusko::LongNumber("102");
    IBusko::LongNumber fifteen_neg = IBusko::LongNumber("-15");
    IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
};

TEST_F(MoreFixture, eq_nums){
    ASSERT_FALSE(one_v1 > one_v2)
        << "It's equal nums " << one_v1 << " > " << one_v2;
}
TEST_F(MoreFixture, pos_more_then_neg){
    ASSERT_TRUE(one_v1 > negative_one)
        << "A positive num less then a negative num " << negative_one << " > " << one_v1;
}
TEST_F(MoreFixture, different_numbers_with_equal_length){
    ASSERT_TRUE(one_hundred_three > one_hundred_two)
        << "An One hundred three less then an one hundred two " << one_hundred_two << " > " << one_hundred_three;
}
TEST_F(MoreFixture, more_neg_logical1){
    ASSERT_FALSE(fifteen_neg > thirteen_neg)
        << "Incorrect negative logical " << fifteen_neg << " > " << thirteen_neg;
}
TEST_F(MoreFixture, more_neg_logical2){
    ASSERT_TRUE(thirteen_neg > fifteen_neg)
        << "Incorrect negative logical " << fifteen_neg << " > " << thirteen_neg;
}


class LessFixture : public testing::Test {
public:
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber one_hundred_three = IBusko::LongNumber("103");
    IBusko::LongNumber one_hundred_two = IBusko::LongNumber("102");
    IBusko::LongNumber fifteen_neg = IBusko::LongNumber("-15");
    IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
};

TEST_F(LessFixture, eq_nums){
    ASSERT_FALSE(one_v1 < one_v2)
        << "It's equal nums " << one_v1 << " > " << one_v2;
}
TEST_F(LessFixture, pos_more_then_neg){
    ASSERT_TRUE(negative_one < one_v1)
        << "A negative num more then a positive num " << negative_one << " > " << one_v1;
}
TEST_F(LessFixture, different_numbers_with_equal_length){
    ASSERT_TRUE(one_hundred_two < one_hundred_three)
        << "An One hundred two more then an one hundred three " << one_hundred_three << " < " << one_hundred_two;
}
TEST_F(LessFixture, less_neg_logical1){
    ASSERT_TRUE(fifteen_neg < thirteen_neg)
    << "Incorrect negative logical " << thirteen_neg << " < " << fifteen_neg;
}
TEST_F(LessFixture, less_neg_logical2){
    ASSERT_FALSE(thirteen_neg < fifteen_neg)
        << "Incorrect negative logical " << thirteen_neg << " < " << fifteen_neg;
}
class SumFixture : public testing::Test {
    public:
        IBusko::LongNumber zero = IBusko::LongNumber("0");
        IBusko::LongNumber one = IBusko::LongNumber("1");
        IBusko::LongNumber two = IBusko::LongNumber("2");
        IBusko::LongNumber p_3 = IBusko::LongNumber("3");
        IBusko::LongNumber nine = IBusko::LongNumber("9");
        IBusko::LongNumber p_11 = IBusko::LongNumber("11");
        IBusko::LongNumber p_14 = IBusko::LongNumber("14");
        IBusko::LongNumber thirteen = IBusko::LongNumber("13");
        IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
        IBusko::LongNumber twenty_seven = IBusko::LongNumber("27");
        IBusko::LongNumber ninety_nine_pos = IBusko::LongNumber("99");
        IBusko::LongNumber ninety_nine_neg = IBusko::LongNumber("-99");
        IBusko::LongNumber one_hundred_eight = IBusko::LongNumber("108");
        IBusko::LongNumber p_22 = IBusko::LongNumber("22");
};

TEST_F(SumFixture, simple_sum){
    IBusko::LongNumber a = one + two;
    ASSERT_EQ(p_3, a)
        << "It's not three";
}
TEST_F(SumFixture, next_capacity){
    IBusko::LongNumber a = two + nine;
    ASSERT_EQ(p_11, a)
        << "It's not eleven";
}
TEST_F(SumFixture, negative_plus_positive){
    IBusko::LongNumber a = ninety_nine_pos + ninety_nine_neg;
    ASSERT_EQ(zero, a)
        << "It's not 0";
}
TEST_F(SumFixture, associated1){
    IBusko::LongNumber a = thirteen + nine;
    ASSERT_EQ(p_22, a)
        << "It's not 22";
}
TEST_F(SumFixture, sum_of_nums_with_different_capacity){
    IBusko::LongNumber a = ninety_nine_neg + one_hundred_eight;
    ASSERT_EQ(nine, a)
        << "It's not 9";
}
TEST_F(SumFixture, sum_with_bugs){
    IBusko::LongNumber a = twenty_seven + thirteen_neg;
    ASSERT_EQ(p_14, a)
        << "It's not 14";
}
TEST_F(SumFixture, associated2){
    IBusko::LongNumber a = thirteen_neg + twenty_seven;
    ASSERT_EQ(p_14, a)
        << "It's not 14";
}

class DifferenceFixture : public testing::Test{
    public:
        IBusko::LongNumber zero = IBusko::LongNumber("0");
        IBusko::LongNumber p_1 = IBusko::LongNumber("1");
        IBusko::LongNumber n_1 = IBusko::LongNumber("-1");
        IBusko::LongNumber two = IBusko::LongNumber("2");
        IBusko::LongNumber three = IBusko::LongNumber("3");
        IBusko::LongNumber p_4 = IBusko::LongNumber("4");
        IBusko::LongNumber n_4 = IBusko::LongNumber("-4");
        IBusko::LongNumber nine = IBusko::LongNumber("9");
        IBusko::LongNumber p_10 = IBusko::LongNumber("10");
        IBusko::LongNumber p_11 = IBusko::LongNumber("11");
        IBusko::LongNumber twelve = IBusko::LongNumber("12");
        IBusko::LongNumber thirteen = IBusko::LongNumber("13");
        IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
        IBusko::LongNumber twenty_seven = IBusko::LongNumber("27");
        IBusko::LongNumber ninety_nine_pos = IBusko::LongNumber("99");
        IBusko::LongNumber ninety_nine_neg = IBusko::LongNumber("-99");
        IBusko::LongNumber one_hundred_eight = IBusko::LongNumber("108");
        IBusko::LongNumber p_198 = IBusko::LongNumber("198");
};

TEST_F(DifferenceFixture, simple_diff1){
    IBusko::LongNumber a = p_1 - two;
    ASSERT_EQ(n_1, a)
        << "It's not minus one";
}
TEST_F(DifferenceFixture, simple_diff2){
    IBusko::LongNumber a = two - p_1;
    ASSERT_EQ(p_1, a)
        << "It's not one";
}
TEST_F(DifferenceFixture, simple_diff3){
    IBusko::LongNumber a = twelve - two;
    ASSERT_EQ(p_10, a)
        << "It's not ten";
}
TEST_F(DifferenceFixture, simple_diff4){
    IBusko::LongNumber a = thirteen - two;
    ASSERT_EQ(p_11, a)
        << "It's not eleven";
}
TEST_F(DifferenceFixture, last_capacity){
    IBusko::LongNumber a = thirteen - nine;
    ASSERT_EQ(p_4, a)
        << "It's not four";
}
TEST_F(DifferenceFixture, negative_plus_positive){
    IBusko::LongNumber a = ninety_nine_pos - ninety_nine_neg;
    ASSERT_EQ(p_198, a)
        << "It's not 198";
}
TEST_F(DifferenceFixture, associated){
    IBusko::LongNumber a = nine - thirteen;
    ASSERT_EQ(n_4, a)
        << "It's not -4";
}
TEST_F(DifferenceFixture, sum_of_nums_with_different_capacity){
    IBusko::LongNumber a = one_hundred_eight - ninety_nine_pos;
    ASSERT_EQ(nine, a)
        << "It's not 9";
}
TEST_F(DifferenceFixture, equal_numbers1){
    IBusko::LongNumber a = one_hundred_eight - one_hundred_eight;
    ASSERT_EQ(zero, a)
        << "It's not 0";
}

class MultiplicationFixture : public testing::Test{
public:
    IBusko::LongNumber zero = IBusko::LongNumber("0");
    IBusko::LongNumber one = IBusko::LongNumber("1");
    IBusko::LongNumber two = IBusko::LongNumber("2");
    IBusko::LongNumber nine = IBusko::LongNumber("9");
    IBusko::LongNumber thirteen = IBusko::LongNumber("13");
    IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
    IBusko::LongNumber twenty_seven = IBusko::LongNumber("27");
    IBusko::LongNumber ninety_nine_pos = IBusko::LongNumber("99");
    IBusko::LongNumber ninety_nine_neg = IBusko::LongNumber("-99");
    IBusko::LongNumber one_hundred_eight = IBusko::LongNumber("108");
    IBusko::LongNumber p_1287 = IBusko::LongNumber("1287");
    IBusko::LongNumber p_18 = IBusko::LongNumber("18");
    IBusko::LongNumber n_26 = IBusko::LongNumber("-26");
};

TEST_F(MultiplicationFixture, simple_multiplication1){
    IBusko::LongNumber a = one * two;
    ASSERT_EQ(two, a)
        << "It's not 2";
}
TEST_F(MultiplicationFixture, simple_multiplication2){
    IBusko::LongNumber a = two * one;
    ASSERT_EQ(two, a)
        << "It's not 2";
}
TEST_F(MultiplicationFixture, multiplicate_with_zero1){
    IBusko::LongNumber a = zero * twenty_seven;
    ASSERT_EQ(zero, a)
        << "It's not 0";
}
TEST_F(MultiplicationFixture, multiplicate_with_zero2){
    IBusko::LongNumber a = twenty_seven * zero;
    ASSERT_EQ(zero, a)
        << "It's not 0";
}
TEST_F(MultiplicationFixture, multiplicate_two_neg_num1){
    IBusko::LongNumber a = thirteen_neg * ninety_nine_neg;
    ASSERT_EQ(p_1287, a)
        << "It's not 1287";
}
TEST_F(MultiplicationFixture, multiplicate_two_neg_num2){
    IBusko::LongNumber a = ninety_nine_neg * thirteen_neg;
    ASSERT_EQ(p_1287, a)
        << "It's not 1287";
}
TEST_F(MultiplicationFixture, simple_multiplication3){
    IBusko::LongNumber a = nine * two;
    ASSERT_EQ(p_18, a)
        << "It's not 18";
}
TEST_F(MultiplicationFixture, multiplicate_two_neg_num3){
    IBusko::LongNumber a = thirteen_neg * two;
    ASSERT_EQ(n_26, a)
        << "It's not -26";
}

class DivisionFixture : public testing::Test{
    public:
        IBusko::LongNumber zero = IBusko::LongNumber("0");
        IBusko::LongNumber one = IBusko::LongNumber("1");
        IBusko::LongNumber one_neg = IBusko::LongNumber("-1");
        IBusko::LongNumber two = IBusko::LongNumber("2");
        IBusko::LongNumber nine = IBusko::LongNumber("9");
        IBusko::LongNumber thirteen1 = IBusko::LongNumber("13");
        IBusko::LongNumber thirteen2 = IBusko::LongNumber("13");
        IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
        IBusko::LongNumber twenty_seven = IBusko::LongNumber("27");
        IBusko::LongNumber ninety_nine_pos = IBusko::LongNumber("99");
        IBusko::LongNumber ninety_nine_neg = IBusko::LongNumber("-99");
        IBusko::LongNumber one_hundred_eight = IBusko::LongNumber("108");
        IBusko::LongNumber p_200 = IBusko::LongNumber("200");
        IBusko::LongNumber p_100 = IBusko::LongNumber("100");
        IBusko::LongNumber p_54 = IBusko::LongNumber("54");

};

TEST_F(DivisionFixture, simple_division1){
    IBusko::LongNumber a = one_hundred_eight / two;
    ASSERT_EQ(p_54, a)
        << "It's not 54";
}
TEST_F(DivisionFixture, simple_division2){
    IBusko::LongNumber a = p_200 / two;
    ASSERT_EQ(p_100, a)
        << "It's not 100";
}
TEST_F(DivisionFixture, division_of_equal_num1){
    IBusko::LongNumber a = thirteen1 / thirteen2;
    ASSERT_EQ(one, a)
        << "It's not 1";
}
TEST_F(DivisionFixture, division_with_diff_sign1){
    IBusko::LongNumber a = thirteen1 / thirteen_neg;
    ASSERT_EQ(one_neg, a)
        << "It's not -1";
}
TEST_F(DivisionFixture, division_by_zero2){
    IBusko::LongNumber a = zero / thirteen_neg;
    ASSERT_EQ(zero, a)
        << "It isn't null";
}

class FArithmetic : public testing::Test {
public:
    IBusko::LongNumber n_19602 = IBusko::LongNumber("-19602");
    IBusko::LongNumber n_99 = IBusko::LongNumber("-99");
    IBusko::LongNumber p_0 = IBusko::LongNumber("0");
    IBusko::LongNumber p_1 = IBusko::LongNumber("1");
    IBusko::LongNumber p_2 = IBusko::LongNumber("2");
    IBusko::LongNumber p_4 = IBusko::LongNumber("4");
    IBusko::LongNumber n_15 = IBusko::LongNumber("-15");
    IBusko::LongNumber p_19602 = IBusko::LongNumber("19602");
    IBusko::LongNumber p_12 = IBusko::LongNumber("12");
    IBusko::LongNumber p_100 = IBusko::LongNumber("100");
    IBusko::LongNumber p_113 = IBusko::LongNumber("113");
    IBusko::LongNumber p_6 = IBusko::LongNumber("6");
    IBusko::LongNumber p_3 = IBusko::LongNumber("3");
    IBusko::LongNumber p_7 = IBusko::LongNumber("7");
};

TEST_F(FArithmetic, remainder) {
    IBusko::LongNumber a = p_3 % p_2;
    ASSERT_EQ(p_1, a) << "3 % 2 = 1";
    IBusko::LongNumber a1 = p_19602 % p_12;
    ASSERT_EQ(p_6, a1) << "19602 % 12 = 6";
    IBusko::LongNumber a2 = n_15 % p_4;
    ASSERT_EQ(p_1, a2) << "-15 % 4 = 1";
    IBusko::LongNumber a3 = p_113 % p_3;
    ASSERT_EQ(p_2, a3) << "113 % -3 = 2";
    IBusko::LongNumber a4 = n_15 % p_7;
    ASSERT_EQ(p_6, a4) << "-15 % -7 = 6";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

