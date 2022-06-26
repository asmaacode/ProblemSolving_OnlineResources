#include <iostream>
#include<string>
using namespace std;
/*

Title: Buddy Strings
Link : https://leetcode.com/problems/buddy-strings/
Description:
		Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
		Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
		For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example:
		Input: s = "ab", goal = "ba"
		Output: true
		Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Constraints:
		1 <= s.length, goal.length <= 2 * 104
		s and goal consist of lowercase letters.
*/


bool hasDuplicate(string str) {
	char letter = NULL;
	for (int i = 0; i < str.length();i++) {
		letter = str[i];
		str[i] = ' ';
		if (str.find(letter) != string::npos)
			return true;
	}
	return false;
}

bool notSameLength(string str1, string str2) {
	return str1.length() != str2.length();
}

bool acceptedIndexes(string str1, string str2, int index1, int index2) {
	return	str1[index1] != str2[index2] || str1[index2] != str2[index1];
}

bool buddyStrings(string str, string goal) {
	if (notSameLength(str,goal)) {
		return false;
	}
	int diffrences = 0, index1 = -1, index2 = -1;
	bool twiceValidIndexes = false;
	if (str == goal) {
		if (hasDuplicate(str))
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	for (int i = 0; i < str.length();i++) {
		if (str[i] != goal[i]) {
			switch (diffrences)
			{
			case 0:
				diffrences++;
				index1 = i;
				break;
			case 1:
				diffrences++;
				index2 = i;
				twiceValidIndexes = true;
				break;
			default:
				return false;
				break;
			}
		}
	}
	if (!twiceValidIndexes)
	{
		return false;
	}
	else
	{
		if (acceptedIndexes(str,goal,index1,index2))
			return false;
		return true;
	}
}
