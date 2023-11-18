#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
void print(std::vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << ", ";
    }
    std::cout << std::endl;
}

int main(){

    std::vector<int> vec1 = {1, 4, 3, 78, 23, 50, 60}; // 1 3 4 23 50 60 78 90
    int duration = 0;                                  // 1 3 4 23 50 60 78
    std::vector<int> vec2 = {1, 4, 3, 78, 23, 50, 60, 90};
    //std::cout << halfSelectionSort(vec1, duration) << std::endl;
    std::cout << standardSort(vec2, duration) << std::endl;
    print(vec2);
    //print(vec2);
    return 0;
}