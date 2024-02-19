#include <iostream>

#include "bubble_sort.hpp"

int main(){
	std::vector<int> vec = {1, 0, 5, 3, 8};
	
	cout << "Before: " << "\n";
	
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << "\n";
	
	BubbleSort::sort(vec);
	
	cout << "After: " << "\n";
	
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << "\n";
	return 0;
}