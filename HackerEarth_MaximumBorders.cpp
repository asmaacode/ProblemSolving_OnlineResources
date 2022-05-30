#include <iostream>
#include <cmath>
#include<unordered_map>
using namespace std;
/*

Hacker Earth 
Maximum borders Problem :
You are given a table with  rows and  columns. Each cell is colored with white or black. Considering the shapes created by black cells, what is the maximum border of these shapes? Border of a shape means the maximum number of consecutive black cells in any row or column without any white cell in between.
A shape is a set of connected cells. Two cells are connected if they share an edge. Note that no shape has a hole in it.

Input format
The first line contains  denoting the number of test cases.
The first line of each test case contains integers  denoting the number of rows and columns of the matrix. Here, '#' represents a black cell and '.' represents a white cell. 
Each of the next  lines contains  integers.

Output format
Print the maximum border of the shapes.

Time Limit: 1
Memory Limit: 256*/

int main() {
	int attempt, rows, columns, blackCells, currentBlackCells, lastIndex, firstIndex;
	attempt = rows = columns = blackCells = currentBlackCells = lastIndex = firstIndex = 0;
	string rowData = "";
	cin >> attempt;
	while (attempt > 0) {
		cin >> rows >> columns;
		blackCells = 0;
		while (rows > 0) {
			cin >> rowData;
			lastIndex = rowData.find_last_of("#");
			if (lastIndex > -1) lastIndex++;
			firstIndex = rowData.find_first_of("#");
			currentBlackCells = lastIndex - firstIndex;
			if (currentBlackCells > blackCells)
				blackCells = currentBlackCells;
			rows--;
		}

		cout << blackCells << endl;
		attempt--;
	}
	return 0;
}
