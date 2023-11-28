#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int medianOfMediansMethod ( std::vector<int>& nums, int& duration );
int medianOfMedians ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high );
   // returns the median of medians of all elements contained between high and low, inclusive.

int quickSelect (std::vector<int>& nums, int& duration);
void quickSelect (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator center);
std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
std::vector<int>::iterator medianof3 (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);