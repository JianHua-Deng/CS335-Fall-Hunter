#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

/*
//return the iterator of a number in the vector
std::vector<int>::iterator search(std::vector<int>::iterator start, std::vector<int>::iterator end, int value){
    std::vector<int>::iterator it = start;
    for(; it != end + 1; ++it){
        if(*it == value){
            return it;
        }
    }
    it = start + 1;
    return it;
}

void swapforworse(std::vector<int>::iterator start, std::vector<int>::iterator median, std::vector<int>::iterator end, int size, std::vector<int>& nums){
    if(size <= 3){
        return;
    }

    std::vector<int>::iterator center = start;
    std::advance(center, std::distance(start, end) / 2);//moving center to middle
    std::vector<int>::iterator nextBigger = find(start, end, *(start) + 1);// finding one bigger the the leftmost

    std::iter_swap(center, nextBigger);

    if(*center < *median){//gonna recurse on the right side
        swapforworse(start + *center , median, end, size/2, nums);
    }else{
        swapforworse(start, median, end - *center, size/2, nums);
    }
}

*/

std::vector<int>& worstCaseQuickSelect(){
    //such that the pivot we selected should always be 1 more than the smallest
    int size = 20000;
    int halfsize = (size - 1)/2;
    static std::vector<int> worse(size);
    std::vector<int>::iterator start = worse.begin();
    std::vector<int>::iterator center = worse.begin() + halfsize;
    std::vector<int>::iterator end = worse.end() - 1;

    
    /*
    for(int i = 1; i <= size; i++){
        worse[i - 1] = i;
    }
    */
    
    *(end) = size;
    *(end - 1) = size - 1;
    
    for(int i = 0; i < halfsize; ++i){
        if(i % 2 == 0){
            *(start + i) = i + 1;
        }else{
            *(start + i) = halfsize + i + 1;
        }
        *(center + i) = (i + 1) * 2;
    }
    
    //std::random_shuffle(worse.begin(), worse.end());


    //std::vector<int>::iterator center = worse.begin() + (worse.size() - 1)/2;

    //swapforworse(start, median, end, size);

    

    //std::random_shuffle(worse.begin(), worse.end());
    
    //std::swap(worse[(worse.size() - 1)/2], worse[1]);
    return worse;
}

