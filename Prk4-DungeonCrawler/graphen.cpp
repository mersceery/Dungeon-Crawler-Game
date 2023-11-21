#include "graphen.h"
#include "door.h"
#include "cmath"
#include "levelchanger.h"
#include <queue>
#include <typeinfo>
#define INF 0xFFFFFFF
using std::priority_queue;

Graphen::Graphen(): level(nullptr)
{

}

Graphen::~Graphen()
{
    auto row = level->getBreite();
    auto col = level->getHohe();
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            delete nodeField[i][j];
        }
    }
}

void Graphen::initGraphen(Level *lvl)
{
    //if not nullptr meaning there exist another graph
    //then delete all the nodes in the previous graph
    if(level != nullptr){
        for (int i=0; i<level->getBreite(); i++){
            for (int j=0; j<level->getHohe(); j++){
                delete nodeField[i][j];
            }
        }
    }
    level = lvl;
    auto row = level->getBreite();
    auto col = level->getHohe();

    //adjust the 2D Vector
    nodeField.resize(row, vector<Node*>(col));

    //creates a new node for each tile in the level
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            Node* tmp = new Node{level->getTile(i,j)};
            //checks if the new created node and the node at the current position are the same, if not then add it
            if(tmp != nodeField[i][j]){
                nodeField.at(i).at(j) = tmp;
            }
        }
    }

    //add the neighboring nodes to the node's adjacency list for each node
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            addNeighbourNode(nodeField.at(i).at(j),i,j);
        }
    }
}

double Graphen::caculateDistance(int Row1, int Col1, int Row2, int Col2)
{
    //euclidean in coordinates, prefer diagonal path if exist
    return sqrt(pow(Row1-Row2,2) + pow(Col1-Col2,2));
}

void Graphen::addNeighbourNode(Node *node, int currRow, int currCol)
{
    //checks all the 8 adjacent cells of the given node in the graph
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            //check if the row n col are valid (within the dimensions of the graph)
            //if not valid then just GG go next continue to the next iteration
            bool checkRow = (currRow+i >= 0) && (currRow+i < level->getBreite());
            bool checkCol = (currCol+j >= 0) && (currCol+j < level->getHohe());
            if(!(checkCol&&checkRow)){
                continue;
            }
            //assigns the node in the adjacent cell to these variables
            auto tmpNode = nodeField[currRow+i][currCol+j];
            Tile* tmpTile = tmpNode->tile;
            double distance = caculateDistance(currRow, currCol, currRow+i, currCol+j);

            //check then if true just GG go next (don't move yet if SOURCE still in LevelChanger)
            if((typeid(*tmpTile) == typeid(LevelChanger)) || (typeid(*node->tile) == typeid(LevelChanger))){
                continue;
            }

            //check whether we can enter or leave the tile (z.B Wall)
            bool canEnter = tmpTile->CheckOnEnter(node->tile) != nullptr;
            bool canLeave = node->tile->CheckOnLeave(tmpTile) != nullptr;

            auto desTile = tmpTile->CheckOnEnter(node->tile);
            auto desNode = findNode(desTile);

            //check if the current node n the adjacent node aren't the same n valid can enter && leave
            if((node != tmpNode) && canEnter && canLeave){
                node->adjListe.insert({desNode,distance});
            }
        }
    }
}

Node* Graphen::findNode(Tile *tile)
{
    for (int i=0; i<level->getBreite(); i++){
        for (int j=0; j<level->getHohe(); j++){
            if(tile == nodeField[i][j]->tile){
                return nodeField[i][j];
            }
        }
    }
    return nullptr;
}

//the graph is represented using an adjacency list and a priority queue is used to keep track
//of the unvisited nodes with the smallest distance from the starting node
std::vector<Node*> Graphen::shortestPathGraph(Tile *srcTile, Tile *desTile)
{
    //distance from the source node and a pointer to the node
    typedef std::pair<double, Node*> Element;

    // lambda function to make a functor for priority queue
    // and as a comparator to compare elements based on their distance from the source node.
    auto compare = [](Element elem1, Element elem2){ return elem1.first < elem2.first;};
    priority_queue<Element, vector<Element>,decltype(compare)> PriorQueue(compare);

    //access pair parameter with .first .second
    //stores the distance from the source node and the path to a node for each node in the graph
    //and is sorted using the MapSorter in struct
    std::map<Node*, std::pair<double, std::vector<Node*>>,Node::MapSorter> distance;

    //find source node, nicht existiert dann return empty vector of node
    auto srcNode = findNode(srcTile);
    if(srcNode == nullptr){
        return std::vector<Node*>{};
    }

    //push n insert source node each with the distance of 0 n an empty path
    PriorQueue.push(std::make_pair(0,srcNode));
    distance.insert({srcNode, std::make_pair(0, std::vector<Node*>{})});

    //with each iteration pop the node with the smallest distance from the source node from the queue
    while(!PriorQueue.empty()){
        //u is the nearest node from the source node
        Node* u = PriorQueue.top().second;
        PriorQueue.pop();

        //then iterates through the adjacency list of the popped node and for each adjacent node n
        //it checks if the distance to it is greater than the distance to the popped node + the weight of the edge between the two nodes
        for(auto i = u->adjListe.begin(); i != u->adjListe.end(); i++){
            Node* v = i->first;
            double weight = i->second;

            if(distance.find(v) == distance.end()){
                distance[v] = std::make_pair(INF, std::vector<Node*>{});
            }
           //If distance is shorter then updates the distance and the path (push it into the vector n queue)
            if(distance[v].first > distance[u].first + weight){
                distance[v].first = distance[u].first + weight;
                distance[v].second = distance[u].second;
                distance[v].second.push_back(u);
                PriorQueue.push(std::make_pair(distance[v].first,v));
            }
        }
    }

    //try to find the destination node in the graph, if not found then return empty vector
    auto destNode = findNode(desTile);
    if(destNode == nullptr){
        return std::vector<Node*>{};
    }
    //if the destNode is found then add the destination node to the path n returns that path as a vector of Node pointers
    auto iter = distance.find(destNode);
    if(iter != distance.end()){
        (*iter).second.second.push_back(destNode);
        return (*iter).second.second;
    }
    return std::vector<Node*>{};
}

//time complexity of this dijkstra code is O((E+V)logV), E = number of edges n V = number of vertices in the graph (with priority queue and map)
//that is if we visit and process all the vertices

//Inserting and deleting from a priority queue has a time complexity of O(VlogV) (VlogV coz the while loop runs V times n logV is from PrioQue)
//Map (to store distance n path of each node) = O(logV) for insertion and O(1) for access, total --> O(VlogV)
//dijkstra examines all its edges so the total number of edge examinations is O(E)






