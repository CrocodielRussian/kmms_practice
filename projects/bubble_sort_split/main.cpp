#include <iostream>

#include "bubble_sort.hpp"

int main(){
	std::vector<int> vec = {1, 0, 5, 3, 8};
	
	std::cout << "Before: " << "\n";
	
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
	
	BubbleSort::sort(vec);
	
	std::cout << "After: " << "\n";
	
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
	return 0;
}
