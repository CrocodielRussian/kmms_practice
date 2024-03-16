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
    ASSERT_EQ(-12345, x.get_sum())
    << "Trouble with write negative num " << x.get_sum();
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
    IBusko::LongNumber fifteen_neg = IBusko::LongNumber("-15");
    IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
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
TEST_F(MoreFixture, more_neg_logical1){
    ASSERT_FALSE(fifteen_neg > thirteen_neg)
        << "Incorrect negative logical " << fifteen_neg.get_sum() << " > " << thirteen_neg.get_sum();
}
TEST_F(MoreFixture, more_neg_logical2){
    ASSERT_TRUE(thirteen_neg > fifteen_neg)
        << "Incorrect negative logical " << fifteen_neg.get_sum() << " > " << thirteen_neg.get_sum();
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
TEST_F(LessFixture, less_neg_logical1){
    ASSERT_TRUE(fifteen_neg < thirteen_neg)
    << "Incorrect negative logical " << thirteen_neg.get_sum() << " < " << fifteen_neg.get_sum();
}
TEST_F(LessFixture, less_neg_logical2){
    ASSERT_FALSE(thirteen_neg < fifteen_neg)
        << "Incorrect negative logical " << thirteen_neg.get_sum() << " < " << fifteen_neg.get_sum();
}
class SumFixture : public testing::Test {
    public:
        IBusko::LongNumber one = IBusko::LongNumber("1");
        IBusko::LongNumber two = IBusko::LongNumber("2");
        IBusko::LongNumber nine = IBusko::LongNumber("9");
        IBusko::LongNumber thirteen = IBusko::LongNumber("13");
        IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
        IBusko::LongNumber twenty_seven = IBusko::LongNumber("27");
        IBusko::LongNumber ninety_nine_pos = IBusko::LongNumber("99");
        IBusko::LongNumber ninety_nine_neg = IBusko::LongNumber("-99");
        IBusko::LongNumber one_hundred_eight = IBusko::LongNumber("108");
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
TEST_F(SumFixture, associated1){
    IBusko::LongNumber a = thirteen + nine;
    ASSERT_EQ(22, a.get_sum())
        << "It's not 22";
}
TEST_F(SumFixture, sum_of_nums_with_different_capacity){
    IBusko::LongNumber a = ninety_nine_neg + one_hundred_eight;
    ASSERT_EQ(9, a.get_sum())
        << "It's not 9";
}
TEST_F(SumFixture, sum_with_bugs){
    IBusko::LongNumber a = twenty_seven + thirteen_neg;
    ASSERT_EQ(14, a.get_sum())
        << "It's not 14";
}
TEST_F(SumFixture, associated2){
    IBusko::LongNumber a = thirteen_neg + twenty_seven;
    ASSERT_EQ(14, a.get_sum())
        << "It's not 14";
}

class DifferenceFixture : public testing::Test{
    public:
        IBusko::LongNumber one = IBusko::LongNumber("1");
        IBusko::LongNumber two = IBusko::LongNumber("2");
        IBusko::LongNumber three = IBusko::LongNumber("3");
        IBusko::LongNumber nine = IBusko::LongNumber("9");
        IBusko::LongNumber twelve = IBusko::LongNumber("12");
        IBusko::LongNumber thirteen = IBusko::LongNumber("13");
        IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
        IBusko::LongNumber twenty_seven = IBusko::LongNumber("27");
        IBusko::LongNumber ninety_nine_pos = IBusko::LongNumber("99");
        IBusko::LongNumber ninety_nine_neg = IBusko::LongNumber("-99");
        IBusko::LongNumber one_hundred_eight = IBusko::LongNumber("108");
};

TEST_F(DifferenceFixture, simple_diff1){
    IBusko::LongNumber a = one - two;
    ASSERT_EQ(-1, a.get_sum())
        << "It's not minus one";
}
TEST_F(DifferenceFixture, simple_diff2){
    IBusko::LongNumber a = two - one;
    ASSERT_EQ(1, a.get_sum())
        << "It's not one";
}
TEST_F(DifferenceFixture, simple_diff3){
    IBusko::LongNumber a = twelve - two;
    ASSERT_EQ(10, a.get_sum())
        << "It's not ten";
}
TEST_F(DifferenceFixture, simple_diff4){
    IBusko::LongNumber a = thirteen - two;
    ASSERT_EQ(11, a.get_sum())
        << "It's not eleven";
}
TEST_F(DifferenceFixture, last_capacity){
    IBusko::LongNumber a = thirteen - nine;
    ASSERT_EQ(4, a.get_sum())
        << "It's not four";
}
TEST_F(DifferenceFixture, negative_plus_positive){
    IBusko::LongNumber a = ninety_nine_pos - ninety_nine_neg;
    ASSERT_EQ(198, a.get_sum())
        << "It's not 198";
}
TEST_F(DifferenceFixture, associated){
    IBusko::LongNumber a = nine - thirteen;
    ASSERT_EQ(-4, a.get_sum())
        << "It's not -4";
}
TEST_F(DifferenceFixture, sum_of_nums_with_different_capacity){
    IBusko::LongNumber a = one_hundred_eight - ninety_nine_pos;
    ASSERT_EQ(9, a.get_sum())
        << "It's not 9";
}
TEST_F(DifferenceFixture, equal_numbers1){
    IBusko::LongNumber a = one_hundred_eight - one_hundred_eight;
    ASSERT_EQ(0, a.get_sum())
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
};

TEST_F(MultiplicationFixture, simple_multiplication1){
    IBusko::LongNumber a = one * two;
    ASSERT_EQ(2, a.get_sum())
        << "It's not 2";
}
TEST_F(MultiplicationFixture, simple_multiplication2){
    IBusko::LongNumber a = two * one;
    ASSERT_EQ(2, a.get_sum())
        << "It's not 2";
}
TEST_F(MultiplicationFixture, multiplicate_with_zero1){
    IBusko::LongNumber a = zero * twenty_seven;
    ASSERT_EQ(0, a.get_sum())
        << "It's not 0";
}
TEST_F(MultiplicationFixture, multiplicate_with_zero2){
    IBusko::LongNumber a = twenty_seven * zero;
    ASSERT_EQ(0, a.get_sum())
        << "It's not 0";
}
TEST_F(MultiplicationFixture, multiplicate_two_neg_num1){
    IBusko::LongNumber a = thirteen_neg * ninety_nine_neg;
    ASSERT_EQ(1287, a.get_sum())
        << "It's not 1287";
}
TEST_F(MultiplicationFixture, multiplicate_two_neg_num2){
    IBusko::LongNumber a = ninety_nine_neg * thirteen_neg;
    ASSERT_EQ(1287, a.get_sum())
        << "It's not 1287";
}
TEST_F(MultiplicationFixture, simple_multiplication3){
    IBusko::LongNumber a = nine * two;
    ASSERT_EQ(18, a.get_sum())
        << "It's not 18";
}
TEST_F(MultiplicationFixture, multiplicate_two_neg_num3){
    IBusko::LongNumber a = thirteen_neg * two;
    ASSERT_EQ(-26, a.get_sum())
        << "It's not -26";
}

class DivisionFixture : public testing::Test{
    public:
        IBusko::LongNumber zero = IBusko::LongNumber("0");
        IBusko::LongNumber one = IBusko::LongNumber("1");
        IBusko::LongNumber two = IBusko::LongNumber("2");
        IBusko::LongNumber nine = IBusko::LongNumber("9");
        IBusko::LongNumber thirteen1 = IBusko::LongNumber("13");
        IBusko::LongNumber thirteen2 = IBusko::LongNumber("13");
        IBusko::LongNumber thirteen_neg = IBusko::LongNumber("-13");
        IBusko::LongNumber twenty_seven = IBusko::LongNumber("27");
        IBusko::LongNumber ninety_nine_pos = IBusko::LongNumber("99");
        IBusko::LongNumber ninety_nine_neg = IBusko::LongNumber("-99");
        IBusko::LongNumber one_hundred_eight = IBusko::LongNumber("108");

};

TEST_F(DivisionFixture, simple_division1){
    IBusko::LongNumber a = one_hundred_eight / two;
    ASSERT_EQ(54, a.get_sum())
        << "It's not 54";
}
TEST_F(DivisionFixture, division_of_equal_num1){
    IBusko::LongNumber a = thirteen1 / thirteen2;
    ASSERT_EQ(1, a.get_sum())
        << "It's not 1";
}
TEST_F(DivisionFixture, division_with_diff_sign1){
    IBusko::LongNumber a = thirteen1 / thirteen_neg;
    ASSERT_EQ(-1, a.get_sum())
        << "It's not -1";
}
TEST_F(DivisionFixture, division_with_diff_sign2){
    IBusko::LongNumber a = thirteen_neg / thirteen1;
    ASSERT_EQ(-1, a.get_sum())
        << "It's not -1";
}
TEST_F(DivisionFixture, division_by_zero1){
    IBusko::LongNumber a = thirteen_neg / zero;
    ASSERT_EQ(0, a.get_sum())
        << "It's impossible";
}
TEST_F(DivisionFixture, division_by_zero2){
    IBusko::LongNumber a = zero / thirteen_neg;
    ASSERT_EQ(0, a.get_sum())
        << "It isn't null";
}

int main(int argc, char **argv) {
//    IBusko::LongNumber a1 = IBusko::LongNumber("100");
    IBusko::LongNumber b1 = IBusko::LongNumber("12");
    IBusko::LongNumber b2 = IBusko::LongNumber("2");
    IBusko::LongNumber a = IBusko::LongNumber("144");
    IBusko::LongNumber b = IBusko::LongNumber("12");
//    IBusko::LongNumber d = IBusko::LongNumber("-1");
//    IBusko::LongNumber one = IBusko::LongNumber("1");
    IBusko::LongNumber e = IBusko::LongNumber("777");
//    IBusko::LongNumber zero = IBusko::LongNumber("0");

    IBusko::LongNumber c = a / b;

    std::cout << c << "\n";
    std::cout << c.get_sum() << "\n";
    std::cout << c.get_sign() << "\n";

//    std::cout << b1 - b2 << "\n";
//    std::cout << (b1 - e) << "\n";

//    std::cout << a1 - b1 << "\n";
//    std::cout << c << "\n";
//    std::cout << d * e << "\n";
//    std::cout << c.get_sign() << "\n";
//    std::cout << c.get_sum() << "\n";

//    ::testing::InitGoogleTest(&argc, argv);
//	return RUN_ALL_TESTS();

}
