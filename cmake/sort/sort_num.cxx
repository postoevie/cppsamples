#include <iostream>
#include <vector>
#include <algorithm>

#ifdef USE_CUSTOM_SORT
#include "sort_num_custom_.h"
#endif

std::vector<int> map_to_integers(int size, char* strings[]) {
	std::vector<int> numbers = {};
	for (int argIndex = 1; argIndex < size; argIndex++) {
		char* argumentString = strings[argIndex];
		int argumentNumber = std::stoi (argumentString);
		numbers.push_back(argumentNumber);
	}
	return numbers;
}

void performSort(std::vector<int>& numbers) {
	#ifdef USE_CUSTOM_SORT
	customsort::sort(numbers);
	#else
	std::sort(numbers.begin(), numbers.end());
	#endif
}

int main(int argc, char* argv[]) {
	try {
		std::vector<int> numbers = map_to_integers(argc, argv);
		performSort(numbers);
		std::cout << "Sorted vector: ";
		for (int num : numbers) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument: " << ia.what() << '\n';
		return 1;
	}
}