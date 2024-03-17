#include "long_number.hpp"

namespace IBusko {
	LongNumber::LongNumber() {
        this->length = 1;
        this->sign = NEUTRAL;
        this->sum = 0;
        this->numbers = new int[this->length];
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
        delete[] x.numbers;
        x.length = 0;
        x.sum = 0;
        x.sign = 0;

	}

	LongNumber::~LongNumber() {
//        std::cout << "delete: " << this << "\n";
		delete[] numbers;
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
        std::cout << "copy " << this << " " << &x << "\n";
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
//        std::cout << "move_copy_&&x " << this << " " << &x  << "\n";
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
            addition_of_num(numbers, size, result, x);
            if(is_null(result)){
                result.sign = NEUTRAL;
            }else{
                result.sign = x.get_sign();
            }
        }else{
            subtraction_of_num(numbers, size, result, x);
            if(is_null(result)){
                result.sign = NEUTRAL;
            }else if(this->more_compare_by_module(x)){
                result.sign = this->sign;
            }else{
                result.sign = x.sign;
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
            subtraction_of_num(numbers, size, result, x);
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
        LongNumber temp1, temp_this;;

        int mx = std::max(this->get_digits_number(), x.get_digits_number());
        int mn = std::min(this->get_digits_number(), x.get_digits_number());

        result.length = mx;

        if(!more_compare_by_module(x)){
            return zero;
        }
        int l = 0 , r = 10, ans = 0, mid = 1;
        temp1 = x;
        temp_this = *this;
        int count = 0;
        for(int j = mx - 1; j >= mn - 1; j--) {
            std::cout << "this: "<< this << " " << *this << "\n";
//            std::cout << "temp_this: "<< &temp_this << "\n";
            LongNumber temp2 = left_shift(temp_this, j, j - mn + 1);
            l = 0, r = 10, mid = 0, ans = 0;
//            std::cout << "before_this: " << this << " " << *this << "\n";
            std::cout << "temp2: " << temp2 << "\n";
            while(l <= r) {
                mid = (l + r) / 2;
                LongNumber k = convert_int_to_big_integer(mid);
                LongNumber t = temp1 * k;

                if ((t < temp2) || (t == temp2)) {
                    ans = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            std::cout << "ans: " << ans << "\n";
//            std::cout << "after_this: " << this << " " << *this << "\n";
            LongNumber k = convert_int_to_big_integer(ans);
            LongNumber divider = temp1 * k;
            std::cout << "divider: " << divider << "\n";
            //different_of_digit(temp_this, divider);
//                std::cout << "diff: " << temp2 - temp1 * k << "\n";
            std::cout << ans << "\n";
            result.numbers[j] = ans;
        }
        std::cout << "++end" << "\n";
        return result;
	}

	LongNumber LongNumber::operator % (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}

    void LongNumber::different_of_digit(IBusko::LongNumber &x, const IBusko::LongNumber &y) {

        int size_x = x.get_digits_number();
        int size_y= y.get_digits_number();
        for(int i = size_x - 1; i >= size_y; i--){
            std::cout << "num: " << x.numbers[i] << " " << y.numbers[i - size_y] << "\n";
            x.numbers[i] -= y.numbers[i - size_y];
        }
        std::cout << "-----------" << "\n";
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
    LongNumber LongNumber::left_shift(const IBusko::LongNumber &x, int start, int end) {
        LongNumber result;
        std::cout << &x << "\n";
        result.length = start - end + 1;
        result.sign = POSITIVE;

        for(int i = 0; i < result.length; i++){
            result.numbers[i] = 0;
        }
        for(int i = end; i <= start; i++){
            result.numbers[i - end] = x.numbers[i];
        }
        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());

        return result;
    }

	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}
    bool LongNumber::is_null(const IBusko::LongNumber &x) const {
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
    void LongNumber::subtraction_of_num(int *numbers, int size, LongNumber& result, const LongNumber& x) {
        short diff, index_1, index_2;
        if(this->sign == NEGATIVE){
            index_1 = 1;
            index_2 = -1;
        }else{
            index_1 = -1;
            index_2 = 1;
        }
        for(int i = size - 2; i >= 0; i--) {
            diff = 0;
            if (x.length > i) {
                diff = diff + index_1 * x.numbers[i];
            }
            if (length > i) {
                diff = diff + index_2 * numbers[i];
            }
            if (diff < 0) {
                result.numbers[i] = 10 - abs(diff);
                result.numbers[i + 1]--;
            } else {
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
    LongNumber LongNumber::leading_of_zeroes(IBusko::LongNumber &x) {
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
		for(int i = x.get_digits_number() - 1; i >= 0; i--){
            os << x.numbers[i];
        }
        os << std::ends;
		return os;
	}
}
