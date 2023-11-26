#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
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

    int duration = 0;
    std::vector<int> vec1 = {1, 4, 3, 78, 23, 50, 60}; //Odd, Median should be 23
    std::vector<int> vec2 = {1, 4, 3, 78, 23, 50, 60, 90};//Even, Median should be 23
    std::vector<int> vec3 = {1, 4, 3, 78, 23, 50, 60, 90, 0, 60, 2, 5, 100, 154, 30, 29, 854, 395, 12, 60};//Odd, median should be 30
    std::vector<int> vec4 = {1, 4, 3, 78, 23, 50, 2, 9, 23, 19};//Even, median should be 9
    std::vector<int> vec5 = {78, 4, 3, 78, 23, 50, 78};//testing if median of 3 work for 3 of same value, median should be 50

    //std::cout << "Median: "<< halfSelectionSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< standardSort(vec2, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< mergeSort(vec2, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< inPlaceMergeSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< halfHeapSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    std::cout << "Median: "<< quickSelect(vec1, duration) << ", Duration: " << duration <<std::endl;
    //print(vec1);
    //print(vec2);
    //print(vec4);
    //print(vec3);
    print(vec1);
    //printHeap(vec3);
    return 0;
}