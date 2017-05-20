// Show how to modify Program 1.3 to implement full path compression, where we
// comlete each union operation by making every node that we touch point to the
// root of the new tree

#include <iostream>
#include <cstdlib>
#include "Helper.h"
using namespace std;
int main(int argc, char** argv) {
    int N = 10000;
    if( argc >= 2 ) N = std::atoi(argv[1]);
    int i, j, p, q, u, v, *id = new int[N], *sz = new int[N];
    for(i = 0; i < N; i++) { id[i] = i; sz[i] = 1; }
    while(cin >> p >> q){
        for( i = p; i != id[i]; i = id[i]);
        u = p;
        while( u != i ){
            int b = id[u];
            id[u] = i;
            u = b;
        }
        for( j = q; j != id[j]; j = id[j]);
        v = q;
        while( v != j ){
            int b = id[v];
            id[v] = j;
            v = b;
        }
        if( i == j ) continue;
        if( sz[i] < sz[j] ) { id[i] = j; sz[j] += sz[i]; }
        else { id[j] = i; sz[i] += sz[j]; }
        cout << " " << p << " " << q << endl;
    }
    Helper::Print(cout, id, id+N); cout << endl;
    Helper::Print(cout, sz, sz+N); cout << endl;
    Helper::PrintTree(cout, id, N); cout << endl;
}
