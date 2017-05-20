#include <iostream>

using namespace std;

int search(int a[], int v, int l, int r)
{
    for( int i = l; i <= r; ++i ){
        if( a[i] == v )
            return i;
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