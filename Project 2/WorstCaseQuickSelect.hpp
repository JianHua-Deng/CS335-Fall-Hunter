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
        if(i % 2 == 0){
            *(center + i) = i + 1;
        }else{
            *(center + i) = halfsize + i;
        }
        *(start + i) = (i + 1) * 2;
    }

    return worse;
}

