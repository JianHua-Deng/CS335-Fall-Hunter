#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

//assuming the range between low and high only consists of 4 elements
std::vector<int>::iterator medianof4(std::vector<int>::iterator low, std::vector<int>::iterator high){
    std::vector<int>::iterator loser1;
    std::vector<int>::iterator loser2;
    std::vector<int>::iterator loser3;
    std::vector<int>::iterator lesser1;
    std::vector<int>::iterator lesser2;
    std::vector<int>::iterator lesser3;

    //pretty much the same idea as median of 5 except we do lesser comparisons
    if(*low < *(low+1)){
        lesser1 = low;
        loser1 = low+1;
    }else{
        lesser1 = low+1;
        loser1 = low;
    }

    if(*(low + 2) < *(low + 3)){
        lesser2 = low+2;
        loser2 = low+3;
    }else{
        lesser2 = low+3;
        loser2 = low+2;
    }

    if(*lesser1 < *lesser2){
        loser3 = lesser2;
    }else{
        loser3 = lesser1;
    }

    if(*loser1 < *loser2){
        lesser3 = loser1;
    }else{
        lesser3 = loser2;
    }

    if(*loser3 < *lesser3){
        return loser3;
    }else{
        return lesser3;
    }

}

//return iterator at high, which will be the pivot
std::vector<int>::iterator medianof3 (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){

    std::vector<int>::iterator center = low;

    std::advance(center, std::distance(low, high) / 2);//moving iterator center to point to the middle value of the list

 

    if((*low < *center && *center < *high) || (*high < *center && *center < *low )){

        return center;

    }else if((*center < *low  && *low < *high) || (*high < *low && *low < *center)){

        return low;

    }else{

        return high;//high should be the pivot
    }


    //return high;

}

std::vector<int>::iterator medianOfFive(std::vector<int>::iterator low, std::vector<int>::iterator high){

    //I know these may be extras and will cause slow downs, but I wanted to visualize so its easier to read this way
    std::vector<int>::iterator greater1;
    std::vector<int>::iterator greater2;
    std::vector<int>::iterator winner1;
    std::vector<int>::iterator loserofGreatest;
    std::vector<int>::iterator loserofloser;
    std::vector<int>::iterator loser1;
    std::vector<int>::iterator loser2;
    std::vector<int>::iterator loser3;
    std::vector<int>::iterator loser4;
    std::vector<int>::iterator loser5;

    std::vector<int>::iterator a = low;
    std::vector<int>::iterator b = low + 1;
    std::vector<int>::iterator c = low + 2;
    std::vector<int>::iterator d = low + 3;
    std::vector<int>::iterator e = low + 4;

    if(*a > *b){//1st comparison, comparing first group
        greater1 = a;
        loser1 = b;
    }else{
        greater1 = b;
        loser1 = a;
    }

    if(*c > *d){//2nd comparisons, comparing second group
        greater2 = c;
        loser2 = d;
    }else{
        greater2 = d;
        loser2 = c;
    }

    if(*greater1 > *greater2){//3rd comparisons, compare to the greater of the two groups

        loser3 = greater2;
        loserofGreatest = loser1;
        loserofloser = loser2;
        
    }else{

        loser3 = greater1;
        loserofGreatest = loser2;
        loserofloser = loser1;

    }

    if(*loserofGreatest > *e){//4th comparisons, comparing the value who originally compared to the greatest of all during the 1st comparison with e
        winner1 = loserofGreatest;
        loser4 = e;
    }else{
        winner1 = e;
        loser4 = loserofGreatest;
    }

    if(*winner1 > *loser3){//5th comparisons, comparing the loser of the 3rd comparison to the winner of 4th comparison
        loser5 = loser3;
    }else{
        loser5 = winner1;
    }
    
    if(*loser5 > *loserofloser){//6th comparisons, loser of 5th comparison will now compare to the loser of loser(which are the smaller value who compared to the loser of the 3rd comparison)
        return loser5;
    }else{
        return loserofloser;
    }


}

int medianOfMedians ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ){
    if(nums.size() <= 24){
        std::sort(low, high + 1);  
        return *(low + std::distance(low, high)/2);
        
    }
    std::vector<int> medians;
    std::vector<int>::iterator it = low;
    for(; it + 5 < high + 1; it = it + 5){//it + 5 will be the start of next 5 
        medians.push_back(*medianOfFive(it, it + 4));//it + 4 will be the end of the current groups of 5
    }

    if(std::distance(it, high + 1) == 3){//when there's 3 element left
        medians.push_back(*medianof3(nums, it, high));
    }else if(std::distance(it, high + 1) == 4){//when there's 4 element left
        medians.push_back(*medianof4(it, high));
    }
    

    return medianOfMedians(medians, medians.begin(), medians.end() - 1);

}

std::vector<int>::iterator find(std::vector<int>& nums, int value, std::vector<int>::iterator low, std::vector<int>::iterator high){
    while(low != high + 1){
        if(*low == value){
            return low;
        }
        ++low;
    }
    std::cout << "Something went WRONG!!!" << "\n";
    return low;
}

std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){
    int pivotValue = medianOfMedians(nums, low, high);
    std::vector<int>::iterator pivot = find(nums, pivotValue, low, high);// return the pivot iterator, which is at high - 1
    std::iter_swap(pivot, high);
    pivot = high;//iter_swap only swaps the value, hence, the iterator pivot itself is no longer pointing at where the pivot is

    std::vector<int>::iterator left = low;
    std::vector<int>::iterator right = pivot - 1; //high is the position of pivot, and high - 1 will be the right start of our partitioning

    ///*
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
    //*/
    std::iter_swap(left, pivot);

    return left;    
    

    
}

void quickSelect (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator center){
    //!(low + 9 <= high)
    if(high <= low + 9){//if low + 9 is greater than or equals to high, meaning the range from low to high has less than or equal to 10 element
        std::sort(low, high + 1);
        //std::cout << "It stops here, at Sort" << "\n";
        return;
    }

    std::vector<int>::iterator median = hoarePartition(nums, low, high);

    if(median == center){
        //std::cout << "It stoppes here" << "\n";
        return;
    }else if (median < center){
        quickSelect(nums, median + 1, high, center);
    }else{
        quickSelect(nums, low, median - 1, center);
    }
}

int medianOfMediansMethod ( std::vector<int>& nums, int& duration ){
    auto start = std::chrono::steady_clock::now();

    quickSelect(nums, nums.begin(), nums.end() - 1, nums.begin() + (nums.size() - 1)/2);

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return *(nums.begin() + (nums.size() - 1)/2);//returning the middle element as the pivot
}

