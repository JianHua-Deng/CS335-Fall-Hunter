#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include <fstream>

std::vector<int> readFile(std::string file){
    std::vector<int> values;
    std::ifstream inputs(file);

    std::string number;
    while(inputs >> number){
        values.push_back(std::stoi(number));
    }
    return values;
}

std::string check(std::vector<int>& vec1, std::vector<int> vec2){
    if(vec1.size() != vec2.size()){
        return "Not even the Size are the same BRUH";
    }

    for(int i = 0; i < vec1.size(); ++i){

        if(vec1[i] != vec2[i]){
            return "False";
        }
    }
    return "True";
}

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
    std::vector<int> vec3 = {1, 4, 3, 78, 23, 50, 60, 90, 0, 65, 2, 5, 100, 154, 30, 29, 854, 395, 12, 60};//Odd, median should be 30
    std::vector<int> vec4 = {1, 4, 3, 78, 23, 50, 2, 9, 23, 19};//Even, median should be 9
    std::vector<int> vec5 = {78, 4, 3, 78, 23, 50, 78};//testing if median of 3 work for 3 of same value, median should be 50
    std::vector<int> vec6 = {1, 4, 3, 78, 23, 50, 61, 90, 0, 65, 2, 5, 100, 154, 30, 29, 854, 395, 12, 60, 103, 632, 987, 63, 41, 9878, 662, 441, 44, 22, 99};// odd, median should be 61
    std::vector<int> vec7 = {1, 4, 3, 78, 23, 50, 61, 90, 0, 65, 2, 5, 100, 154, 30, 29, 854, 395, 12, 60, 103, 632, 987, 63, 41, 9878, 662, 441, 44, 22, 99, 237};// even, median should be 61
    std::vector<int> inputVec1 = readFile("input1.txt");
    std::vector<int> heapVec1Check = readFile("heapsort1.txt");
    std::vector<int> quickSelectVec1Check = readFile("quickselect1.txt");


    //std::cout << "Median: "<< halfSelectionSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< standardSort(vec7, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< mergeSort(vec2, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< inPlaceMergeSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< halfHeapSort(vec7, duration) << ", Duration: " << duration <<std::endl;
    std::cout << "Median: "<< quickSelect(vec7, duration) << ", Duration: " << duration <<std::endl;

    //std::cout << "Median: "<< halfHeapSort(inputVec1, duration) << ", Duration: " << duration <<std::endl;// IT SEEMS TO WORK YAYYYY
    //std::cout << "Median: "<< quickSelect(inputVec1, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< halfSelectionSort(inputVec1, duration) << ", Duration: " << duration <<std::endl;


    
    //print(vec1);
    //print(vec2);
    //print(vec4);
    //print(vec3);
    //print(vec3);
    print(vec7);
    //print(inputVec1);

    //std::cout << check(heapVec1Check, heapVec1After) << "\n";

    //print(inputVec1);
    //printHeap(vec3);
    return 0;
}