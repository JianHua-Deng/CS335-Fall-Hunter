#include "StandardSort.hpp"

int standardSort (std::vector<int>& nums, int& duration){

    auto start = std::chrono::steady_clock::now();

    std::sort(nums.begin(), nums.end());

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();  

    /*
    if(nums.size() % 2 == 0){
        return *(nums.begin() + (nums.size()/2) - 1);
    }else{
        return *(nums.begin() + (nums.size()/2));
    }
    */
   
    return *(nums.begin() + (nums.size() - 1)/2);
}