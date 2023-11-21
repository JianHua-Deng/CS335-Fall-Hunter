#include "HalfHeapSort.hpp"
/*
Details: Before starting heapsort, take the first element in the vector (at index 0) and move it to the back of the vector. This will leave index 0 open, as per the textbook implementation.
For heapsort, you don't have to use iterators. Using array subscripts is more efficient since you'll be doing a lot of arithmetic on indexes (e.g. doubling them to find the left child, halving to find the parent).
At the end of the sort, you should have deleted elements smaller up to but not including the median - i.e. at the end of the sort, the median should be at the root of the remaining heap.
*/
int halfHeapSort (std::vector<int>& nums, int& duration){
    nums.push_back(std::move(nums[0]));//moving the first element to the end of the vector
    buildHeap(nums);

    return -1;
}

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void percDown (std::vector<int>& heap, std::vector<int>::size_type hole){


    /**/
    int child;
    int toBeInsert;
                                        //left child
    for(toBeInsert = std::move(heap[0]); hole * 2 < heap.size(); hole = child){
        child = hole * 2;//left child
        if(child != heap.size() - 1 && heap[child] > heap[child + 1]){
            child++;
        }
        if(toBeInsert > heap[child]){
            heap[hole] = std::move(heap[child]);
        }else{
            break;
        }
    }

    heap[hole] = std::move(toBeInsert);

    /*
    int left = hole * 2 + 1;//left child index
    int right = hole * 2 + 2;//right child index
    int smallest = hole; //value to be inserted into hole is stored in heap at index 0

    //if left child index is less than heap size, and left < smallest(index 0)
    if(left < heap.size() && heap[left] < heap[smallest]){
        smallest = left;
    }
    
    //if right child index is less than heap size, and right < smallest(index 0)
    if(right < heap.size() && heap[right] < heap[smallest]){
        smallest = right;
    }

    //if smallest != hole, it means we didnt find the new spot, so we swap hole and smallest, and recursively percDown again
    if(smallest != hole){
        std::swap(heap[hole], heap[smallest]);
        percDown(heap, smallest);
    }
}
    */

    /*
    int left = hole * 2 + 1;//left child index
    int right = hole * 2 + 2;//right child index
    int smallest = hole; //value to be inserted into hole is stored in heap at index 0

    //if left child index is less than heap size, and left < smallest(index 0)
    if(left < heap.size() && heap[left] < heap[0] && heap[left] < heap[right]){
        smallest = left;
    }
    
    //if right child index is less than heap size, and right < smallest(index 0)
    if(right < heap.size() && heap[right] < heap[0] && heap[right] < heap[left]){
        smallest = right;
    }

    std::cout << "Smallest: " << smallest << "\n";
    //if smallest != hole, it means we didnt find the new spot, so we swap hole and smallest, and recursively percDown again
    if(smallest != hole){
        std::swap(heap[hole], heap[smallest]);
        percDown(heap, smallest);
    }else{
        heap[hole] = std::move(heap[0]);
    }
    */
}

void buildHeap (std::vector<int>& heap){

    for(int i = heap.size()/2; i >= 1; --i){
        heap[0] = std::move(heap[i]);
        percDown(heap, i);
    }

}