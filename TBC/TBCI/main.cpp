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
    cout.setf(ios::fixed, ios::floatfield);//Non-scientific notation
    if (argc != 6) {
        cout << "please input five parameters: infile, outfile, delta, edge sampling P,C,s!" << endl;
        exit(1);
    }
    string infile = argv[1];
    string outfile = argv[2];
    int delta = stoi(argv[3]);
    double C = stod(argv[4]);
    double s = stod(argv[5]);
    cout << "input file: " << infile << endl;
    cout << "output file: " << outfile << endl;
    cout << "delta: " << delta << endl;
    cout << "C: " << C << endl;
    cout << "s: " << s << endl;
    ifstream in(infile.c_str());
    if (!in) {
        cout << "open infile failed\n";
        exit(1);
    }
    in.close();
    ofstream out(outfile.c_str(), ios::app);
    out.setf(ios::fixed, ios::floatfield);
    if (!out) {
        cout << "open outfile failed\n";
        exit(1);
    }
    out.close();
    int found = infile.find_last_of("/");
    string S(infile.substr(found + 1, 20));
    cout << "prefile " << S << endl;

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
    sort(G.edges.begin(), G.edges.end());
    in.close();

//
//====================================================sampling====================================================
//
//====================================================sampling====================================================
//


    double timeinterval = C * delta;
    mt19937 rng(std::random_device{}());
    out.open(outfile.c_str(), ios::app);
    for (int i = 0; i < 10; ++i) {
        double count[6] = {0, 0, 0, 0, 0, 0};
        start = get_wall_time();
        set<int> samples;
        vector<int> tr_set;
        unordered_map<int, vector<double>> hash;
        for (int j = 0; j < s; j++) {

            cout << j << " ";
            vector<TEdge> ids;
            uniform_int_distribution<int> dist(0, G.edges.size() - 1);
            int tr = dist(rng);
            tr_set.emplace_back(tr);
            cout << "start counting the motif1" << endl;
            for (auto it = G.edges.begin() + tr; it != G.edges.end(); it++) {
                if (it->tim > G.edges[tr].tim + C * delta) {
                    break;
                } else {
                    int in = it - G.edges.begin();
                    samples.insert(in);
                }
            }
        }
            //cout<<samples.size()<<endl;
            //cout << "start counting the motif2" << endl;
            for (auto it0 = samples.begin(); it0 != samples.end(); it0++) {
                    int tr0 = *it0;
                    auto it = G.edges.begin() + tr0;
                    int in0 = it - G.edges.begin();
                    int numCd = G.binarySearch(in0, timeinterval);
                    std::unique_ptr<double[]> temp = G.Motif(*it, delta, C, numCd);
                    vector<double> temp1;
                    for (int i1 = 0; i1 < 6; i1++) {
                        temp1.emplace_back(temp[i1]);
                    }
                    hash[tr0]=temp1;


            }
            //cout << 100 << " ";
            //cout << "start counting the motif3" << endl;
            for (auto it1 = tr_set.begin(); it1 != tr_set.end(); it1++) {
                int tr1 = *it1;
                for (auto it = G.edges.begin() + tr1; it != G.edges.end(); it++) {
                    if (it->tim > G.edges[tr1].tim + C * delta) {
                        break;
                    } else {
                        int in = it - G.edges.begin();
                        for (int i = 0; i < 6; i++) {
                            count[i] += hash[in][i];
                        }
                    }
                }
            }


        time1 = get_wall_time() - start;
        out.open(outfile.c_str(), ios::app);
        out << time1 << " ";
        long count1[6] = {0, 0, 0, 0, 0, 0};
        count1[0]=count[1];
        count1[1]=count[0];
        count1[2]=count[3];
        count1[3]=count[2];
        count1[4]=count[5];
        count1[5]=count[4];
        for (int k = 0; k < 6; k++) {
            out << count[k] / s << " ";
            if (k == 5) {
                out << endl;
            }
        }

    }
    out.close();
}
//
//====================================================count====================================================
//

