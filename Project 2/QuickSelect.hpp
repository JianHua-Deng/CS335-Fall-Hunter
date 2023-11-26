#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int quickSelect (std::vector<int>& nums, int& duration);
void quickSelect (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator center);
std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
std::vector<int>::iterator medianof3 (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);