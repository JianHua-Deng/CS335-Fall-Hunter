#include "HalfSelectionSort.hpp"

int halfSelectionSort (std::vector<int>& nums, int& duration){

    auto start = std::chrono::steady_clock::now();

    if(nums.size() > 50000){
        std::cout << "Vector Size is too Large" << std::endl;
        return -1;
    }

    std::vector<int>::iterator i;
    std::vector<int>::iterator min;
    std::vector<int>::iterator it;

    //if i != the middle element in the vector + 1 
    for(i = nums.begin(); i <= nums.begin() + ((nums.size() - 1)/2); ++i){
        min = i;
        for(it = i + 1; it != nums.end(); ++it){
            if(*it < *min){
                min = it;
            }
        }
        std::iter_swap(i, min);
    }
    
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