#include "long_number.hpp"

namespace IBusko {
	LongNumber::LongNumber() {
        this->length = 0;
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

        for(int i = 0; i < length; i++){
            numbers[i] = x.numbers[i];
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
        this->length = x.get_digits_number();
        this->sign = x.get_sign();
        this->sum = x.get_sum();

        if(this->numbers != nullptr){
            delete[] this->numbers;
        }
        this->numbers = new int[length];

        for(int i = 0; i < length; i++){
            numbers[i] = x.numbers[i];
        }
		return *this;
	}

	LongNumber& LongNumber::operator = (LongNumber&& x) {
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
                if(this->get_digits_number() == mn && x.get_digits_number() == mx)
                    mul = this->numbers[i] * x.numbers[j];
                if(this->get_digits_number() == mx && x.get_digits_number() == mn)
                    mul = this->numbers[j] * x.numbers[i];

                result.numbers[j + idx] += mul;
                result.numbers[j + 1 + idx] += result.numbers[j + idx] / 10;
                result.numbers[j + idx] %= 10;
            }
            idx++;
        }

//        for(int i = 0; i < result.get_digits_number(); i++){
//            std::cout << result.numbers[i];
//        }
//        std::cout << "\n";
        if(is_null(result)){
            result.sign = NEUTRAL;
        }else if(this->get_sign() == x.get_sign()){
            result.sign = POSITIVE;
        }else{
            result.sign = NEGATIVE;
        }

        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());

		return result;
	}

	LongNumber LongNumber::operator / (LongNumber& x) {
        LongNumber result;
        int temp;
        LongNumber two("2");
        LongNumber one("1");
        LongNumber zero("0");
//
        int mx = std::max(this->get_digits_number(), x.get_digits_number());
        int mn = std::min(this->get_digits_number(), x.get_digits_number());
//
        result.length = mx;

        for(int i = this->get_digits_number() - 1; i >= 0; i--){
            std::cout << this->numbers[i];
        }
        std::cout << "\n";
        for(int i = x.get_digits_number() - 1; i >= 0; i--){
            std::cout << x.numbers[i];
        }
        std::cout << "\n";

        int carry = 0, cur = 0;
        for(int j = mn - 1; j >= 0; j--){
            carry = 0;
            for(int i = mx - 1; i >= 0; i--){
                if(this->get_digits_number() == mx){
                    cur = this->numbers[i] + carry * 10;
                    this->numbers[i] = cur / x.numbers[j];
                    carry = cur % x.numbers[j];
                }else{
                    cur = x.numbers[i] + carry * 10;
                    x.numbers[i] = cur / this->numbers[j];
                    carry = cur % this->numbers[j];
                }
            }
        }
        std::cout << "end" << "\n";
        for(int i = mx - 1; i >= 0; i--){
            std::cout << this->numbers[i];
        }
        std::cout << "\n";
//        std::cout << this->get_sign() << "\n";
//        std::cout << this->get_sum() << "\n";
//        if(*this < x){
//            result = zero;
//            return result;
//        }else{
//            temp = *this;
//            std::cout << temp << "\n";
//            while(temp > two){
//                std::cout << temp << " " << x << "\n";
//                temp = temp - x;
//                result = result + one;
//            }
//            return  result;
//        }
//        std::cout << result << "\n";
//        division_of_num(numbers, this->get_digits_number(), result, x);
        return result;
	}

	LongNumber LongNumber::operator % (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
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
	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}
    bool LongNumber::is_null(const IBusko::LongNumber &x) const {
        if(x.get_digits_number() == 1)
            return x.numbers[0] == 0;
        if(x.get_digits_number() == 2)
            return x.numbers[0] == 0 && x.numbers[1] == 0;
        return (x.numbers[0] == 0 && x.numbers[1] == 0 && x.numbers[2] == 0 && x.numbers[x.get_digits_number() - 1] == 0 && x.numbers[x.get_digits_number() - 2] == 0 && x.numbers[x.get_digits_number() - 3] == 0);
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
    void LongNumber::division_of_num(int *numbers, int size, IBusko::LongNumber &result, const IBusko::LongNumber &x) {
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
        bool null_capacity = true;
		for(int i = x.get_digits_number() - 1; i >= 0; i--){
            if(x.numbers[i] != 0 && null_capacity)
                null_capacity = false;
            if(!(null_capacity))
                os << x.numbers[i];
        }

        os << std::ends;
		return os;
	}
}
