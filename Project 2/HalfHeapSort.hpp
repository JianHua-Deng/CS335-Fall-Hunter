#pragma once
#include <iostream>
#include <vector>
#include <chrono>
/*
Details: Before starting heapsort, take the first element in the vector (at index 0) and move it to the back of the vector. This will leave index 0 open, as per the textbook implementation.
For heapsort, you don't have to use iterators. Using array subscripts is more efficient since you'll be doing a lot of arithmetic on indexes (e.g. doubling them to find the left child, halving to find the parent).
At the end of the sort, you should have deleted elements smaller up to but not including the median - i.e. at the end of the sort, the median should be at the root of the remaining heap.
*/
// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown (std::vector<int>& heap, std::vector<int>::size_type hole){
    
    int child;
    int toBeInsert;

    //textbook implementation
    //Swapping the hole with either right child or left child based on which is lesser
                                        //left child
    for(toBeInsert = std::move(heap[0]); hole * 2 < heap.size(); hole = child){
        child = hole * 2;//left child
        if(child != heap.size() - 1 && heap[child] > heap[child + 1]){//comparing left child with right child
            child++;
        }
        if(toBeInsert > heap[child]){//comparing the lesser child with the toBeInsert value to see which is lesser, if toBeInser is lesser, that mean we found the spot
            heap[hole] = std::move(heap[child]);
        }else{
            break;
        }
    }

    heap[hole] = std::move(toBeInsert);

}

void buildHeap (std::vector<int>& heap){
    //Due to the fact that size() / 2 - 1 are only for the case when our heap starts at index 0
    //In our case where indexes starts at 1, we need to use size() / 2
    for(int i = heap.size()/2; i > 0; --i){
        heap[0] = std::move(heap[i]);//moving the value to the 0 index, as this is the pre condition for percDown
        percDown(heap, i);
    }

}

int halfHeapSort (std::vector<int>& nums, int& duration){

    auto start = std::chrono::steady_clock::now();
    
    nums.push_back(std::move(nums[0]));//moving the first element to the end of the vector
    buildHeap(nums);

    /*
    size - 1 is the actual size of array that contains the actual content we need, because value at index 0 is a placeholder
    Check if the size is even or odd, if it's even, we are taking the lesser of the two middle element, thus we subtract 1 again
    */
    int half = (nums.size() - 2)/2;
    

    for(int i = 0; i < half; i++){

        nums[0] = std::move(nums[nums.size() - 1]);//moving the end element to index 0 and then erase the end element
        nums.erase(std::prev(nums.end()));
    
        percDown(nums, 1);
    }

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    return nums[1];
}

