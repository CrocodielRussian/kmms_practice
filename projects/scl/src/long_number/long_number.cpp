#include "long_number.hpp"

namespace IBusko {
    LongNumber::LongNumber(){
        this->length = 1;
        this->sign = NEUTRAL;
        this->sum = 0;
        this->numbers = new int[length];
    }
    LongNumber::LongNumber(const char* const str) {
        int index = 0;
        this->length = get_length(str);
        if(str[0] == MINUS){
            this->sign = NEGATIVE;
            this->length--;
            index++;
        }else if(str[0] == '0'){
            this->sign = NEUTRAL;
        }else{
            this->sign = POSITIVE;
        }

        this->numbers = new int[length];

        for(int i = 0; i < length; i++){
            numbers[i] = 0;
        }
        write_number(str, numbers, length, index);

        this->sum = sum_of_arr(numbers, length, sign);
    }

    LongNumber::LongNumber(const LongNumber& x) {
        this->length = x.get_digits_number();
        this->sign = x.get_sign();
        this->sum = x.get_sum();
        this->numbers = new int[length];

        if(x.numbers != nullptr){
            for(int i = 0; i < length; i++){
                this->numbers[i] = x.numbers[i];
            }
        }
    }

    LongNumber::LongNumber(LongNumber&& x) {
        this->length = x.get_digits_number();
        this->sign = x.get_sign();
        this->sum = x.get_sum();

        this->numbers = new int[length];

        for(int i = 0; i < length; i++){
            numbers[i] = x.numbers[i];
        }
        x.numbers = nullptr;
        x.length = 0;
        x.sum = 0;
        x.sign = 0;

    }
    LongNumber::LongNumber(int len) {
        this->length = len;
        this->sign = NEUTRAL;
        this->sum = 0;
        this->numbers = new int[length];

        for(int i = 0; i < length; i++){
            this->numbers[i] = 0;
        }

    }

    LongNumber::~LongNumber() {
        delete[] numbers;
        numbers = nullptr;
    }

    LongNumber& LongNumber::operator = (const char* const str) {
        int index = 0;
        this->length = get_length(str);
        if(str[0] == MINUS){
            this->sign = NEGATIVE;
            this->length--;
            index++;
        }else{
            this->sign = POSITIVE;
        }

        if(!is_positive()){
            this->length = get_length(str) - 1;
        }else{
            this->length = get_length(str);
        }

        if(this->numbers != nullptr){
            delete[] this->numbers;
        }

        this->numbers = new int[length];

        write_number(str, numbers, length, index);

        this->sum = sum_of_arr(numbers, length, sign);

        return *this;
    }

    LongNumber& LongNumber::operator = (const LongNumber& x) {
        if(this == &x) return *this;
        this->length = x.get_digits_number();
        this->sign = x.get_sign();
        this->sum = x.get_sum();

        if(this->numbers != nullptr){
            delete[] this->numbers;
        }
        this->numbers = new int[this->get_digits_number()];

        for(int i = 0; i < length; i++){
            numbers[i] = x.numbers[i];
        }
        return *this;
    }

    LongNumber& LongNumber::operator = (LongNumber &&x){
        if(this == &x) return *this;
        this->length = x.get_digits_number();
        this->sign = x.get_sign();
        this->sum = x.get_sum();

        if(this->numbers != nullptr) {
            delete[] this->numbers;
        }

        this->numbers = x.numbers;

        x.numbers = nullptr;
        x.length = 0;
        x.sum = 0;
        x.sign = 0;

        return *this;
    }

    bool LongNumber::operator == (const LongNumber& x) const{
        if(this->get_sign() == NEUTRAL && x.get_sign() == NEUTRAL && this->numbers[0] == 0 && x.numbers[0] == 0){
            return true;
        }
        if(this->get_sign() != x.get_sign()){
            return false;
        }
        if(this->get_digits_number() != x.get_digits_number()){
            return false;
        }

        for(int i = length-1; i >= 0; i--){
            if(this->numbers[i] > x.numbers[i] || this->numbers[i] < x.numbers[i]){
                return false;
            }
        }

        return true;
    }

