// Quick-union solution to connectivity problem
#include <iostream>
#include <cstdlib>
#include "Helper.h"
using namespace std;
int main(int argc, char** argv) {
    int N = 10000;
    if( argc >= 2 ) N = std::atoi(argv[1]);
    int i, j, p, q, *id = new int[N];
    for(i = 0; i < N; i++) id[i] = i;
    while(cin >> p >> q){
        for( i = p; i != id[i]; i = id[i]);
        for( j = q; j != id[j]; j = id[j]);
        if( i == j ) continue;
        id[i] = j;
        cout << " " << p << " " << q << endl;
    }
    Helper::Print(cout, id, id+N); cout << endl;
    Helper::PrintTree(cout, id, N); cout << endl;
}
