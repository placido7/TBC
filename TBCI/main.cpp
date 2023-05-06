#include "bipartite_graph.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<random>
#include <sys/time.h>
#include <memory>
using namespace std;
//====================================================get_wall_time====================================================
//
double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,nullptr)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
//
//====================================================main====================================================
int main(int argc,char **argv) {
    cout.setf(ios::fixed,ios::floatfield);//Non-scientific notation
    if (argc!=6)
    {cout<<"please input five parameters: infile, outfile, delta, edge sampling P,C,s!"<<endl; exit(1);}
    string infile=argv[1];
    string outfile=argv[2];
    int delta=stoi(argv[3]);
    double C=stod(argv[4]);
    double s=stod(argv[5]);
    cout<<"input file: "<<infile<<endl;
    cout<<"output file: "<<outfile<<endl;
    cout<<"delta: "<<delta<<endl;
    cout<<"C: "<<C<<endl;
    cout<<"s: "<<s<<endl;
    ifstream in(infile.c_str());
    if(!in){cout<<"open infile failed\n";exit(1);}
    in.close();
    ofstream out(outfile.c_str(),ios::app);
    out.setf(ios::fixed,ios::floatfield);
    if(!out){cout<<"open outfile failed\n";exit(1);}
    out.close();
    int found=infile.find_last_of("/");
    string S(infile.substr(found+1,20));
    cout<<"prefile "<<S<<endl;

//
//====================================================read the graph====================================================
//

    TGraph G;
    char buf[100];
    const char *d = " ";
    long a[3];
    double start, time1;
    in.open(infile.c_str());
    while (in.getline(buf, 100)) //
    {
        char *p = strtok(buf, d);
        int i = 0;
        while (p) {
            a[i] = atol(p); //
            p = strtok(nullptr, d);
            i = i + 1;
        }
        delete p;
        if (a[0] != a[1]) {
            G.addEdge(a[0], a[1], a[2], 0);
        }
    }

    G.Initialize();
    sort(G.edges.begin(),G.edges.end());
    in.close();

//
//====================================================sampling====================================================
//
//====================================================sampling====================================================
//


    double timeinterval =C*delta;
    mt19937 rng(std::random_device{}());
    out.open(outfile.c_str(), ios::app);
    for (int i = 0; i < 10; ++i) {
        double count[6] = {0, 0, 0, 0, 0, 0};
        start = get_wall_time();
        for (int j = 0; j <s; j++) {

            cout << j << " ";
            vector<TEdge> ids;
            uniform_int_distribution<int> dist(0,G.edges.size()-1);
            int tr=dist(rng);
            cout << "start counting the motif" << endl;
            for (auto it = G.edges.begin()+tr; it != G.edges.end(); it++) {
                if (it->tim >G.edges[tr].tim + C * delta) {
                    break;
                } else{
                    int in=it-G.edges.begin();
                    int numCd= G.binarySearch(in,timeinterval);
                    std::unique_ptr<double[]>temp = G.Motif(*it, delta, C, numCd);
                    for (int i = 0; i < 6; i++) {
                            count[i] += temp[i];
                    }


                }
            }

            cout << "number of sampling:" << ids.size() << endl;

        }
        time1 = get_wall_time() - start;
        out<< time1<<" ";
        for (int k = 0; k < 6; k++) {
            out << count[k]/s <<" ";
            if(k==5)
            {
                out<<endl;
            }
        }


    }

    out.close();

}
//
//====================================================count====================================================
//






