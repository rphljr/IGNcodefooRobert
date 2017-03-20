#pragma once
#include <vector>
//desplay a vector of vectors
void desplayVecOfVec(std::vector<std::vector<int>> grid);
//random number betwen low and high inclods low and high
int RandomNum(int low, int high);
//makes a vector of x size randly , betwen and including low and high 
std::vector<int> pushVec(int size, int low, int high);
//helper to addAll
void addAllHelper(std::vector<std::vector<int>> grid, int size, int i, int j, std::vector<std::vector<int>>& addItUp, int& line, int direction);
// finds all posible combinatins of 9 in an x by x grid 
void addAll(std::vector<std::vector<int>> grid, int size);
