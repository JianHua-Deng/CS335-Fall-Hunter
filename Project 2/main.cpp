#include "HalfSelectionSort.hpp"

int main(){

    std::vector<int> vec1 = {1, 4, 3, 78, 23, 50, 60, 90}; // 1 3 4 23 50 60 78 90
    int duration = 0;                                      // 1 3 4 23 50 60 78

    std::cout << halfSelectionSort(vec1, duration) << std::endl;

    for(int i = 0; i < vec1.size(); i++){
        std::cout << vec1[i] << ", ";
    }
    std::cout << "\n";
    return 0;
}