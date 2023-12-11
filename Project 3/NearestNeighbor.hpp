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

void readFile(std::list<Node>& linkedlist, std::string filename){
    std::ifstream inputs(filename);
    if(!inputs){
        std::cout << "Failed to read Files" << std::endl;
        return;
    }
    
    //Need to skip 7 lines first
    std::string junk;
    while(junk != "NODE_COORD_SECTION"){
        std::getline(inputs, junk);
        //std::cout << junk << "\n";
    }

    int placeholder;
    double x, y;
    while(inputs >> placeholder){

        if(inputs >> x >> y){
            //std::cout << placeholder << " " << x << " " << y << std::endl;
            //Node *n = new Node(std::stod(x), std::stod(y));
            linkedlist.push_back(Node(x, y, placeholder));            
        }
        
    }
}

void nearestNeighbor (std::string filename){
    std::list<Node> unvisited;
    std::list<Node> visited;
    int distance = 0;
    double min;
    std::list<Node>::iterator toRemove;
    readFile(unvisited, filename);

    //making the first unvisited to be the starting point
    Node current = unvisited.front();
    //std::cout << unvisited.size() << "\n";
    unvisited.pop_front();
    visited.push_back(current);

    
    
    while(!(unvisited.empty())){
        //std::cout << "X: " << current.getX() << "Y: " << current.getY() << std::endl;
        for(std::list<Node>::iterator it = unvisited.begin(); it != unvisited.end(); ++it){
            if(it == unvisited.begin()){
                min = it->distance(current.getX(), current.getY());
                toRemove = it;
                
            }else{
                if(min > it->distance(current.getX(), current.getY())){
                min = it ->distance(current.getX(), current.getY());
                toRemove = it;
                }
            }
        }
        current = *toRemove;
        distance += min;
        visited.push_back(current);
        unvisited.erase(toRemove);
        
    }
    distance += visited.front().distance(current.getX(), current.getY());// re adding the current distance, back the the original
    visited.push_back(visited.front());//mannually make the tour back to original
    /*
    for(std::list<Node>::iterator it = visited.begin(); it != visited.end(); ++it){
        std::cout << "ID: " << it->getId()<< ", X: " << it->getX() << ", Y: " << it->getY() << std::endl;
    }
    */
    std::cout << "Distance: " << distance << std::endl;     
}
