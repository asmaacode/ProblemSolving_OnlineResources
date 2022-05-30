#include <iostream>
#include <cmath>
#include<unordered_map>
using namespace std;

/*Leetcode problem 1 :

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example :

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity? Yes, it is O(n)
*/
vector<int> twoSum(vector<int>& nums, int target) {
	const int  size = nums.size();
	vector <int> result;

	unordered_map <int, int>pool;
	unordered_map <int, int>poolIndexes;
	unordered_map <int, int>negativePool;
	unordered_map <int, int>negativePoolIndexes;

	int currentElement,currentElementAbs,complement;
	bool foundTheSolution = false;

	for (int i = 0; i < size;i++) {
		currentElementAbs = abs(nums[i]);
		currentElement = nums[i];

		if (pool.find(currentElementAbs) != pool.end())
			if (currentElement == pool[currentElementAbs])
			{
				result.push_back(poolIndexes[currentElementAbs]);
				foundTheSolution = true;
			}
		if (negativePool.find(currentElementAbs) != negativePool.end())
			if (currentElement== negativePool[currentElementAbs]) {
				result.push_back(negativePoolIndexes[currentElementAbs]);
				foundTheSolution = true;
			}

		if (foundTheSolution) {
			result.push_back(i);
			break;
		}
	
		if (currentElement<= target) {
			complement = target - nums[i];
			pool[abs(complement)] = complement;
			poolIndexes[abs(complement)] = i;
		}
		else {
			complement = currentElement - target;
			negativePool[complement] = target - currentElement;
			negativePoolIndexes[complement] = i;
		}

	}
	return result;
}

int main() {
	vector<int> nums = {0, 4, 3, 0};
	int target = 0;

	vector<int>res = twoSum(nums,target);
	cout << res.at(0) <<res.at(1);
	
	return 0;
}
