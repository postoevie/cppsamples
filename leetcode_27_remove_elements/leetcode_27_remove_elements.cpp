#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

//https://leetcode.com/problems/remove-element/description/

class Solution {
public:
    int remove_element(vector<int>& nums, int val) {
        // The solution takes more memory consuming less time (~0ms on leetcode tests)
        vector<int> out_indexes = {};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                out_indexes.push_back(i);
            }
        }

        int out_indexes_size = out_indexes.size();

        for (int i = 0; i < out_indexes_size; i++) {
            nums[i] = nums[out_indexes[i]];
        }

        return out_indexes_size;
    }
};

void test_solution(vector<int> nums_array, int value_to_remove, vector<int>expected_nums_array) {
    vector<int> nums = nums_array;
    int val = value_to_remove;
    vector<int> expectedNums = expected_nums_array;

    Solution solution = Solution();
    int k = solution.remove_element(nums, val);
    
    assert(k == expectedNums.size());

    std::sort(nums.begin(), nums.begin() + k, std::less<int>()); // Sort the first k elements of nums

    for (int i = 0; i < k; i++) {
        assert(nums[i] == expectedNums[i]);
    }
}
 
int main() {
    test_solution({1, 2, 4, 1}, 1, {2, 4});
    test_solution({1, 2, 4, 1}, 2, {1, 1, 4});
    test_solution({}, 1, {});
    test_solution({1, 1, 1, 1}, 1, {});
    test_solution({8, 2, 5, 6, 7, 9, 1, 2, 11}, 2, {1, 5, 6, 7, 8, 9, 11});
    return 0;
}