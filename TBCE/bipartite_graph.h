#ifndef PT_BIPARTITE_GRAPH_H
#define PT_BIPARTITE_GRAPH_H

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<climits>
#include<random>
#include<algorithm>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<set>
#include <algorithm>
#include <map>
#include <memory>
using namespace std;

class TEdge
{
public:
    long src,dest,tim,id;
    TEdge(long src,long dest,long tim,long id);
    bool operator<(const TEdge& e) const;
    static bool equal(TEdge e1, TEdge e2);

};
class TGraph
{
public:
    unordered_map < int, vector<TEdge>> adj;

    vector<TEdge> edges;

    void addEdge(long src,long dest,long tim,long id);

    void Initialize();

    vector<TEdge> Wedge(TEdge e,long delta);
    //寻找V型楔子
    std::unique_ptr<long[]> Wedge2Motif(TEdge e1,TEdge e2,long delta);

    unordered_map<long,vector<TEdge>> cross_top_node(TEdge edge1,TEdge edge2,long delta);
    //上层顶点的共同邻点

    std::unique_ptr<long[]> Motif(TEdge e,long delta);

    ~TGraph()= default;;


};

#endif //PT_BIPARTITE_GRAPH_H
