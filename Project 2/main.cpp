#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
void print(std::vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << ", ";
    }
    std::cout << std::endl;
}

void printHeap(std::vector<int>& nums){
    for(int i = 1; i < nums.size(); i++){
        std::cout << nums[i] << ", ";
    }
    std::cout << std::endl;
}

int main(){

    std::vector<int> vec1 = {1, 4, 3, 78, 23, 50, 60}; // 1 3 4 23 50 60 78 90
    int duration = 0;                                  // 1 3 4 23 50 60 78
    std::vector<int> vec2 = {1, 4, 3, 78, 23, 50, 60, 90};
    std::vector<int> vec3 = {1, 4, 3, 78, 23, 50, 60, 90, 0, 60, 2, 5, 100, 154, 30, 29, 854, 395, 12, 60};
    std::vector<int> vec4 = {1, 4, 3, 78, 23, 50, 2, 9, 23, 19};
    //std::cout << "Median: "<< halfSelectionSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< standardSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< mergeSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< inPlaceMergeSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    std::cout << "Median: "<< halfHeapSort(vec4, duration) << ", Duration: " << duration <<std::endl;
    //print(vec1);
    //print(vec2);
    //print(vec3);
    printHeap(vec4);
    return 0;
}