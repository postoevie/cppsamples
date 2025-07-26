
#include "sort_num_custom_.h"

#include <iostream>

namespace customsort {
	void bubbleSort(std::vector<int>& vec) {
		int n = vec.size();
		bool swapped;

		for (int i = 0; i < n - 1; ++i) {
			swapped = false;

			for (int j = 0; j < n - i - 1; ++j) {
				if (vec[j] > vec[j + 1]) {
				std::swap(vec[j], vec[j + 1]);
				swapped = true;
			}
		}

		// Optimization: if no swaps were done, array is sorted
		if (!swapped)
			break;
		}
	}

	void sort(std::vector<int>& numbers) {
		std::cout << "Bubble it!" << std::endl;
		bubbleSort(numbers);
	}
}