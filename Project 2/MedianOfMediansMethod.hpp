#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

std::vector<int>::iterator medianof4(std::vector<int>::iterator low, std::vector<int>::iterator high){
    std::vector<int>::iterator loser1;
    std::vector<int>::iterator loser2;
    std::vector<int>::iterator loser3;
    std::vector<int>::iterator lesser1;
    std::vector<int>::iterator lesser2;
    std::vector<int>::iterator winner1;
    std::vector<int>::iterator winner2;

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
        winner1 = lesser1;
        loser3 = lesser2;
    }else{
        winner1 = lesser2;
        loser3 = lesser1;
    }

    if(*loser3 < *loser2){
        winner2 = loser3;
    }else{
        winner2 = loser2;
    }

    if(*winner2 < *loser1){
        return winner2;
    }else{
        return loser1;
    }

}

//return iterator at high, which will be the pivot
std::vector<int>::iterator medianof3 (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){

    std::vector<int>::iterator center = low;

    std::advance(center, std::distance(low, high) / 2);//moving iterator center to point to the middle value of the list

    //std::cout << "LOW: " << *low << ", CENTER: " << *center << ", HIGH: " << *high << ", ";
 

    if((*low < *center && *center < *high) || (*high < *center && *center < *low )){

        return center;
        //std::iter_swap(center, high);//center should be the pivot

    }else if((*center < *low  && *low < *high) || (*high < *low && *low < *center)){

        return low;
        //std::iter_swap(low, high);//low should be the pivot

    }else{

        return high;//high should be the pivot
    }


    //return high;

}

std::vector<int>::iterator medianOfFive(std::vector<int>::iterator low, std::vector<int>::iterator high){
    //I know these are extra and may cause slow downs, but I wanted to visualize so its easier to read this way
    std::vector<int>::iterator greater1;
    std::vector<int>::iterator greater2;
    std::vector<int>::iterator winner1;
    std::vector<int>::iterator winner2;
    std::vector<int>::iterator winner3;
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

    if(*a > *b){//1st comparison
        greater1 = a;
        loser1 = b;
    }else{
        greater1 = b;
        loser1 = a;
    }

    if(*c > *d){//2nd comparisons
        greater2 = c;
        loser2 = d;
    }else{
        greater2 = d;
        loser2 = c;
    }

    if(*greater1 > *greater2){//3rd comparisons

        loser3 = greater2;
        loserofGreatest = loser1;
        loserofloser = loser2;
        
    }else{

        loser3 = greater1;
        loserofGreatest = loser2;
        loserofloser = loser1;

    }

    if(*loserofGreatest > *e){//4th comparisons
        winner2 = loserofGreatest;
        loser4 = e;
    }else{
        winner2 = e;
        loser4 = loserofGreatest;
    }
    std::cout << "Winner: " << *winner2 << "| Loser3: " << *loser3 << "\n"; 
    if(*winner2 > *loser3){//5th comparisons
        
        winner3 = winner2;
        loser5 = loser3;
    }else{
        
        winner3 = loser3;
        loser5 = winner2;
    }
    std::cout << "Winner: " << *winner3 << "| LoserofLoser: " << *loserofloser << "\n"; 
    if(*loser5 > *loserofloser){//6th comparisons
        //std::cout << "Its HERE!" << "\n";
        return loser5;
    }else{
        //std::cout << "Its HERE LOSER!" << "\n";
        return loserofloser;
    }


}

int medianOfMedians ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high ){
    if(nums.size() <= 24){
        std::sort(low, high + 1);
        for(int i = 0; i < nums.size(); ++i){
            std::cout << nums[i] << ",";
        }
        std::cout << "\n";
        return *(low + std::distance(low, high)/2);
    }
    std::vector<int> medians;
    std::vector<int>::iterator it = low;
    for(; it + 5 < high + 1; it = it + 5){//it + 5 will be the start of next 5 
        medians.push_back(*medianOfFive(it, it + 4));//it + 4 will be the end of the current groups of 5
    }

    if(std::distance(it, high) == 3){//when there's 3 element left
        medians.push_back(*medianof3(nums, it, high));
    }else if(std::distance(it, high) == 4){//when there's 4 element left
        medians.push_back(*medianof4(it, high));
    }

    return medianOfMedians(medians, medians.begin(), medians.end() - 1);

}

std::vector<int>::iterator hoarePartition (std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high){
    
    std::vector<int>::iterator pivot = medianof3(nums, low, high);// return the pivot iterator, which is at high - 1
    //std::cout << "Pivot: " << *pivot << "\n";
    std::vector<int>::iterator left = low;
    std::vector<int>::iterator right = pivot - 1; //high is the position of pivot, and high - 1 will be the right start of our partitioning
    //std::cout << "\n" <<"Pivot: " << *pivot << "\n";

    ///*
    while(true){
        while(left < pivot && *left < *pivot){
            ++left;
        }
        while(right > low && *right > *pivot){
            --right;
        }
        //std::cout << "Pivot: " << *pivot << " Left: " << *left << " Right: " << *right << "\n";
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

int quickSelect (std::vector<int>& nums, int& duration){
    auto start = std::chrono::steady_clock::now();

    quickSelect(nums, nums.begin(), nums.end() - 1, nums.begin() + (nums.size() - 1)/2);

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return *(nums.begin() + (nums.size() - 1)/2);//returning the middle element as the pivot
}

