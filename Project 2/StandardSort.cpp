#include "StandardSort.hpp"

int standardSort (std::vector<int>& nums, int& duration){
    std::sort(nums.begin(), nums.end());

    if(nums.size() % 2 == 0){
        return *(nums.begin() + (nums.size()/2) - 1);
    }else{
        return *(nums.begin() + (nums.size()/2));
    }
}