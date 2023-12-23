#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <fstream>
#include <chrono>

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
    
    //Need to skip till we find where the data is actually located
    std::string junk;
    while(inputs >> junk ){
        if(junk == "NODE_COORD_SECTION"){
            break;
        }
    }

    int id;
    double x, y;
    while(inputs >> id >> x >> y){
        linkedlist.push_back(Node(x, y, id));            
    }
}

void nearestNeighbor (std::string filename){
    int duration = 0;
    
    std::list<Node> unvisited;
    std::list<Node> visited;
    int distance = 0;
    double min;
    std::list<Node>::iterator toRemove;
    
    readFile(unvisited, filename);


    auto start = std::chrono::steady_clock::now();//Start here because creating the lists aren't really part of the computations

    //making the first node in the unvisited list to be the starting point
    Node current = unvisited.front();
    unvisited.pop_front();
    visited.push_back(current);

    
    while(!(unvisited.empty())){
        //Iterate through the list to find the minimal distance 
        for(std::list<Node>::iterator it = unvisited.begin(); it != unvisited.end(); ++it){
            if(it == unvisited.begin()){//if it is at the first element, at this state, min and toRemove has nothing, hence we need to set it
                min = it->distance(current.getX(), current.getY());
                toRemove = it;
            }else{
                //if theres a distance smaller than min, change min to the new distance and toRemove to that of the smaller's iterator
                if(min > it->distance(current.getX(), current.getY())){
                min = it ->distance(current.getX(), current.getY());
                toRemove = it;
                }
            }
        }
        //remove the smallest from the unvisited list and add it to visited, and then sum up the distance
        current = *toRemove;
        distance += min;
        visited.push_back(current);
        unvisited.erase(toRemove);
        
    }
    distance += visited.front().distance(current.getX(), current.getY());// manually re adding the distance of the current node to the original node
    visited.push_back(visited.front());//mannually make the tour back to original by adding the original(at index 0) to the back of the list

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    //printing them out
    for(Node n : visited){
        std::cout << n.getId() << " ";
    }

    std::cout << std::endl << "Total Distance: " << distance << std::endl << "Time in ms: " << duration << std::endl;     
}



    