#include "WorstCaseQuickSelect.hpp"

std::vector<int>& worstCaseQuickSelect(){
    //such that the pivot we selected should always be 1 more than the smallest
    std::vector<int> worse;
    for(int i = 1; i <= 20000; i++){
        worse.push_back(i);
    }

    std::random_shuffle(worse.begin(), worse.end());

    return worse;
}

