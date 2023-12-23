#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>
#include <queue>
#include <fstream>

class Node{
    private:
        double x;
        double y;
        int id;
        Node* nodeA;
        Node* nodeB;

    public:

        Node(){
            this->x = 0;
            this->y = 0;
            this->nodeA = nullptr;
            this->nodeB = nullptr;
        }

        
        Node(double input1, double input2, int id){
            this->x = input1;
            this->y = input2;
            this->id = id;
            this->nodeA = nullptr;
            this->nodeB = nullptr;
        }

        ~Node(){
            //Since we are going to delete it each node in Nodelist anyway, thus, this is to prevent double free seg fault 
            this->nodeA = nullptr;
            this->nodeB = nullptr;
        }


        int distance(double x2, double y2){
            return std::sqrt(std::pow(x2 - (this->x), 2) + std::pow(y2 - (this->y), 2)) + 0.5;//distance formula, and +0.5 for rounding
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

        void setNodeA(Node* node1){
            this->nodeA = node1;
        }

        void setNodeB(Node* node2){
            this->nodeB = node2;
        }
        Node* getNodeA() const{
            return this->nodeA;
        }

        Node* getNodeB() const{
            return this->nodeB;
        }

        //return the node that is pointing towards nullptr
        Node* returnNoneEmpty(){
            if(this->nodeB == nullptr){
                return nodeA;
            }else{
                return nodeB;
            }
        }

        //return true if nodeA or nodeB is nullptr
        bool isCompleteEmpty(){
            return (this->nodeA == nullptr && this->nodeB == nullptr);
        }

        //if both pointer in this node is NOT nullptr
        bool occupied(){
            return(this->nodeA != nullptr && this->nodeB != nullptr);
        }

        //return true if nodeA or nodeB is nullptr
        bool isEmpty(){
            return (this->nodeA == nullptr || this->nodeB == nullptr);
        }        
};

class Edge{
    private:
        int weight;
        Node* nodeA;
        Node* nodeB;

    public:
        Edge(){
            this->nodeA = nullptr;
            this->nodeB = nullptr;
            this->weight = 0;
        }

        Edge(Node* node1, Node* node2){

            this->nodeA = node1;
            this->nodeB = node2;
            this->weight = this->nodeA->distance(this->nodeB->getX(), this->nodeB->getY());

        }

        //custom compartor operator for my edge class for priority queue
        bool operator < (const Edge& edge) const{
            return (this->weight > edge.getWeight());
        }

        int getWeight() const{
            return this->weight;
        }

        Node* getNodeA() const{
            return this->nodeA;
        }

