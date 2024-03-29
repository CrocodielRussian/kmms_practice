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

	LongNumber& LongNumber::operator=(LongNumber &&x){
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

	bool LongNumber::operator == (const LongNumber& x) {
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

	bool LongNumber::operator > (const LongNumber& x) {
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

	bool LongNumber::operator < (const LongNumber& x) {
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

	LongNumber LongNumber::operator + (const LongNumber& x) {
        LongNumber result;

        int size = std::max(x.get_digits_number(), this->get_digits_number()) + 1;

        result.length = size;
        result.numbers = new int[size];

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
            if(!more_compare_by_module(x)){
                subtraction_of_num(x, result, *this);
            }else{
                subtraction_of_num(*this, result, x);
            }

            if(is_null(result)){
                result.sign = NEUTRAL;
            }else if(this->more_compare_by_module(x)){
                result.sign = this->get_sign();
            }else{
                result.sign = x.get_sign();
            }

        }
        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());

        result = leading_of_zeroes(result);

        return result;
	}

	LongNumber LongNumber::operator - (const LongNumber& x) {
        LongNumber result;

        int size = std::max(x.get_digits_number(), this->get_digits_number()) + 1;

        result.length = size;
        result.numbers = new int[size];

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
            if(!more_compare_by_module(x)){
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

        result = leading_of_zeroes(result);

        return result;
	}

	LongNumber LongNumber::operator * (const LongNumber& x) {
        LongNumber result;
        LongNumber zero("0");

        int size = x.get_digits_number() + this->get_digits_number() + 1;

        result.length = size;
        result.numbers = new int[size];

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
        result = leading_of_zeroes(result);

		return result;
	}


	LongNumber LongNumber::operator / (const LongNumber& x) {
        LongNumber result;
        LongNumber zero("0");
        LongNumber divider, temp2, divisible;

        int mx = std::max(this->get_digits_number(), x.get_digits_number());
        int mn = std::min(this->get_digits_number(), x.get_digits_number());

        int *arr_of_ans = new int[mx];

        for(int i = 0; i < mx; i++){
            arr_of_ans[i] = -1;
        }

        result.length = mx;
        for(int i = 0; i < mx; i++){
            result.numbers[i] = 0;
        }

        if(!more_compare_by_module(x)){
            return zero;
        }
        int l = 0 , r = 10, ans = 0, mid = 1;
        divider = x;
        divisible = *this;

        int count = 0;
        for(int j = mx - 1; j >= mn - 1; j--) {
            temp2 = get_subnumber(divisible, divider);
            l = 0, r = 10, mid = 0, ans = 0;
            while(l <= r) {
                mid = (l + r) / 2;
                LongNumber k = convert_int_to_big_integer(mid);
                LongNumber t = divider * k;

                if ((t < temp2) || (t == temp2)) {
                    ans = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            LongNumber k = convert_int_to_big_integer(ans);
            LongNumber temp = divider * k;

            LongNumber different = temp2 - temp;

            arr_of_ans[j] = ans;

            set_subnumber(divisible, different, temp2.get_digits_number());
        }
        int len_arr_of_ans = mx;

        for(int i = 0; i < mx; i++){
            if(arr_of_ans[i] != -1){
                len_arr_of_ans--;
            }
        }

        for(int i = mx - 1; i >= len_arr_of_ans; i--){
            result.numbers[i - len_arr_of_ans] = arr_of_ans[i];
        }

        delete[] arr_of_ans;

        if(x.get_sign() == this->get_sign())
            result.sign = POSITIVE;
        else
            result.sign = NEGATIVE;

        return result;
	}

	LongNumber LongNumber::operator % (const LongNumber& x) {
        LongNumber result;
        LongNumber zero("0");
        LongNumber divider, temp2, divisible, different;

        int mx = std::max(this->get_digits_number(), x.get_digits_number());
        int mn = std::min(this->get_digits_number(), x.get_digits_number());

        if(!more_compare_by_module(x)){
            return *this;
        }
        int l = 0 , r = 10, ans = 0, mid = 1;
        divider = x;
        divisible = *this;
        int count = 0;

        for(int j = mx - 1; j >= mn - 1; j--) {
            temp2 = get_subnumber(divisible, divider);

            l = 0, r = 10, mid = 0, ans = 0;
            while(l <= r) {
                mid = (l + r) / 2;
                LongNumber k = convert_int_to_big_integer(mid);
                LongNumber t = divider * k;

                if ((t < temp2) || (t == temp2)) {
                    ans = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            LongNumber k = convert_int_to_big_integer(ans);
            LongNumber temp = divider * k;

            different = temp2 - temp;

            set_subnumber(divisible, different, temp2.get_digits_number());
        }
        result = different;

        return result;
	}

    void LongNumber::different_of_digit(LongNumber &x, const LongNumber &y) {
        int size_x = x.get_digits_number();
        int size_y= y.get_digits_number();
        for(int i = size_x - 1; i >= size_y; i--){
            x.numbers[i] -= y.numbers[i - size_y];
        }
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
    bool LongNumber::more_compare_by_module(const LongNumber& x) {
        if(this->get_digits_number() > x.get_digits_number()){
            return true;
        }else if(this->get_digits_number() < x.get_digits_number()){
            return false;
        }else{
            for(int i = length-1; i >= 0; i--){
                if(this->numbers[i] > x.numbers[i]) {
                    return true;
                }else if(this->numbers[i] < x.numbers[i]){
                    return false;
                }
            }
        }
        return false;
    }
    LongNumber LongNumber::left_shift(const LongNumber &x, int& start, int& end) {
        LongNumber result;
        result.length = start - end + 1;
        result.sign = POSITIVE;
        int s = start, e = end;

        for(int i = 0; i < result.length; i++){
            result.numbers[i] = 0;
        }
        for(int i = s; i >= e; i--){
            result.numbers[i - e] = x.numbers[i];
        }
        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());

        result = leading_of_zeroes(result);

        return result;
    }
    LongNumber LongNumber::get_subnumber(const LongNumber &divisible, const LongNumber &divider) {
        LongNumber result, temp("0");
        int i1 = divisible.get_digits_number() - 1, i2 = divisible.get_digits_number() - 1;
        while(temp < divider){
            if(i2 < 0){
                break;
            }
            temp = left_shift(divisible, i1, i2);
            i2--;
        }
        result = temp;

        return result;
    }
    void LongNumber::set_subnumber(LongNumber &number, const LongNumber &sub_number, int size_subnumber) {
        int size = number.get_digits_number() - 1;
        int inx_snum = sub_number.get_digits_number() - 1;
        int count = 0;

        for(int i = size; i >= size_subnumber - size; i--){
            std::cout << number.numbers[i];
            if(sub_number.get_digits_number() + count < size_subnumber){
                count++;
                number.numbers[i] = 0;
            }else{
                number.numbers[i] = sub_number.numbers[inx_snum];
                inx_snum--;
            }
        }
        number = leading_of_zeroes(number);
    }
	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}
    bool LongNumber::is_null(const LongNumber &x) const {
        if(x.get_digits_number() == 1)
            return x.numbers[0] == 0;
        if(x.get_digits_number() == 2)
            return (x.numbers[0] == 0 && x.numbers[1] == 0);
        return (x.numbers[0] == 0 && x.numbers[1] == 0 && x.numbers[2] == 0 && x.numbers[x.get_digits_number() - 1] == 0 && x.numbers[x.get_digits_number() - 2] == 0);
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
	int LongNumber::get_length(const char* const str) const {
        int length = 0;
        while (str[length] != END) {
            length++;
        }
        return length;
    }
    void LongNumber::subtraction_of_num(const LongNumber& x, LongNumber& result, const LongNumber& y) {
        short diff, index_1, index_2;
        if(x.get_sign() == NEGATIVE){
            index_1 = 1;
            index_2 = -1;
        }else{
            index_1 = -1;
            index_2 = 1;
        }
        for(int i = x.get_digits_number() - 1; i >= 0; i--) {
            diff = 0;

            if (y.length > i) {
                diff = diff + index_1 * y.numbers[i];
            }
            if (x.get_digits_number() > i) {
                diff = diff + index_2 * x.numbers[i];
            }
            if (diff < 0) {
                result.numbers[i] = 10 - abs(diff);
                result.numbers[i + 1]--;
            }else {
                result.numbers[i] = abs(diff);
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
    LongNumber LongNumber::leading_of_zeroes(LongNumber &x) {
        LongNumber result;
        result.sign = x.get_sign();
        result.sum = x.get_sum();
        if(x.get_sum() == 0){
            result.sign = NEUTRAL;
            result.length = 1;
            result.numbers[0] = 0;
            return result;
        }
        int length_of_tail = 0;

        for(int i = x.get_digits_number() - 1; i >= 0; i--){
            if(x.numbers[i] != 0){
                result.length = x.get_digits_number() - length_of_tail;
                break;
            }
            length_of_tail++;
        }
        for(int i = x.get_digits_number() - length_of_tail - 1; i >= 0; i--){
            result.numbers[i] = x.numbers[i];
        }
        return result;
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
        os << std::ends;
		return os;
	}
}
