#include <iostream>
#include <vector>
#include "Header.h"

void desplayVecOfVec(std::vector<std::vector<int>> grid)
{
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[i].size(); j++)
		{
			std::cout << grid[i][j] << "   ";
		}
		std::cout << std::endl;
	}
}

int RandomNum(int low, int high)
{
	return low + rand() % (high - low + 1);
}

std::vector<int> pushVec(int size, int low, int high)
{
	std::vector<int> pushVec;
	for (size_t i = 0; i < size; i++)
	{
		pushVec.push_back(RandomNum(low, high));
	}
	return pushVec;
}

void addAllHelper(std::vector<std::vector<int>> grid, int size, int i, int j, std::vector<std::vector<int>>& addItUp, int& line, int direction)
{
	//checks for 9
	if (grid[i][j] == 9)
	{
		return;
	}
	int toltal = grid[i][j];
	//adds up the toltal
	for (size_t i = 0; i < addItUp[line].size(); i++)
	{
		toltal += addItUp[line][i];
	}
	//checks to make shore toltal is less than 9
	if (toltal >= 9)
	{
		return;

	}
	
		//check left
		if (j != 0 && direction != 1)
		{
			
			toltal += grid[i][j - 1];


			if (toltal > 9)
			{

				std::vector<int> push;
				addItUp.push_back(push);
				line++;

			}
			else if (toltal == 9)
			{
				addItUp[line].push_back(grid[i][j]);
				addItUp[line].push_back(grid[i][j - 1]);
				std::vector<int> push;
				addItUp.push_back(push);
				line++;

			}
			else
			{
				addItUp[line].push_back(grid[i][j]);

				addAllHelper(grid, size, i, j - 1, addItUp, line, 1);

			}
			toltal -= grid[i][j - 1];
		}
		//check up
		if (i != 0 && direction != 2)
		{
			

			toltal += grid[i - 1][j];
			if (toltal > 9)
			{
				std::vector<int> push;
				addItUp.push_back(push);
				line++;

			}
			else if (toltal == 9)
			{
				addItUp[line].push_back(grid[i][j]);
				addItUp[line].push_back(grid[i - 1][j]);
				std::vector<int> push;
				addItUp.push_back(push);
				line++;

			}
			else
			{
				addItUp[line].push_back(grid[i][j]);

				addAllHelper(grid, size, i - 1, j, addItUp, line, 2);

			}
			toltal -= grid[i - 1][j];


		}
		//check up left
		if (j != 0 && i != 0 && direction != 3)
		{
			
			toltal += grid[i - 1][j - 1];
			if (toltal > 9)
			{
				std::vector<int> push;
				addItUp.push_back(push);
				line++;

			}
			else if (toltal == 9)
			{
				addItUp[line].push_back(grid[i][j]);
				addItUp[line].push_back(grid[i - 1][j - 1]);
				std::vector<int> push;
				addItUp.push_back(push);
				line++;

			}
			else
			{
				addItUp[line].push_back(grid[i][j]);

				addAllHelper(grid, size, i - 1, j - 1, addItUp, line, 3);


			}
			toltal -= grid[i - 1][j - 1];

		}
		//check up righ
		if (i != 0 && j != size - 1 && direction != 4)
		{
			
			toltal += grid[i - 1][j + 1];
			if (toltal > 9)
			{
				std::vector<int> push;
				addItUp.push_back(push);
				line++;

			}
			else if (toltal == 9)
			{
				addItUp[line].push_back(grid[i][j]);
				addItUp[line].push_back(grid[i - 1][j + 1]);
				std::vector<int> push;
				addItUp.push_back(push);
				line++;

			}
			else
			{

				addItUp[line].push_back(grid[i][j]);

				addAllHelper(grid, size, i - 1, j + 1, addItUp, line, 4);


			}
			toltal -= grid[i - 1][j + 1];


		}

	
	return;

}

void addAll(std::vector<std::vector<int>> grid, int size)
{

	//holder vector for ansers 
	std::vector<std::vector<int>> addItUp;
	int line = -1;

	for (int i = size - 1; i >= 0; i--)
	{

		for (int j = size - 1; j >= 0; j--)
		{
			//vector to push on to vector of vectors
			std::vector<int> push;
			addItUp.push_back(push);
			addAllHelper(grid, size, i, j, addItUp, ++line, 0);

		}
	}
	//sepperater space
	std::cout << std::endl << std::endl << std::endl;
	//desply ansers
	for (size_t i = 0; i < addItUp.size(); i++)
	{
		int toltal = 0;
		for (size_t j = 0; j < addItUp[i].size(); j++)
		{
			toltal += addItUp[i][j];
			if (toltal == 9)
			{
				for (size_t k = 0; k <= j; k++)
				{
					std::cout << addItUp[i][k] << " ";
					if (k != j)
					{ std::cout << "+ "; }
				}
				std::cout << " = 9\n";
			}
		}
	}

}


