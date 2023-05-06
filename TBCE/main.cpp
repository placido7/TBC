#include "bipartite_graph.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<random>
#include <sys/time.h>

using namespace std;

//====================================================get_wall_time====================================================
//
double get_wall_time() {
    struct timeval time{};
    if (gettimeofday(&time, nullptr)) {
        return 0;
    }
    return (double) time.tv_sec + (double) time.tv_usec * .000001;
}

//
//====================================================main====================================================
int main(int argc, char **argv) {
    cout.setf(ios::fixed, ios::floatfield);//Non-scientific notation
    if (argc != 5) {
        cout << "please input five parameters: infile, outfile, delta, edge sampling rate P!" << endl;
        exit(1);
    }
    string infile = argv[1];
    string outfile = argv[2];
    int delta = stoi(argv[3]);
    double P = stod(argv[4]);

    cout << "input file: " << infile << endl;
    cout << "output file: " << outfile << endl;
    cout << "delta: " << delta << endl;
    cout << "P: " << P << endl;
    ifstream in(infile.c_str());
    if (!in) {
        cout << "open infile failed\n";
        exit(1);
    }
    in.close();
    ofstream out(outfile.c_str(), ios::app);
    out.setf(ios::fixed, ios::floatfield);//Non-scientific notation
    if (!out) {
        cout << "open outfile failed\n";
        exit(1);
    }
    out.close();
    int found = infile.find_last_of("/");
    string s(infile.substr(found + 1, 5));
    cout << "prefile " << s << endl;


//
//====================================================reading graph====================================================
//

    TGraph G;
    char buf[100];
    const char *d = " ";
    long a[3];
    double start, time1;
    in.open(infile.c_str());
    while (in.getline(buf, 100)) {
        char *p = strtok(buf, d);
        int i = 0;
        while (p) {
            a[i] = atol(p);
            p = strtok(nullptr, d);
            i = i + 1;
        }
        delete p;
        if (a[0] != a[1]) {
            G.addEdge(a[0], a[1], a[2], 0);
        }
    }

    G.Initialize();
    cout << "Finish reading " << G.edges.size() << " edges and the last edge is " << a[0] << " " << a[1] << " " << a[2]
         << endl;
    in.close();

//
//====================================================sampling====================================================
//

    mt19937 rng(std::random_device{}());
    for (int j = 0; j < 10; j++) {
        start = get_wall_time();
        cout << j << " ";
        double rn;
        vector<TEdge> ids;
        long count[6] = {0, 0, 0, 0, 0, 0};
        out.open(outfile.c_str(), ios::app);
        uniform_real_distribution<double> u(0.0, 1.0);

        for (auto it = G.edges.begin(); it != G.edges.end(); it++) {
            rn = u(rng);
            if (rn <= P) {
                std::unique_ptr<long[]> temp = G.Motif(*it, delta);
                for (int i = 0; i < 6; i++) {
                    count[i] += temp[i];
                }
            }
        }

        out.close();
        cout << "number of sampling:" << ids.size() << endl;
        cout << "start counting the motif" << endl;

        time1 = get_wall_time() - start;
        out.open(outfile.c_str(), ios::app);
        out << time1 << " ";
        for (int i = 0; i < 6; i++) {
            out << count[i] / P << " ";
            if (i == 5) {
                out << endl;
            }
        }
    }
    out.close();

}





