#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
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
    std::vector<int> vec3 = {1, 4, 3, 78, 23, 50, 60, 90, 0, 60, 2, 5, 100, 154, 30, 34};
    //std::cout << halfSelectionSort(vec1, duration) << std::endl;
    //std::cout << standardSort(vec2, duration) << std::endl;
    std::cout << mergeSort(vec3, duration) << std::endl;
    //print(vec1);
    //print(vec2);
    print(vec3);
    return 0;
}