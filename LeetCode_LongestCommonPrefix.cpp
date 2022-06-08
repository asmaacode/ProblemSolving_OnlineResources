#include <iostream>
#include <string>
#include<vector>
using namespace std;
/*
* LeetCode 
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
	Input: strs = ["flower","flow","flight"]
	Output: "fl"

Example 2:
	Input: strs = ["dog","racecar","car"]
	Output: ""
	Explanation: There is no common prefix among the input strings.

Constraints:
	strs.length <= 200
	strs[i].length <= 200
	strs[i] consists of only lower-case English letters.
*/

int shortestLength(vector<string> strs) {
	int shortestLength = strs[0].length();
	for (int counter = 1; counter < strs.size();counter++) {
		if (shortestLength > strs[counter].length())
		{
			shortestLength = strs[counter].length();
		}
	}
	return shortestLength;
}
int findLongestPrefixLength(vector<string> strs, int strLength) {
	string currentString,nextString;
	for (int index = 0; index < strs.size()-1;index++) {
		currentString = strs[index];
		nextString = strs[index+1];
		for (int letter= 0; letter < strLength;letter++) {
			if(currentString[letter] != nextString[letter]){
				strLength = letter;
				break;
			}
		}
		if (strLength <= 0) return -1;
	}
	return strLength;
}
string findLongestPrefix(vector<string> strs,  int length) {
	if (length < 0)
		return "";
	else
		return strs[0].substr(0,length);
}
string longestCommonPrefix(vector<string>& strs) {
	return findLongestPrefix(strs, findLongestPrefixLength(strs, shortestLength(strs)));
}
/*Main Call :
	vector<string> strs = { "flower","flow","flight" };
	cout<<longestCommonPrefix(strs);
*/
