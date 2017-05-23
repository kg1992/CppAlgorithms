// Program 3.8 Closest-point computation
//
// This program illustrates the use of an array of structures, and is representative of the typical situation
// where we save items in an array to precess them later, during some computation. It counts the number of
// pairs of N randomly generated points in the unit square that can be connected by a straight line of length
// less than d, using the data type for points described in Section3.I. The running time is O(N^2), so this
// program cannot be used for huge N,. Program 3.20 povides a faster solution.
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace CppAlgorithms{

    struct point{float x;float y;};
    
    float distance( point a, point b )
    {
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    }
}

float randFloat()
{ return 1.0* rand() / RAND_MAX; }

int main(int argc, char** argv)
{
    
    if( argc < 3 ) throw "needs two arguments to run";
    // get maximum distance d
    float d = atof(argv[2]);
    int i, cnt = 0, N = atoi(argv[1]);
    CppAlgorithms::point *a = new CppAlgorithms::point[N];
    // initialize points with random values
    for( i = 0; i < N; ++i )
    { a[i].x = randFloat(); a[i].y = randFloat(); }
    for( i = 0; i < N; ++i )
        for( int j = i+1; j < N; ++j )
            if( CppAlgorithms::distance(a[i], a[j]) < d) cnt++;
    cout << cnt << " paris within " << d << endl;
}