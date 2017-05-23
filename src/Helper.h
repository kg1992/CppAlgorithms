#include <iostream>
#include <iterator>

namespace CppAlgorithms {
    template<typename iterator_type>
    std::ostream& Print(std::ostream& o, iterator_type beg, iterator_type end)
    {
        const char delim[] = ", ";
        while( beg != end ){
            o << *beg++;
            if( beg != end )
                o << delim;
        }
        return o;
    }
    
    std::ostream& PrintTree(std::ostream& o, int* a, int count);
}