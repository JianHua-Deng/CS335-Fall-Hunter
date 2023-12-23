#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

int standardSort (std::vector<int>& nums, int& duration){

    auto start = std::chrono::steady_clock::now();

    std::sort(nums.begin(), nums.end());

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();  
   
    return *(nums.begin() + (nums.size() - 1)/2);
}