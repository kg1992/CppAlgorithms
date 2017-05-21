// Types of numbers (Standard deviation)
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "Helper.h"

using namespace std;

typedef int Number;
Number randNum()
{ return rand();}

int main(int argc, char* argv[])
{
    int N = argc > 1 ? atoi(argv[1]) : 100;
    float m1 = 0.0, m2 = 0.0;
    vector<Number> items = vector<Number>();
    for(int i = 0; i < N; ++i )
    {
        Number x = randNum() % 100;
        items.push_back(x);
        m1 += ((float) x)/N;
        m2 += ((float)x*x)/N;
    }
    cout << "items : "; Helper::Print(cout, items.begin(), items.end()); cout << endl;
    cout << "     Avg.: " << m1 << endl;
    cout << "Std. dev.: " << sqrt(m2-m1*m1) << endl;
    return 0;
}