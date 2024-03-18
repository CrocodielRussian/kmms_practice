#pragma once

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>


namespace IBusko {
	class LongNumber {
		static const char END = '\0';
		static const char MINUS = '-';
		static const int NEGATIVE = -1;
		static const int POSITIVE = 1;
        static const int NEUTRAL = 0;

        int* numbers;
        int length;
        int sign;
        int sum;

		public:
			LongNumber();
			LongNumber(const char* const str);
			LongNumber(const LongNumber& x);
			LongNumber(LongNumber&& x);
			
			~LongNumber();
			
			LongNumber& operator = (const char* const str);
			LongNumber& operator = (const LongNumber& x);
			LongNumber& operator = (LongNumber&& x);
			
			bool operator == (const LongNumber& x);
			bool operator > (const LongNumber& x);
			bool operator < (const LongNumber& x);
			
			LongNumber operator + (const LongNumber& x);
			LongNumber operator - (const LongNumber& x);
			LongNumber operator * (const LongNumber& x);
			LongNumber operator / (const LongNumber& x);
			LongNumber operator % (const LongNumber& x);

            void different_of_digit(LongNumber& x, const LongNumber& y);
			int get_digits_number() const;
			int get_sum() const;
            int get_sign() const;
            LongNumber get_subnumber(const LongNumber& divisible, const LongNumber& divider);
            LongNumber left_shift(const LongNumber& x, int size, LongNumber& start);
            LongNumber left_shift(const LongNumber& x, int& start, int& end);
            LongNumber leading_of_zeroes(LongNumber&x);
            void set_subnumber(LongNumber& number, const LongNumber& sub_number, int size_subnumber);
            bool more_compare_by_module(const LongNumber& x);
			bool is_positive() const;
            bool is_null(const LongNumber& x) const;

			friend std::ostream& operator << (std::ostream &os, const LongNumber& x);

        private:
            void addition_of_num(int* numbers, int size, LongNumber& result, const LongNumber& x);
            LongNumber convert_int_to_big_integer(int num);
            void division_of_num(int* numbers, int size, LongNumber& result, const LongNumber& x);
            int get_length(const char* const str) const;
            int sum_of_arr(int* numbers, int size, int sign) const;
            void subtraction_of_num(const LongNumber& x, LongNumber& result, const LongNumber& y);
            void write_number(const char* const str, int* numbers, int size, int index);
	};
}
