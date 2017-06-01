#include "graph.h"
#include "limits"

//DO NOT TOUCH
Graph::Graph()
{

}

//DO NOT TOUCH
void Graph::AddVertex(int key){
    vertex_list_.push_back(new Vertex(key));
    num_vertexes_++;
}

//DO NOT TOUCH
void Graph::AddEdge(char from, char to, int weight){
    Vertex *vfrom = GetVertex(from);
    Vertex *vto = GetVertex(to);
    vfrom->AddEdge(vto, weight);
}

//DO NOT TOUCH
Vertex* Graph::GetVertex(char key){
    int i = 0;
    while(i < num_vertexes_){
        if(vertex_list_[i]->GetKey() == key){
            return vertex_list_[i];
        }
        i++;
    }

    AddVertex(key);
    return vertex_list_[i];
}

bool Graph::IsAdjacent(char from, char to){
    Vertex *vfrom = GetVertex(from);

    if(vfrom->HasEdge(to)){
        return true;
    }else{
        return false;
    }
}

void Graph::PrintNeighbors(char vertex){
    Vertex *vfrom = GetVertex(vertex);

    for(int i = 0; i < vfrom->GetNumEdges(); i++){
        std::cout<<vfrom->GetEdge(i)->GetTo()->GetKey()<<" ";
    }
    std::cout<<std::endl;
}

Vertex* Graph::DijkstrasAlgorithm(char start, char end){
    //The current vertex you are working on.
    Vertex* currentVertex = nullptr;

    //How many vertices we've visited.
    int visited = 0;

    //An array that keeps track of the already visited vertices.
    int visitedIndex[num_vertexes_] = {0};
    for(int i=0;i<num_vertexes_;i++)
    {
        currentVertex=vertex_list_[i];
        currentVertex->SetWeight(INT_MAX);



    }
    currentVertex=GetVertex(start);
    currentVertex->SetWeight(0);

    Vertex* temp;
    while(visited<num_vertexes_)
    {
        visitedIndex[0] = 1;
        //currentVertex=GetVertex(0);
        int smIndex=0;
        for(int i=0;i<num_vertexes_;i++)
        {
          // std::cout<<vertex_list_[i]->GetWeight()<<" ";
          //  std::cout<<currentVertex->GetWeight()<<" ";
            if(vertex_list_[i]->GetWeight() < temp->GetWeight() && visitedIndex[i]!=1)
            {
               // std::cout<<" got to first if statement"<<std::endl;
                currentVertex=vertex_list_[i];
                smIndex = i;


            }

        }

        visitedIndex[smIndex] = 1;

        //std::cout<<"Num Edges: "<<currentVertex->GetNumEdges()<<std::endl;

        for(int j=0;j<currentVertex->GetNumEdges();j++)
        {
            temp=currentVertex->GetEdge(j)->GetTo();
            int edge = currentVertex->GetEdge(j)->GetWeight();
            int combined = edge + currentVertex->GetWeight();
            //std::cout<<temp->GetWeight()<<" temp weight"<<std::endl;
            if(combined < temp->GetWeight())
            {

               // std::cout<<currentVertex->GetWeight()<<" c vertex weight"<<std::endl;
                temp->SetPrev(currentVertex);
                temp->SetWeight(combined);
               // std::cout<<"temps weight"<< temp->GetWeight()<<std::endl;
               // std::cout<<temp->GetKey()<<std::endl;
            //    std::cout<<"got here2"<<std::endl;
            }

        }

        if(temp==GetVertex(end))
        {
           // std::cout<<" got to the end!";
            return temp;
        }
        visited++;


    }


return temp;
}
