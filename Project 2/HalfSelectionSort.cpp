#include "HalfSelectionSort.hpp"

int halfSelectionSort (std::vector<int>& nums, int& duration){
    if(nums.size() > 50000){
        std::cout << "Vector Size is too Large" << std::endl;
        return -1;
    }

    std::vector<int>::iterator i;
    std::vector<int>::iterator min;
    std::vector<int>::iterator it;

    //if i != the middle element in the vector + 1 
    for(i = nums.begin(); i != nums.begin() + (nums.size()/2) + 1; ++i){
        min = i;
        for(it = i + 1; it != nums.end(); ++it){
            if(*it < *min){
                min = it;
            }
        }
        std::iter_swap(i, min);
    }
    
    if(nums.size() % 2 == 0){
        return *(nums.begin() + (nums.size()/2) - 1);
    }else{
        return *(nums.begin() + (nums.size()/2));
    }
    

    
}