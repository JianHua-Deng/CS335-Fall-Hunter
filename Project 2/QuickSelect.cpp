#include "QuickSelect.hpp"

int quickSelect (std::vector<int>& nums, int& duration){

    quickSelect(nums, nums.begin(), nums.end() - 1, nums.begin() + (nums.size() - 1)/2);

    return *(nums.begin() + (nums.size() - 1)/2);
}

void quickSelect (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator center){

    if(!(low + 9 <= high)){//if the range contains more than 10 elements
        std::sort(low, high);
        return;
    }

    std::advance(center, std::distance(low, high) / 2);

    std::vector<int>::iterator median = hoarePartition(nums, low, high);

    if(median == center){
        return;
    }else if (median < center){
        quickSelect(nums, median + 1, high, center);
    }else{
        quickSelect(nums, low, median - 1, center);
    }
}

std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){

    std::vector<int>::iterator left = low;
    std::vector<int>::iterator right = high - 1;
    std::vector<int>::iterator pivot = medianof3(nums, low, high);
        
    while(left <= right){
        while(left + 1 <= high && *left < *pivot){
            ++left;
        }
        while(low <= right - 1 && *right > *pivot){
            --right;
        }
        std::iter_swap(left, right);
    }
    std::iter_swap(left, pivot);
    
    return left;
    
}

std::vector<int>::iterator medianof3 (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){

    std::vector<int>::iterator center = low;
    std::advance(center, std::distance(low, high) / 2);//moving iterator center to point to the middle value of the list
    
    
    if(*low == *center && *low == *high){//if all 3 values are equal

        std::iter_swap(low, high - 1);   

    }else{

        if(*center < *low){
            std::iter_swap(low, center);
        }
        if(*high < *low){
            std::iter_swap(low, high);
        }
        if(*high < *center){
            std::iter_swap(center, high);
        }
        std::iter_swap(center, high - 1);       
    }
    return high - 1;  
}

