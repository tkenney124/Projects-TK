#include "graph.h"

//DO NOT TOUCH
Graph::Graph()
{

}

//DO NOT TOUCH
void Graph::AddVertex(int key){                     //add new vertex to graph
    vertex_list_.push_back(new Vertex(key));        // graph stored as vector
    num_vertexes_++;
}

//DO NOT TOUCH
void Graph::AddEdge(char from, char to, int weight){
    Vertex *vfrom = GetVertex(from);
    Vertex *vto = GetVertex(to);
    vfrom->AddEdge(vto, weight);                    //adds edge from origin to destination, gives weight
}

//DO NOT TOUCH
Vertex* Graph::GetVertex(char key){
    int i = 0;
    while(i < num_vertexes_){                   //to loop through vertex_list
        if(vertex_list_[i]->GetKey() == key){   //returns vertex from list if one matches key given
            return vertex_list_[i];
        }
        i++;                                    //increments key
    }

    AddVertex(key);                             // if it doesnt exist - adds the vertex and returns the new list
    return vertex_list_[i];
}

bool Graph::IsAdjacent(char from, char to){
    Vertex *vfrom = GetVertex(from);
    Vertex *vto = GetVertex(to);
    //HasEdge expects a character, not a Vertex pointer
    //Also, be sure to put this in an if and return the appropriate boolean value

    if(vfrom->HasEdge(vto->GetKey())) //expects a character - get key returns that character
    {
        return true;
    }
    return false;
}

void Graph::PrintNeighbors(char vertex){

    Vertex *home = GetVertex(vertex);
    //Instead of num_vertexes_, look and see what functions home has available to it.
    //Is there a better integer we could use there?
    std::cout<<"Neighbors of "<<vertex<<" :";
    for(int i=0; i<home->GetNumEdges(); i++){
      char temp =  home->GetEdge(i)->GetTo()->GetKey(); // gets what home connects to and then returns the key to be used in has edge



        if(home->HasEdge(temp))  //requires HasEdge to work, now it does work and it shows what from(home) connects to(temp)
        {

            std::cout<<GetVertex(temp)->GetKey()<<" ";
        }
    }

}
//Once you get the above figured out, access the array (vector) in home at a specific index.
//Look at GetEdge(int index);
/*Edge* Vertex::GetEdge(int index){       //asks for edge of a specific number
    if(index < num_edges_){             //returns edge if specified number within
        return edges_[index];
    }
    return nullptr;
}
    */
