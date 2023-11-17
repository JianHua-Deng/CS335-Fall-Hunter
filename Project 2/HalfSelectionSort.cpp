#include "HalfSelectionSort.hpp"

int halfSelectionSort (std::vector<int>& nums, int& duration){
    if(nums.size() > 50000){
        throw std::runtime_error("Vector size too large");
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
    
    return *(i-1);//returning (i-1) because i is pointing 1 head of the median after the for loop ended
    
}