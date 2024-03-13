#include "long_number.hpp"

namespace IBusko {
	LongNumber::LongNumber() {
        this->length = 0;
        this->sign = 0;
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
        int size = std::max(x.length, length) + 1;
        result.length = size;
        result.numbers = new int[size];
        for(int i = 0; i < result.get_digits_number(); i++){
            result.numbers[i] = 0;
        }
        if(this->get_sign() == x.get_sign()){
            result.sign = x.get_sign();
            addition_of_num(numbers, size, result, x);
        }else{
            if(this->more_compare_by_module(x)){
                result.sign = this->sign;
            }else{
                result.sign = x.sign;
            }
            subtraction_of_num(numbers, size, result, x);
        }
        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());
		return result;
	}
	
	LongNumber LongNumber::operator - (const LongNumber& x) {
        LongNumber result;
        int size = std::max(x.length, length) + 1;
        result.length = size;
        result.numbers = new int[size];
        for(int i = 0; i < result.length; i++){
            result.numbers[i] = 0;
        }

        if(this->get_sign() == POSITIVE && x.get_sign() == NEGATIVE || this->get_sign() == NEGATIVE && x.get_sign() == POSITIVE){
            result.sign = this->get_sign();
            addition_of_num(numbers, size, result, x);
        }else{
            if(this->more_compare_by_module(x)){
                result.sign = this->get_sign();
            }else{
                result.sign = x.get_sign();
            }
            subtraction_of_num(numbers, size, result, x);
        }
        result.sum = sum_of_arr(result.numbers, result.get_digits_number(), result.get_sign());
        return result;
	}

	LongNumber LongNumber::operator * (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}

	LongNumber LongNumber::operator / (const LongNumber& x) {
		// TODO
		LongNumber result;
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
               // std::cout << x.numbers[i] << " ";
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
		for(int i = 0; i < std::min(size, 7); i++)
			s += pow(10, i) * numbers[i];
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
		// TODO
		return os;
	}
}
