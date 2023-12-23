#pragma once
#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int>& worstCaseQuickSelect(){
    //such that the pivot we selected should always be 1 more than the smallest
    int size = 20000;
    int halfsize = (size)/2;
    static std::vector<int> worse(size);
    std::vector<int>::iterator start = worse.begin();
    std::vector<int>::iterator center = worse.begin() + halfsize;
    std::vector<int>::iterator end = worse.end() - 1;
    
  

    for(int i = 0; i < halfsize; ++i){
    //the latter half of the vector will be all even numbers, alternating from values that i(even index) + 1 or halfsize + i, this is such so it is always odd and that it always pick the second largest
        if(i % 2 == 0){
            *(center + i) = i + 1;
        }else{
            *(center + i) = halfsize + i;
        }
        *(start + i) = (i + 1) * 2;//the latter half will be all odds
    }

    return worse;
}

