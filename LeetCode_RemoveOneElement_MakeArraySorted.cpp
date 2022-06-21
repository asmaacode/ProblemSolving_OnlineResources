#include <iostream>
#include <unordered_map>

using namespace std;

/*
Title: Remove One Element to Make the Array Strictly Increasing
Link : https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
Description:
        Given a 0-indexed integer array nums, 
        return true if it can be made strictly increasing after removing exactly one element, or false otherwise. 
        If the array is already strictly increasing, return true.
        The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).

Example:
      Input: nums = [1,2,10,5,7]
      Output: true
      Explanation: 
                  By removing 10 at index 2 from nums, it becomes [1,2,5,7].
                  [1,2,5,7] is strictly increasing, so return true.

Constraints:
      2 <= nums.length <= 1000
      1 <= nums[i] <= 1000
*/


bool isSortedNow(vector<int>& nums) {
	for (int i = 0;i <= nums.size() - 2;i++) {
		if (!(nums[i] < nums[i+1])) {
			return false;
		}
	}
	return true;
}

bool hasNoDuplicate(vector<int>& nums){
	unordered_map <int, int> duplicate_tester;
	for (int i = 0;i < nums.size();i++) {
		if (duplicate_tester[nums[i]] == nums[i]) {
			return false;
		}
		else {
			duplicate_tester[nums[i]] = nums[i];
		}
		
	}
	return true;
}

bool canBeIncreasing(vector<int>& nums) {
	vector<int> copy_nums;
	bool hasNoDuplicated = true, isSorted = true;
	if ((isSortedNow(nums) && hasNoDuplicate(nums)) || nums.size()< 3) {
		return true;
	}
	for (int i = 0;i < nums.size();i++) {
		copy_nums = nums;
		copy_nums.erase((i)+copy_nums.begin());
		if (isSortedNow(copy_nums) && hasNoDuplicate(copy_nums)) {
			return true;
		}
	}
	return false;
}



int main() {
	vector<int> nums = { 512,867,904,997,403 };
	if (canBeIncreasing(nums)) 
    cout << "True"; 
	else 
    cout << "False";
  
	return 0;
}
