#include "vertex.h"

//DO NOT TOUCH
Vertex::Vertex(){
    key_ = '?';
    num_edges_ = 0;
}

//DO NOT TOUCH
Vertex::Vertex(char key)
{
   key_ = key;
}

//DO NOT TOUCH
char Vertex::GetKey(){
    return key_;
}

//DO NOT TOUCH
int Vertex::GetNumEdges(){
    return num_edges_;
}

//DO NOT TOUCH
Edge* Vertex::GetEdge(char to){
    for(int i = 0; i < num_edges_; i++){
        if(edges_[i]->GetTo()->GetKey() == to){
            return edges_[i];
        }
    }
    return 0;
}

//DO NOT TOUCH
Edge* Vertex::GetEdge(int index){
    if(index < num_edges_){
        return edges_[index];
    }
    return nullptr;
}

//DO NOT TOUCH
void Vertex::AddEdge(Edge* newEdge){
    edges_.push_back(newEdge);
    num_edges_++;
}

//DO NOT TOUCH
void Vertex::AddEdge(Vertex *to, int weight){
    edges_.push_back(new Edge(to, weight));
    num_edges_++;
}

//DO NOT TOUCH
bool Vertex::HasEdge(char to){
    for(int i = 0; i < num_edges_; i++){
        if(edges_[i]->GetTo()->GetKey() == to){
            return true;
        }
    }
    return false;
}

void Vertex::SetNumEdges(int numEdges){
    num_edges_ = numEdges;
}

void Vertex::SetKey(char key){
    key_ = key;
}

Vertex* Vertex::CopyVertex(){
    Vertex* newVertex = new Vertex();

    newVertex->SetWeight(weight_);
    newVertex->SetKey(key_);
    newVertex->SetNumEdges(num_edges_);

    for(int i = 0; i < num_edges_; i++){
        newVertex->AddEdge(edges_.at(i)->CopyEdge());
    }

    return newVertex;
}

int Vertex::GetWeight(){
    return weight_;
}

int Vertex::SetWeight(int weight){
    weight_ = weight;
}

Vertex* Vertex::GetPrev(){
    return prev_;
}

void Vertex::SetPrev(Vertex* prev){
    prev_ = prev;
}

void Vertex::ReconstructPath(){
    std::stack <char> path;

    Vertex* current = prev_;

    path.push(key_);
    while(current){
        path.push(current->GetKey());
        current = current->GetPrev();
    }

    while(path.size()){
        std::cout<<path.top()<<" ";
        path.pop();
    }
    std::cout<<std::endl;
}


