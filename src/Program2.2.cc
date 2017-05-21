#include <iostream>

using namespace std;

int search(int a[], int v, int l, int r)
{
    while( r>= l)
    {
        int m = (l+r)/2;
        if( v == a[m] ) return m;
        if( v < a[m] ) r = m-1; else l = m+1;
    }
    return -1;
}

int main()
{
    const int N = 10;
    int a[N];
    for( int i = 0; i < N; ++i ) a[i] = i;
    cout << search(a, 5, 0, 9) << endl;
    return 0;
}