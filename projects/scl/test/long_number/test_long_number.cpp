#include <gtest/gtest.h>

#include "long_number.hpp"
#include <iostream>

TEST(get_digits_number, check_positive) {
	IBusko::LongNumber x("12345");
	ASSERT_EQ(5, x.get_digits_number())
		<< "Is not equals length" << x;
}
TEST(get_digits_number, check_negative) {
    IBusko::LongNumber x("-1");
    ASSERT_EQ(1, x.get_digits_number())
        << "Second error " << x;
}
TEST(get_n, check_sum) {
	IBusko::LongNumber x("12345");
	ASSERT_EQ(12345, x.get_sum())
		<< "Trouble with write num" << x;
}
TEST(get_n, check_sum) {
    IBusko::LongNumber x("-12345");
    ASSERT_EQ(12345, x.get_sum())
    << "Trouble with write num" << x;
}

//class EqualityFixture : public testing::Test {
//	public:
//		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
//		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
//		IBusko::LongNumber twelve = IBusko::LongNumber("12");
//		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
//};
//
//TEST_F(EqualityFixture, equal) {
//	ASSERT_TRUE(one_v1 == one_v2) << "Equal numbers is not equal " << one_v1 << " == " << one_v2;
//}
//
//TEST_F(EqualityFixture, not_equal) {
//	ASSERT_FALSE(one_v1 == twelve) << "Not equal numbers is equal " << one_v1 << " == " << twelve;
//}
//
//TEST_F(EqualityFixture, not_equal_negative_var) {
//	ASSERT_FALSE(one_v1 == negative_one)
//		<< "Negative five equal to positive " << one_v1 << " == " << negative_one;
//}
//
//class SumFixture : public testing::Test {
//    public:
//        IBusko::LongNumber one = IBusko::LongNumber("1");
//        IBusko::LongNumber two = IBusko::LongNumber("2");
//        IBusko::LongNumber nine = IBusko::LongNumber("9");
//        IBusko::LongNumber thirteen = IBusko::LongNumber("13");
//        IBusko::LongNumber ninety_nine_pos = IBusko::LongNumber("99");
//        IBusko::LongNumber ninety_nine_neg = IBusko::LongNumber("-99");
//};
//TEST(Operator, operator_equal){
//
//};

//TEST_F(SumFixture, simple_sum){
//    IBusko::LongNumber a = one + two;
//    ASSERT_EQ(3, a.get_sum())
//        << "It's not three" << a.get_sum();
//}
//TEST_F(SumFixture, next_capacity){
//    IBusko::LongNumber a = two + nine;
//    ASSERT_EQ(11, a.get_sum())
//        << "It's not eleven" << a.get_sum();
//}
//TEST_F(SumFixture, negative_plus_positive){
//    IBusko::LongNumber a = ninety_nine_pos + ninety_nine_neg;
//    ASSERT_EQ(0, a.get_sum());
//        << "It's not 0" << a.get_sum();
//}
//TEST_F(SumFixture, associated){
//    IBusko::LongNumber a = thirteen + nine;
//    ASSERT_EQ(22, a.get_sum());
//        << "It's not 22" << a.get_sum();
//}


int main(int argc, char **argv) {
//	IBusko::LongNumber x("-123");
//    IBusko::LongNumber y("321");
//
//    std::cout << x.get_sign() << "\n";
//    std::cout << x.get_sum() << "\n";
//
//    std::cout << y.get_sign() << "\n";
//    std::cout << y.get_sum() << "\n";

//    x = y;
//
//    std::cout << x.get_sign() << "\n";
//    std::cout << x.get_sum() << "\n";

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
