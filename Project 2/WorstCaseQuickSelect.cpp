#include "WorstCaseQuickSelect.hpp"

std::vector<int>& worstCaseQuickSelect(){
    //such that the pivot we selected should always be 1 more than the smallest
    std::vector<int> worse;
    for(int i = 0; i < 20000; i++){
        int value = std::rand() % 20000;
        worse.push_back(i);
    }

    return worse;
}

