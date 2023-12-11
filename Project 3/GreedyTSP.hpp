#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <fstream>

class Node{
    private:
    double x;
    double y;
    int id;

    public:

    Node(){
        this->x = 0;
        this->y = 0;
    }
    
    Node(double input1, double input2, int id){
        this->x = input1;
        this->y = input2;
        this->id = id;
    }

    int distance(double x2, double y2){
        return std::sqrt(std::pow(x2 - (this->x), 2) + std::pow(y2 - (this->y), 2)) + 0.5;//distance formula
    }

    double getX() const{
        return this->x;
    }

    double getY() const{
        return this->y;
    }

    int getId() const{
        return this->id;
    }
};

struct Edge{
    
}

