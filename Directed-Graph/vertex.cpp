#include "vertex.h"

//DO NOT TOUCH
Vertex::Vertex(){
    key_ = '?';
    num_edges_ = 0;
}

//DO NOT TOUCH
Vertex::Vertex(int key)
{
   key_ = key; //value
}

//DO NOT TOUCH
char Vertex::GetKey(){
    return key_;
}

//DO NOT TOUCH
int Vertex::GetNumEdges(){
    return num_edges_; // number of edges
}

//DO NOT TOUCH
Edge* Vertex::GetEdge(char to){
    for(int i = 0; i < num_edges_; i++){            //loop through edges
        if(edges_[i]->GetTo()->GetKey() == to){
            return edges_[i];                       //returns edge number that connects to specified vertex
        }
    }
    return 0;
}

//DO NOT TOUCH
Edge* Vertex::GetEdge(int index){       //asks for edge of a specific number
    if(index < num_edges_){             //returns edge if specified number within
        return edges_[index];
    }
    return nullptr;
}

//DO NOT TOUCH
void Vertex::AddEdge(Vertex *to, int weight){
    edges_.push_back(new Edge(to, weight));       //add edge,specify its weight and where it connects to
    num_edges_++;                                 //update number of edges for vertex
}

//DO NOT TOUCH
bool Vertex::HasEdge(char to){                    //checks if vertex has edge with other vertex
    for(int i = 0; i < num_edges_; i++){
        if(edges_[i]->GetTo()->GetKey() == to){    // checks if the from connects to the to
            return true;
        }
    }
    return false;
}


