#include<iostream>
#include<vector>


void bubble_sort(std::vector<int> &v);

int main(){
	std::vector<int> vec = {1, 0, 5, 3, 8};
	
	std::cout << "Before: " << "\n";
	
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
	
	bubble_sort(vec);
	
	std::cout << "After: " << "\n";
	
	for(int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
	return 0;
}

void bubble_sort(std::vector<int> &v){
	int n = v.size();
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(v[j] > v[j + 1])
				std::swap(v[j], v[j + 1]);
		}
	}
}
