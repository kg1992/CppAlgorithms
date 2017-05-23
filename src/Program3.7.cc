// Program 3.7 Coin-flipping simulation
//
// If we flip a coin N times, we expect to get N/2 heads, but could get anywhere from 0 to N heads.
// This program rusn the experiement M times, taking N and M from the command line
// It uses an array f to keep track of the frequency of occurence of the outcome "i heads"
// for 0 <= i <= N, then prints out a historgram of the result of hte experiments,
// with one asterisk for each 10 occurences.
// The operation on which this programis based--indexing an array with a computes value-- is critical
// to the efficiency of many computational procedures.
#include <iostream>
#include <cstdlib>

using namespace std;

int heads()
{ return rand() < RAND_MAX/2; }

int main(int argc, char** argv)
{
    int i, j, cnt;
    if( argc < 3 ) throw "Need two arguments to run";
    // take N and M
    int N = atoi(argv[1]), M = atoi(argv[2]);
    // create buffer 
    int *f = new int[N+1];
    // initialize buffer 
    for( j = 0; j <= N; ++j ) f[j] = 0;
    // do 'flip coin N times' expreirment M times
    for( i = 0; i < M; ++i, f[cnt]++ )
        for( cnt = 0, j = 0; j <= N; ++j )
            if( heads() ) cnt++;
    // print result
    for( j = 0; j <= N; j++ )
    {
        if( f[j] == 0) cout << ".";
        for( i = 0; i < f[j]; i +=10 ) cout << "*";
        cout << endl;
    }
    
    return 0;
}