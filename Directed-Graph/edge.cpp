#include "edge.h"

//DO NOT TOUCH
Edge::Edge()
{

}

//DO NOT TOUCH
Edge::Edge(Vertex *to, int weight){
    to_ = to;
    weight_ = weight;
}

//DO NOT TOUCH
Vertex* Edge::GetTo(){
    return to_;
}

//DO NOT TOUCH
int Edge::GetWeight(){
    return weight_;
}
