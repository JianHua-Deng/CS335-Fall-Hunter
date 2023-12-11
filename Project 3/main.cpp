#include "NearestNeighbor.hpp"
#include "GreedyTSP.hpp"
void print(std::vector<Node> list){
    for(std::vector<Node>::iterator it = list.begin(); it != list.end(); ++it){
        std::cout << "X: " << it->getX() << ", Y: " << it->getY() << std::endl;
    }
}
int main(){

    
    nearestNeighbor("dj38.tsp");



    return 0;
}