    bool LongNumber::operator > (const LongNumber& x) const{
        if(this->get_sign() == NEUTRAL && x.get_sign() == NEUTRAL && this->numbers[0] == 0 && x.numbers[0] == 0){
            return false;
        }
        if(this->get_sign() > x.get_sign()){
            return true;
        }else if(this->get_sign() < x.get_sign()){
            return false;
        }else{
            if(this->get_digits_number() > x.get_digits_number()){
                if(this->get_sign() == 1)
                    return true;
                else
                    return false;
            }else if(this->get_digits_number() < x.get_digits_number()){
                if(this->get_sign() == 1)
                    return false;
                else
                    return true;
            }else{
                for(int i = length-1; i >= 0; i--){
                    if(this->numbers[i] > x.numbers[i]){
                        if(this->get_sign() == 1)
                            return true;
                        else
                            return false;
                    }else if(this->numbers[i] < x.numbers[i]){
                        if(this->get_sign() == 1)
                            return false;
                        else
                            return true;
                    }
                }
            }
        }
        return false;
    }

    bool LongNumber::operator < (const LongNumber& x) const{
        if(this->get_sign() == NEUTRAL && x.get_sign() == NEUTRAL && this->numbers[0] == 0 && x.numbers[0] == 0){
            return false;
        }
        if(this->get_sign() < x.get_sign()){
            return true;
        }else if(this->get_sign() > x.get_sign()){
            return false;
        }else{
            if(this->get_digits_number() < x.get_digits_number()){
                if(this->get_sign() == 1)
                    return true;
                else
                    return false;
            }else if(this->get_digits_number() > x.get_digits_number()){
                if(this->get_sign() == 1)
                    return false;
                else
                    return true;
            }else{
                for(int i = length-1; i >= 0; i--){
                    if(this->numbers[i] < x.numbers[i]){
                        if(this->get_sign() == 1){
                            return true;
                        }else{
                            return false;
                        }
                    }else if(this->numbers[i] > x.numbers[i]){
                        if(this->get_sign() == 1){
                            return false;
                        }else{
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool LongNumber::operator <= (const IBusko::LongNumber &x) const{
        return (*this == x || *this < x);
    }
    bool LongNumber::operator >= (const IBusko::LongNumber &x) const{
        return (*this == x || *this > x);
    }
    bool LongNumber::operator != (const IBusko::LongNumber &x) const{
        return !(*this == x);
    }

    LongNumber LongNumber::operator + (const LongNumber& x){
        int size = std::max(x.get_digits_number(), this->get_digits_number()) + 1;

        LongNumber result(size);

        for(int i = 0; i < result.get_digits_number(); i++){
            result.numbers[i] = 0;
        }
        if(this->get_sign() == x.get_sign()){
            addition_of_num(this->numbers, size, result, x);
            if(is_null(result)){
                result.sign = NEUTRAL;
            }else{
                result.sign = x.get_sign();
            }
        }else{
            if(equal_by_module(x, '<')){
                subtraction_of_num(x, result, *this);
            }else{
                subtraction_of_num(*this, result, x);
            }

            if(is_null(result)){
                result.sign = NEUTRAL;
            }else if(equal_by_module(x, '>')){
                result.sign = this->get_sign();
            }else{
                result.sign = x.get_sign();
            }

        }
        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());
        result.length = leading_of_zeroes(result.numbers, result.get_digits_number());

        return result;
    }

    LongNumber LongNumber::operator - (const LongNumber& x) {
        int size = std::max(x.get_digits_number(), this->get_digits_number()) + 1;

        LongNumber result(size);

        for(int i = 0; i < result.length; i++){
            result.numbers[i] = 0;
        }

        if(this->get_sign() == POSITIVE && x.get_sign() == NEGATIVE || this->get_sign() == NEGATIVE && x.get_sign() == POSITIVE){
            addition_of_num(numbers, size, result, x);
            if(is_null(result)){
                result.sign = NEUTRAL;
            }else{
                result.sign = this->get_sign();
            }
        }else{
            if(equal_by_module(x, '<')){
                subtraction_of_num(x, result, *this);
            }else{
                subtraction_of_num(*this, result, x);
            }
            if(is_null(result)){
                result.sign = NEUTRAL;
            }else if(*this > x){
                result.sign = this->get_sign();
            }else{
                result.sign = NEGATIVE * x.get_sign();
            }
        }

        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());
        result.length = leading_of_zeroes(result.numbers, result.get_digits_number());

        return result;
    }

    LongNumber LongNumber::operator * (const LongNumber& x) {
        LongNumber zero("0");

        int size = x.get_digits_number() + this->get_digits_number() + 1;

        LongNumber result(size);

        for(int i = 0; i < result.length; i++){
            result.numbers[i] = 0;
        }
        int mx, mn;

        mx = std::max(this->get_digits_number(), x.get_digits_number());
        mn = std::min(this->get_digits_number(), x.get_digits_number());

        int mul = 1, idx = 0;
        for(int i = 0; i < mn; i++){
            for(int j = 0; j < mx; j++){
                mul = 1;
                if(this->get_digits_number() == mn)
                    mul = this->numbers[i] * x.numbers[j];
                if(this->get_digits_number() == mx)
                    mul = this->numbers[j] * x.numbers[i];

                result.numbers[j + idx] += mul;
                result.numbers[j + 1 + idx] += result.numbers[j + idx] / 10;
                result.numbers[j + idx] %= 10;
            }
            idx++;
        }
        if(is_null(result)){
            result.sign = NEUTRAL;
        }else if(this->get_sign() == x.get_sign()){
            result.sign = POSITIVE;
        }else{
            result.sign = NEGATIVE;
        }
        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());
        result.length = leading_of_zeroes(result.numbers, result.get_digits_number());

        return result;
    }


    LongNumber LongNumber::operator / (const LongNumber& x) {
        LongNumber zero("0");
        LongNumber neg("-1");
        LongNumber divider, temp2, divisible, different;

        int size = std::max(this->get_digits_number(), x.get_digits_number()) + 2;

        int *arr_of_ans = new int[size];

        for(int i = 0; i < size; i++){
            arr_of_ans[i] = -1;
        }

        LongNumber result(size);
        if(equal_by_module(x, '<')){
            return zero;
        }
        int l = 0 , r = 10, ans = 0, mid = 0;
        divider = x;
        divisible = *this;
        if(*this < zero){
            divisible = divisible * neg;
        }
        if(divider < zero){
            divider = divider * neg;
        }
        int j = 0;
        int len = divisible.get_digits_number();
        while(true){
            LongNumber temp = right_shift(divider, len);
            l = 0, r = 10, ans = 0;
            while(l <= r) {
                mid = (l + r) / 2;
                LongNumber k = convert_int_to_big_integer(mid);
                LongNumber t = temp * k;
                if (t <= divisible) {
                    ans = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            LongNumber k = convert_int_to_big_integer(ans);
            temp = temp * k;

            divisible = divisible - temp;

            arr_of_ans[j] = ans;
            if(divisible < divider || len < 1){
                for(int i = 0;;i++){
                    j++;
                    if(temp.numbers[i] != 0){
                        break;
                    }
                    arr_of_ans[j] = 0;
                }
                break;
            }
            j++;
            len--;
        }
        int len_arr_of_ans = 0;
        for(int i = 0; i < size; i++){
            if(arr_of_ans[i] != -1){
                len_arr_of_ans++;
            }
        }
        int n = 0;
        if(arr_of_ans[0] == 0){
            n++;
        }
        for(int i = 0; i < size - n; i++){
            if(len_arr_of_ans - i - n - 1 < 0){
                break;
            }
            result.numbers[len_arr_of_ans - i - n - 1] = arr_of_ans[i + n];
        }
        delete[] arr_of_ans;

        if(x.get_sign() == this->get_sign())
            result.sign = POSITIVE;
        else
            result.sign = NEGATIVE;

        result.length = leading_of_zeroes(result.numbers, result.get_digits_number());
        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());

        return result;
    }

    LongNumber LongNumber::operator % (const LongNumber& x) {
        LongNumber zero("0");
        LongNumber neg("-1");
        LongNumber one("1");
        LongNumber divisible = *this;
        LongNumber divider = x;

        if(divider < zero){
            divider = divider * neg;
        }
        LongNumber quotient, remainder;
        if(divisible < zero){
            divisible = divisible * neg;
            quotient = divisible / divider + one;
            remainder = quotient * divider - divisible;
        }else{
            quotient = divisible / divider;
            remainder = divisible - quotient * divider;
        }

        return remainder;
    }

    int LongNumber::get_digits_number() const {
        return length;
    }
    int LongNumber::get_sum() const {
        return sum;
    }
    int LongNumber::get_sign() const {
        return sign;
    }

    bool LongNumber::equal_by_module(const IBusko::LongNumber &x, char syb) {
        LongNumber zero("0");
        LongNumber neg("-1");
        LongNumber left = *this;
        LongNumber right = x;

        if(left < zero){
            left = left * neg;
        }
        if(right < zero){
            right = right * neg;
        }
        if(syb == '=')
            return (left == right);
        else if(syb == '<')
            return (left < right);
        else
            return (left > right);
    }

    bool LongNumber::is_positive() const {
        return sign == POSITIVE;
    }
    bool LongNumber::is_null(const LongNumber &x) const {
        for(int i = 0; i < x.get_digits_number(); i++){
            if(x.numbers[i] != 0)
                return false;
        }
        return true;
    }
    // ----------------------------------------------------------
    // PRIVATE
    // ----------------------------------------------------------
    void LongNumber::addition_of_num(int* numbers, int size, LongNumber& result, const LongNumber& x) {
        short sum;
        for(int i = 0; i < size - 1; i++){
            sum = 0;
            if(x.length > i)
                sum += x.numbers[i];
            if(length > i)
                sum += numbers[i];
            result.numbers[i] += sum % 10;
            if(sum > 9)
                result.numbers[i+1]++;
        }
    }

    LongNumber LongNumber::convert_int_to_big_integer(int num) {
        LongNumber result;

        result.length = 1;
        result.sign = POSITIVE;
        result.sum = num;
        result.numbers[0] = num;

        return result;
    }
    LongNumber LongNumber::right_shift(const LongNumber& x, int len){
        LongNumber result(len);
        result.sign = POSITIVE;

        for(int i = x.get_digits_number() - 1; i >= 0; i--){
            result.numbers[len - x.get_digits_number() + i] = x.numbers[i];
        }
        return result;
    }
    int LongNumber::get_length(const char* const str) const {
        int size = 0;
        while (str[size] != END) {
            size++;
        }
        return size;
    }
    void LongNumber::subtraction_of_num(const LongNumber& x, LongNumber& result, const LongNumber& y) {
        short diff, index_1, index_2;
        LongNumber zero("0");
        LongNumber neg("-1");
        LongNumber left = x;
        LongNumber right = y;

        if(left < zero){
            left = left * neg;
        }
        if(right < zero){
            right = right * neg;
        }
        for(int i = 0; i < x.get_digits_number(); i++) {
            diff = 0;

            if (left.get_digits_number() > i) {
                result.numbers[i] += left.numbers[i];
            }
            if (right.get_digits_number() > i) {
                result.numbers[i] -= right.numbers[i];
            }
            if (result.numbers[i] < 0) {
                result.numbers[i] = 10 - abs(result.numbers[i]);
                result.numbers[i + 1]--;
            }
        }
    }

    int LongNumber::sum_of_arr(int* numbers, int size, int sign) const {
        int s = 0;
        if(sign == NEUTRAL)
            return 0;
        for(int i = 0; i < size; i++){
            s += pow(10, i) * numbers[i];
        }
        s *= sign;
        return s;
    }
    int LongNumber::leading_of_zeroes(const int* const num, int size = 0){
        int length = size;
        int i = size - 1;

        while(num[i] == 0){
            length--;
            i--;
        }
        if(length == 0){
            return 1;
        }
        return length;
    }
    void LongNumber::write_number(const char *const str, int *numbers, int size, int index) {
        if(is_positive()){
            for(int i = index; i < length+index; i++){
                numbers[length - 1 - i] = str[i] - 48;
            }
        }else{
            for(int i = index; i < length+index; i++){
                numbers[length - i] = str[i] - 48;
            }
        }
    }
    // ----------------------------------------------------------
    // FRIENDLY
    // ----------------------------------------------------------
    std::ostream& operator << (std::ostream &os, const LongNumber& x) {
        if(x.get_sign() == LongNumber::NEGATIVE){
            os << "-";
        }

        for(int i = x.get_digits_number() - 1; i >= 0; i--){
            os << x.numbers[i];
        }

        return os;
    }
}