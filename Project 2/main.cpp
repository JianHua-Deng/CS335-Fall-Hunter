#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"
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

void check(std::vector<int>& vec1, std::vector<int> vec2){
    std::string check = "Passed\n";
    if(vec1.size() != vec2.size()){
        std::cout << "Not even the Size are the same BRUH";
        std::cout << "\n" << "Vec1 Size: " << vec1.size() << ", Vec2 Size: " << vec2.size() << "\n";

    }

    for(int i = 0; i < vec1.size(); ++i){

        if(vec1[i] != vec2[i]){
            std::cout << vec1[i] << " != " << vec2[i] << "\n";
            check = "Failed\n";
        }
    }
    std::cout << check;

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
    std::vector<int> vec3 = {1, 4, 3, 78, 23, 50, 60, 90, 0, 65, 2, 5, 100, 154, 30, 29, 854, 395, 12, 60, 90};//Odd, median should be 30
    std::vector<int> vec4 = {1, 4, 3, 78, 23, 50, 2, 9, 23, 19};//Even, median should be 9
    std::vector<int> vec5 = {78, 4, 3, 78, 23, 50, 78};//testing if median of 3 work for 3 of same value, median should be 50
    std::vector<int> vec6 = {1, 4, 3, 78, 23, 50, 61, 90, 0, 65, 2, 5, 100, 154, 30, 29, 854, 395, 12, 60, 103, 632, 987, 63, 41, 9878, 662, 441, 44, 22, 99};// odd, median should be 61
    std::vector<int> vec7 = {1, 4, 3, 78, 23, 50, 61, 90, 0, 65, 2, 5, 100, 154, 30, 29, 854, 395, 12, 60, 103, 632, 987, 63, 41, 9878, 662, 441, 44, 22, 99, 237};// even, median should be 61
    std::vector<int> vec8 = {1,5,3,4,2,6,7,8,9,10};// even, median should be 61
    std::vector<int> vec9 = {1, 11, 3, 13, 5, 15, 7, 17, 9, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    std::vector<int>& worse = worstCaseQuickSelect();

    std::vector<int> inputVec1 = readFile("input1.txt");
    std::vector<int> inputVec4 = readFile("input4.txt");
    std::vector<int> inputVec9 = readFile("input9.txt");
    std::vector<int> selectVec1Check = readFile("selectionsort1.txt");
    std::vector<int> selectVec4Check = readFile("selectionsort4.txt");
    std::vector<int> heapVec1Check = readFile("heapsort1.txt");
    std::vector<int> heapVec4Check = readFile("heapsort4.txt");
    std::vector<int> quickSelectVec1Check = readFile("quickselect1.txt");
    std::vector<int> quickSelectVec4Check = readFile("quickselect4.txt");


    //std::cout << "Median: "<< halfSelectionSort(vec3, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< standardSort(vec7, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< mergeSort(inputVec9, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< inPlaceMergeSort(inputVec9, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< halfHeapSort(vec7, duration) << ", Duration: " << duration <<std::endl;
    std::cout << "Median: "<< quickSelect(worse, duration) << ", Duration: " << duration <<std::endl;
    

    //std::cout << "Median: "<< halfHeapSort(inputVec9, duration) << ", Duration: " << duration <<std::endl;// IT SEEMS TO WORK YAYYYY
    //std::cout << "Median: "<< quickSelect(inputVec9, duration) << ", Duration: " << duration <<std::endl;
    //std::cout << "Median: "<< halfSelectionSort(inputVec9, duration) << ", Duration: " << duration <<std::endl;


    
    //print(vec1);
    //print(vec2);
    //print(vec4);
    //print(vec3);
    //print(vec3);
    //print(vec7);
    //print(vec8);
    //print(vec9);
    //print(worse);
    //print(inputVec1);
    
    //print(inputVec4);

    //std::cout << check(heapVec1Check, heapVec1After) << "\n";

    
    //print(inputVec1);
    //check(inputVec1, quickSelectVec1Check);
    //check(inputVec4, heapVec4Check);
    //printHeap(vec3);
    //check(inputVec4, selectVec4Check);
    return 0;
}