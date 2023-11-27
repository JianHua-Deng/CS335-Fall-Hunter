#include "InPlaceMergeSort.hpp"

int inPlaceMergeSort(std::vector<int>& nums, int& duration){

    auto start = std::chrono::steady_clock::now();

    inPlaceMergeSort(nums.begin(), nums.end());

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    return *(nums.begin() + (nums.size() - 1)/2);
    
    /*
    if(nums.size() % 2 == 0){
        return *(nums.begin() + (nums.size()/2) - 1);
    }else{
        return *(nums.begin() + (nums.size()/2));
    }
    */
    

}

void inPlaceMergeSort(std::vector<int>::iterator left, std::vector<int>::iterator right){
    if(right - left <= 1){
        return;
    }
        std::vector<int>::iterator mid = left + (right - left)/2;

        inPlaceMergeSort(left, mid);
        inPlaceMergeSort(mid, right);
        std::inplace_merge(left, mid, right);
}