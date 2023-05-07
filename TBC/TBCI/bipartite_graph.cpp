#include "bipartite_graph.h"
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include <memory>

using namespace std;

TEdge::TEdge(long src, long dest, long tim, long id)
{
    this->src = src;
    this->dest = dest;
    this->tim = tim;
    this->id = id;
}


bool TEdge::operator<(const TEdge &e) const
{
        return tim<e.tim;

}

bool TEdge::equal(TEdge e1, TEdge e2) {
    if(e1.src==e2.src&&e1.dest==e2.dest&&e1.tim==e2.tim)
    {
        return true;
    }
    return false;
}


void TGraph::addEdge(long src, long dest, long tim, long id) {
    TEdge e(src, dest, tim, id);
    edges.emplace_back(e);
}

void TGraph::Initialize() {

    for (auto it = edges.begin(); it != edges.end(); it++) {
        adj[it->src].emplace_back(*it);
        adj[it->dest].emplace_back(*it);
        timeset.insert(it->tim);
    }

}


vector<TEdge> TGraph::Wedge(TEdge e, long delta) {
    vector<TEdge> ans;
    long src=e.src;
    long dest=e.dest;
    long time=e.tim;
    for(auto & edge : adj[dest])
    {
        if(abs(edge.tim-time)<=delta&&(edge.tim!=time)&&!TEdge::equal(e,edge)
           &&edge.src>e.src)
        {
            ans.emplace_back(edge);

        }
    }
    return ans;

}

std::unique_ptr<double[]> TGraph::Wedge2Motif(TEdge e1, TEdge e2, long delta,double C,int numCd) {
    std::unique_ptr<double[]> ans(new double[6]());
    unordered_map<long, vector<TEdge>> cross;
    cross = cross_top_node(e1, e2,delta);

    for (auto &it: cross) {
        if (it.second.size() < 2 || it.first == e1.dest)
        {
            continue;
        } else {
            vector<TEdge> rete1;
            vector<TEdge> rete2;

            for(auto it1=it.second.begin();it1!=it.second.end();it1++)
            {
                if(it1->src==e1.src)
                {
                    rete1.emplace_back(*it1);
                } else if(it1->src==e2.src)
                {
                    rete2.emplace_back(*it1);
                }
            }
            sort(rete1.begin(),rete1.end());
            sort(rete2.begin(),rete2.end());
            for(auto it1=rete1.begin();it1!=rete1.end();it1++)
            {

                for(auto it2=rete2.begin();it2!=rete2.end();it2++)
                {
                    vector<TEdge> ret;
                    ret.emplace_back(e1);
                    ret.emplace_back(e2);
                    ret.emplace_back(*it2);
                    ret.emplace_back(*it1);
                    long a[4];long b[4];long c[4];
                    for (auto it3 = ret.begin(); it3 != ret.end(); it3++) {
                        int i = it3 - ret.begin();
                        a[i] = it3->tim;
                        b[i] = it3->tim;
                    }

                    sort(b, b + 4);
                    if(unique(b,b+4)!=b+4)
                    {
                        continue;
                    }
                    if (b[3] - b[0] > delta) {
                        continue;
                    }
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            if (a[i] == b[j]) {
                                c[i] = j + 1;
                            }
                        }
                    }
                    int num = c[0] * 1000 + c[1] * 100 + c[2] * 10 + c[3];

                    double P_1=edges.size()/(numCd);

                    switch (num)
                    {
                        case 1234:case 2143:case 3412:case 4321:
                            ans[0]+=P_1;
                            break;
                        case 1243:case 4312:case 3421:case 2134:
                            ans[1]+=P_1;
                            break;
                        case 1324:case 4231:case 2413:case 3142:
                            //cout<<"ans2"<<' '<<ans[2]<<endl;
                            ans[2]+=P_1;
                            break;
                        case 1342:case 2431:case 3124:case 4213:
                            ans[3]+=P_1;
                            break;
                        case 1423:case 3241:case 4132:case 2314:
                            ans[4]+=P_1;
                            break;
                        case 1432:case 3214:case 2341:case 4123:
                            ans[5]+=P_1;
                            break;
                        default:
                            break;
                    }
                }

            }
        }
    }
    return ans;
}

unordered_map<long, vector<TEdge>> TGraph::cross_top_node(TEdge edge1, TEdge edge2,long delta) {
    unordered_map<long, vector<TEdge>> ans;
    long t_up=min(edge1.tim,edge2.tim)+delta;
    long t_lp=max(edge1.tim,edge2.tim)-delta;
    for(auto & edge:adj[edge1.src])
    {
        if(edge1.dest<edge.dest&edge.tim<=t_up
           &&edge.tim>=t_lp)
            ans[edge.dest].emplace_back(edge);
    }
    for(auto & edge:adj[edge2.src])
    {
        if(edge1.dest<edge.dest&&edge.tim<=t_up
           &&edge.tim>=t_lp)
            ans[edge.dest].emplace_back(edge);
    }
    return ans;
}

std::unique_ptr<double[]> TGraph::Motif(TEdge e, long delta,double C,int numCd) {
    vector<TEdge> W= Wedge(e,delta);
    std::unique_ptr<double[]> ans1(new double[6]());

    for(auto w:W)
    {
        std::unique_ptr<double[]> temp=Wedge2Motif(e,w, delta, C, numCd);
        for(int i=0;i<6;i++)
        {
            ans1[i]+=temp[i];
        }
    }
    return ans1;
}


int TGraph::binarySearch(int index,double timeinterval) {
    int left = 0;
    int right = index;
    double a=edges[index].tim-timeinterval;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (edges[mid].tim >= a) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    int ans=index-result+1;
    return ans;

}










