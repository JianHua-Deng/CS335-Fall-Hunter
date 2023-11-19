#include "MergeSort.hpp"

int mergeSort (std::vector<int>& nums, int& duration){

    auto start = std::chrono::steady_clock::now();

    mergeSort(nums);

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();    
    
    if(nums.size() % 2 == 0){
        return *(nums.begin() + (nums.size()/2) - 1);
    }else{
        return *(nums.begin() + (nums.size()/2));
    }

    

}

void mergeSort (std::vector<int>& nums){
    if(nums.size() <= 1){
        return;
    }
        int middle = nums.size()/2;

        std::vector<int> left(nums.begin(), nums.begin() + middle);
        std::vector<int> right(nums.begin() + middle, nums.end());

        mergeSort(left);
        mergeSort(right);
        std::merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin());
}

