/*
https://leetcode.com/problems/next-permutation/
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 -> 1,3,2
3,2,1 -> 1,2,3
1,1,5 -> 1,5,1
*/

#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return;
        int pos = -1;
        for (int i = (int)nums.size() - 2; i >= 0; --i) {
            if (nums[i + 1] > nums[i]) {
                pos = i + 1;
                std::sort(nums.begin() + pos, nums.end());
                // find index of the next bigger to [i]
                int swap_pos = -1;
                for (size_t j = i + 1; j < nums.size(); ++j) {
                    if (nums[j] > nums[i]) {
                        swap_pos = (int)j;
                        break;
                    }
                }
                // swap next bigger found and sort the rest of array
                int swap = nums[i];
                nums[i] = nums[swap_pos];
                nums[swap_pos] = swap;
                std::sort(nums.begin() + pos, nums.end());
                break;
            }
        }
        if (pos == -1)
            std::sort(nums.begin(), nums.end());
    }

    void test()
    {
        vector<int> in = { 1, 2, 3 };
        nextPermutation(in);
        cout << "Test 1 " << string(in == vector<int>({ 1, 3, 2 }) ? "passed" : "FAILED") << "\n";

        in = { 3, 2, 1 };
        nextPermutation(in);
        cout << "Test 2 " << string(in == vector<int>({ 1, 2, 3 }) ? "passed" : "FAILED") << "\n";

        in = { 1, 1, 5 };
        nextPermutation(in);
        cout << "Test 3 " << string(in == vector<int>({ 1, 5, 1 }) ? "passed" : "FAILED") << "\n";

        in = { 1, 0, 9 };
        nextPermutation(in);
        cout << "Test 4 " << string(in == vector<int>({ 1, 9, 0 }) ? "passed" : "FAILED") << "\n";

        in = { 1, 3, 2 };
        nextPermutation(in);
        cout << "Test 5 " << string(in == vector<int>({ 2, 1, 3 }) ? "passed" : "FAILED") << "\n";

        in = { 1 };
        nextPermutation(in);
        cout << "Test 6 " << string(in == vector<int>({ 1 }) ? "passed" : "FAILED") << "\n";

        in = {};
        nextPermutation(in);
        cout << "Test 7 " << string(in == vector<int>({}) ? "passed" : "FAILED") << "\n";

        in = { 2, 3, 1 };
        nextPermutation(in);
        cout << "Test 8 " << string(in == vector<int>({ 3, 1, 2 }) ? "passed" : "FAILED") << "\n";

        in = { 2, 4, 3, 1, 0 };
        nextPermutation(in);
        cout << "Test 9 " << string(in == vector<int>({ 3, 0, 1, 2, 4 }) ? "passed" : "FAILED") << "\n";
    }
};