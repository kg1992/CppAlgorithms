#include "Helper.h"
#include <stack>

namespace CppAlgorithms
{
    std::ostream& PrintTree(std::ostream& o, int* a, int count)
    {
        // open list
        std::stack<int> ol = std::stack<int>(), depths = std::stack<int>();
        int i;
        
        // collect roots
        for( i = 0; i < count; ++i )
        {
            if( i == a[i] )
            {
                ol.push(i);
                depths.push(0);
            }
        }
        
        while( !ol.empty() )
        {
            i = ol.top();
            ol.pop();
            int d = depths.top();
            depths.pop();
            for( int j = 0; j < count; ++j )
            {
                if( i != j && a[j] == i )
                {
                    ol.push(j);
                    depths.push(d+1);
                }
            }
            for( int j = 0; j < d; ++j ) o << " ";
            o << "└" << i << std::endl;
        }
        
        return o;
    }
}