        Node* getNodeB() const{
            return this->nodeB;
        }
    
};

void setNodes(std::vector<Node*>& tour, Node* a, Node* b, int weight){
    //Printing and setting Node A's pointer to Node B, and Node B's pointer to Node A
    //Precondition: Node A and B both have no edge, or at most 1 edge
    std::cout << "Edge from " << a->getId() << " to " << b->getId() << " of weight " << weight <<std::endl;
    if(a->getNodeA() == nullptr){
        a->setNodeA(b);
    }else{
        a->setNodeB(b);
    }


    //Setting node B to point to Node A
    if(b->getNodeA() == nullptr){
        b->setNodeA(a);
    }else{
        b->setNodeB(a);
    }


    //Update tour vector only if the that entry of the tour list is nullptr, this is to avoid losing nodes and causing double free seg fault
    if (tour[a->getId()] == nullptr) {
        tour[a->getId()] = a;
    }

    //Update tour vector only if the that entry of the tour list is nullptr, this is to avoid losing nodes and causing double free seg fault
    if (tour[b->getId()] == nullptr) {
        tour[b->getId()] = b;
    }
}


bool addable(Node* input, Node* adjacent){
    
    //For a cycle to occur, you need BOTH node to have at least ONE edge
    //if Node A or Node B already has 2 edges, then its not addable
    if(input->occupied() || adjacent->occupied()){
        return false;
    }
    //if Node A or Node B currently have no edges, then its addable
    if((input->isCompleteEmpty() || adjacent->isCompleteEmpty())){
        return true;
    }


    //Checking for cycle
    //At this point, both input node and ajacent node should have exactly one edge
    Node* prev = input;
    Node* next = input->returnNoneEmpty();//return the pointer thats NOT pointing towards nullptr

    //iterate until reaching a node with a missing edge
    //while "next" still has 2 edges
    while(next->getNodeA() != nullptr && next->getNodeB() != nullptr ){
        
        //determine if I want to get to NodeA or NodeB
        if(next->getNodeA() == prev){
            prev = next;
            next = next->getNodeB();
        }else{
            prev = next;
            next = next->getNodeA();
        }
    }

    //if we're at the end and the end node matches with the ajacent node, it means it causes a cycle
    if(next == adjacent){
        return false;
    }else{
        return true;
    }
}

void readFile(std::vector<Node*>& nodeList, std::string filename){
    std::ifstream inputs(filename);
    if(!inputs){
        std::cout << "Failed to read Files" << std::endl;
        return;
    }
    
    //Need to skip till we find where the data is actually located
    std::string junk;
    while(inputs >> junk){
        if(junk == "NODE_COORD_SECTION"){
            break;
        }
    }

    int id;
    double x, y;
    while(inputs >> id >> x >> y){
        Node* n1 = new Node(x, y, id);
        nodeList.push_back(n1);            
    }
}

void greedyTSP (std::string filename){
    int totalDist, duration = 0;
    std::vector<Node*> nodeList;
    std::priority_queue<Edge> edgeList;

    readFile(nodeList, filename);
    int openEdges = nodeList.size() - 1;//this is to check when to break out the loop and manually adding an edge to create a cycle
    std::vector<Node*> tour(nodeList.size());

    auto start = std::chrono::steady_clock::now();

    //Calculating and creating a edge list
    //nodeList.end() - 1 to avoid calculating the weight of the same node
    for(std::vector<Node*>::iterator x = nodeList.begin(); x < nodeList.end() - 1; ++x){
        for(std::vector<Node*>::iterator y = x + 1; y < nodeList.end(); ++y){// y = x + 1 is also to avoid calculating the weight of the same node
        //creating and pushing Edge objects to a list, which has a constructor that sets and calculate the distance between the two node, and set the two nodes as attribute
            edgeList.push(Edge(*x, *y));
        }
    }

    while(!edgeList.empty() && openEdges > 2){
        //if its addable, and doesnt cause a cycle
        if(addable(edgeList.top().getNodeA(), edgeList.top().getNodeB())){

            totalDist += edgeList.top().getWeight();

            //setting the nodes to point to the appropriate node
            setNodes(tour, edgeList.top().getNodeA(), edgeList.top().getNodeB(), edgeList.top().getWeight());

            //decrement if one of the nodes has no more open edges
            if(edgeList.top().getNodeA()->occupied()){
                --openEdges;
            }

            if(edgeList.top().getNodeB()->occupied()){
                --openEdges;
            }
        }
        edgeList.pop();
        
    }
    
    //At this point there will only be 2 node that is missing an edge
    //Thus we manually search for it, and then manually adding the weight between the two nodes as well as adding to the tour list to create a cycle
    Node *n;
    bool Foundfirst = false;
    for(int i = 0; i < nodeList.size(); ++i){
        if(!(nodeList[i]->occupied()) && !Foundfirst){
            n = nodeList[i];
            Foundfirst = true;
        }else{
            if(!(nodeList[i]->occupied())){
                setNodes(tour , n, nodeList[i], nodeList[i]->distance(n->getX(), n->getY()));
                totalDist += nodeList[i]->distance(n->getX(), n->getY());
                break;                
            }
        }
    }

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    //Printing out the tour by tracing the from the first node, then print the distance and duration
    Node* trailer = tour[1];
    Node* head = tour[1]->getNodeA();
    Node* begin = tour[1];
    std::cout << begin->getId() << " ";
    while(head != begin){
        std::cout << head->getId() << " ";
        if(head->getNodeA() == trailer){
            trailer = head;
            head = head->getNodeB();
        }else{
            trailer = head;
            head = head->getNodeA();
        }
    }
    std::cout << begin->getId() << " " << std::endl;
    std::cout << "Total Distance: " << totalDist << std::endl << "Time in ms: " << duration << std::endl; 
    
    //deleting dynamically allocated node
    for (Node* node : nodeList) {
        delete node;
    }
    
    
}
