#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int inPlaceMergeSort(std::vector<int>& nums, int& duration);
void inPlaceMergeSort(std::vector<int>::iterator left, std::vector<int>::iterator right);