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
			
			int get_digits_number() const;
			int get_sum() const;
            int get_sign() const;
			bool is_positive() const;
			
			friend std::ostream& operator << (std::ostream &os, const LongNumber& x);

        private:
            int get_length(const char* const str) const;
            int sum_of_arr(int* numbers, int size, int sign) const;
            void addition_of_num(int* numbers, int size, LongNumber& result, const LongNumber& x);
            void subtraction_of_num(int* numbers, int size, LongNumber& result, const LongNumber& x);
            void write_number(const char* const str, int* numbers, int size, int index);
	};
}
