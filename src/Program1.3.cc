// Weighted version of quick union
#include <iostream>
#include <cstdlib>
#include "Helper.h"
using namespace std;
int main(int argc, char** argv) {
    int N = 10000;
    if( argc >= 2 ) N = std::atoi(argv[1]);
    int i, j, p, q, *id = new int[N], *sz = new int[N];
    for(i = 0; i < N; i++) { id[i] = i; sz[i] = 1; }
    while(cin >> p >> q){
        for( i = p; i != id[i]; i = id[i]);
        for( j = q; j != id[j]; j = id[j]);
        if( i == j ) continue;
        if( sz[i] < sz[j] ) { id[i] = j; sz[j] += sz[i]; }
        else { id[j] = i; sz[i] += sz[j]; }
        cout << " " << p << " " << q << endl;
    }
    CppAlgorithms::Print(cout, id, id+N); cout << endl;
    CppAlgorithms::Print(cout, sz, sz+N); cout << endl;
    CppAlgorithms::PrintTree(cout, id, N); cout << endl;
}
