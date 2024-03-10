#include "long_number.hpp"

namespace IBusko {
	LongNumber::LongNumber() {
		this->length = 0;
        this->sum = 0;
	}

	LongNumber::LongNumber(const char* const str) {
		this->length = get_length(str);
		this->numbers = new int[length];

        for(int i = 0; i < length; i++){
            numbers[i] = 0;
        }
		
		if(str[0] == MINUS){
			this->sign = NEGATIVE;	
		}else{
			this->sign = POSITIVE;
		}

        for(int i = length-1; i > 0; i--){
            numbers[length-1-i] = str[i] - 48;
        }
//        if(sign == NEGATIVE){
//
//        }else{
//            for(int i = length-1; i >= 0; i--){
//                numbers[length-1-i] = str[i] - 48;
//            }
//        }

		this->sum = sum_of_arr(numbers, length);

		std::cout << "create " << this << "\n";
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
	}
	
	LongNumber::~LongNumber() {
		std::cout << "delete " << this << "\n";
		delete[] numbers;
	}
	
	LongNumber& LongNumber::operator = (const char* const str) {
        this->length = get_length(str);

        if(str[0] == MINUS){
            this->sign = NEGATIVE;
        }else{
            this->sign = POSITIVE;
        }

        if(this->numbers != nullptr){
            delete[] this->numbers;
        }

        this->numbers = new int[length];
        for(int i = length-1; i >= 0; i--){
            numbers[length-1-i] = str[i] - 48;
        }
        std::cout << "operator 1" << "\n";
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
        std::cout << "operator 2" << "\n";
		return *this;
	}

	LongNumber& LongNumber::operator = (LongNumber&& x) {
        std::cout << "operator 3" << "\n";
		return *this;
	}
	
	bool LongNumber::operator == (const LongNumber& x) {
        // TODO
		return true;
	}
	
	bool LongNumber::operator > (const LongNumber& x) {
		// TODO
		return true;
	}

	bool LongNumber::operator < (const LongNumber& x) {
		// TODO
		return true;
	}
	
	LongNumber LongNumber::operator + (const LongNumber& x) {
        LongNumber result;
//            int size = std::max(x.length, length);
//        if(x.length > length) {
//            result = x;
//        }else{
//            result = this;
//        }
//
//        short sum;
//        for(int i = 0; i < size; i++){
//            sum = x.numbers[i] + this->numbers[i];
//            result.numbers[i] = sum % 10;
//            result.numbers[i+1]++;
//        }
//
//        result.sum = sum_of_arr(result.numbers, result.length);
		return result;
	}
	
	LongNumber LongNumber::operator - (const LongNumber& x) {
		// TODO
		LongNumber result = x;
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
    int LongNumber::get_sign() const {
        return sign;
    }
	int LongNumber::get_sum() const {
		return sum;
	}
	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}
	
	// ----------------------------------------------------------
	// PRIVATE
	// ----------------------------------------------------------
	int LongNumber::get_length(const char* const str) const {
		int length = 0;
		length = std::strlen(str);
		return length;
	}
    void LongNumber::sum_of_num(int &numbers, int size) {

    }
	
	int LongNumber::sum_of_arr(int *numbers, int size) const {
		int s = 0;
		for(int i = 0; i < std::min(size, 6); i++)
			s += pow(10, i) * numbers[i];
		return s;
	}
	// ----------------------------------------------------------
	// FRIENDLY
	// ----------------------------------------------------------
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		// TODO
		return os;
	}
}
