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
        LongNumber(int len);

        ~LongNumber();

        LongNumber& operator = (const char* const str);
        LongNumber& operator = (const LongNumber& x);
        LongNumber& operator = (LongNumber&& x);

        bool operator == (const LongNumber& x) const;
        bool operator != (const LongNumber& x) const;
        bool operator > (const LongNumber& x) const;
        bool operator >= (const LongNumber& x) const;
        bool operator < (const LongNumber& x) const;
        bool operator <= (const LongNumber& x) const;

        LongNumber operator + (const LongNumber& x);
        LongNumber operator - (const LongNumber& x);
        LongNumber operator * (const LongNumber& x);
        LongNumber operator / (const LongNumber& x);
        LongNumber operator % (const LongNumber& x);

        int get_digits_number() const;
        int get_sign() const;
        bool is_positive() const;

        friend std::ostream& operator << (std::ostream &os, const LongNumber& x);
    private:
        bool is_null(const LongNumber& x) const;
        bool more_compare_by_module(const LongNumber& x);
        bool equal_by_module(const LongNumber& x, char syb);
        int leading_of_zeroes(const int* const num, int size);
        LongNumber right_shift(const LongNumber& x, int len);
        void addition_of_num(int* numbers, int size, LongNumber& result, const LongNumber& x);
        LongNumber convert_int_to_big_integer(int num);
        int get_length(const char* const str) const;
        void subtraction_of_num(const LongNumber& x, LongNumber& result, const LongNumber& y);
        void write_number(const char* const str, int* numbers, int size, int index);
    };
}