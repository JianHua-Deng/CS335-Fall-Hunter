#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

//return iterator at high, which will be the pivot
std::vector<int>::iterator medianof3 (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){

    std::vector<int>::iterator center = low;

    std::advance(center, std::distance(low, high) / 2);//moving iterator center to point to the middle value of the list
 
    if((*low == *center && *low == *high) || *low == *center || *low == *high){//if all 3 values are equal OR low and center are same value OR low and high has the same value

        std::iter_swap(low, high);   

    }else if(*center == *high){// if middle and right most has the same value
    
        std::iter_swap(center, high);

    }else{

        if((*low < *center && *center < *high) || (*high < *center && *center < *low )){

            std::iter_swap(center, high);//center should be the pivot

        }else if((*center < *low  && *low < *high) || (*high < *low && *low < *center)){

            std::iter_swap(low, high);//low should be the pivot

        }else{

            return high;//high should be the pivot
        }

    }

    return high;

}

std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){

    std::vector<int>::iterator pivot = medianof3(nums, low, high);// return the pivot iterator, which is at high - 1
    std::vector<int>::iterator left = low;
    std::vector<int>::iterator right = pivot - 1; //high is the position of pivot, and high - 1 will be the right start of our partitioning

    while(true){
        while(left < pivot && *left < *pivot){
            ++left;
        }
        while(right > low && *right > *pivot){
            --right;
        }
        if(left >= right){
            break;
        }
        std::iter_swap(left, right);
        ++left;
        --right;
        
    }

    std::iter_swap(left, pivot);

    return left;    
    

    
}

void quickSelect (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator center){
    //!(low + 9 <= high)
    if(high <= low + 9){//if low + 9 is greater than or equals to high, meaning the range from low to high has less than or equal to 10 element
        std::sort(low, high + 1);
        return;
    }

    std::vector<int>::iterator median = hoarePartition(nums, low, high);

    if(median == center){//base case
        return;
    }else if (median < center){
        quickSelect(nums, median + 1, high, center);
    }else{
        quickSelect(nums, low, median - 1, center);
    }
}

int quickSelect (std::vector<int>& nums, int& duration){
    auto start = std::chrono::steady_clock::now();

    quickSelect(nums, nums.begin(), nums.end() - 1, nums.begin() + (nums.size() - 1)/2);

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return *(nums.begin() + (nums.size() - 1)/2);//returning the middle element as the pivot
}



