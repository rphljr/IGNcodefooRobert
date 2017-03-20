#include <iostream>
#include <vector>
#include <ctime>
#include "Header.h"
using namespace std;
int main()
{
	srand(time(0));
	int size = 3;
	int low = 1;
	int high = 9;
	vector<vector<int>> grid;	
	for (size_t i = 0; i < size; i++)
	{
		grid.push_back(pushVec(size,low,high));
	}
	desplayVecOfVec(grid);	
	addAll(grid, size);
	return 0;
}
