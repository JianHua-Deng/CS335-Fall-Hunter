#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

void inPlaceMergeSort(std::vector<int>::iterator left, std::vector<int>::iterator right){
    if(right - left <= 1){//base case
        return;
    }
        std::vector<int>::iterator mid = left + (right - left)/2;

        //pretty much the same idea as standard mergesort, except this time we are directly putting iterator into the parameter
        inPlaceMergeSort(left, mid);
        inPlaceMergeSort(mid, right);
        std::inplace_merge(left, mid, right);
}

int inPlaceMergeSort(std::vector<int>& nums, int& duration){

    auto start = std::chrono::steady_clock::now();

    inPlaceMergeSort(nums.begin(), nums.end());

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    return *(nums.begin() + (nums.size() - 1)/2);

}
