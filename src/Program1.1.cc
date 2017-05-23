// Quick-find solution to connectivity problem
#include <iostream>
#include <cstdlib>
#include "Helper.h"
using namespace std;
int main(int argc, char** argv) {
    int N = 10000;
    if( argc >= 2 ) N = std::atoi(argv[1]);
    int i, p, q, *id = new int[N];
    for(i = 0; i < N; i++) id[i] = i;
    while(cin >> p >> q){
        int t = id[p];
        if( t == id[q] ) continue;
        for( i = 0; i < N; i++)
            if( id[i] == t ) id[i] = id[q];
        cout << " " << p << " " << q << endl;
    }
    CppAlgorithms::Print(cout, id, id+N); cout << endl;
}
