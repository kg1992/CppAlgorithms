#include <iostream>
#include <iterator>
#include <vector>
#include <stack>

namespace Helper {
    template<typename iterator_type>
    static std::ostream& Print(std::ostream& o, iterator_type beg, iterator_type end)
    {
        const char delim[] = ", ";
        while( beg != end ){
            o << *beg++;
            if( beg != end )
                o << delim;
        }
        return o;
    }
    
    static std::ostream& PrintTree(std::ostream& o, int* a, int count)
    {
        // open list
        auto ol = std::stack<int>();
        auto depths = std::stack<int>();
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
    }
}