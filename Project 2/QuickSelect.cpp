#include "QuickSelect.hpp"

int quickSelect (std::vector<int>& nums, int& duration){
    auto start = std::chrono::steady_clock::now();

    quickSelect(nums, nums.begin(), nums.end() - 1, nums.begin() + (nums.size() - 1)/2);

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    return *(nums.begin() + (nums.size() - 1)/2);
}

void quickSelect (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator center){

    if(!(low + 9 <= high)){//if the range contains less than 10 elements
        std::sort(low, high);
        return;
    }

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

    std::vector<int>::iterator pivot = medianof3(nums, low, high);
    std::vector<int>::iterator left = low;
    std::vector<int>::iterator right = high - 2; //high - 1 is the position of pivot, and high - 2 will be the start of our partitioning
    
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
    /*
    while(true){
        while(*left < *pivot){
            ++left;
        }
        while(*right > *pivot){
            --right;
        }
        if(left >= right){
            break;
        }
        std::iter_swap(left, right);
    }
    std::iter_swap(left, pivot);
    
    return left;    
    */

    
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

