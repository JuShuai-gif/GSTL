#include <iostream>
#include <vector>
#include <type_traits>
namespace G{
    template<typename T>
    T Lareange(std::vector<T> x,std::vector<T> y,T xi){
        static_assert(std::is_arithmetic<T>::value, "Integral required.");
        T yi = 0;
        for (size_t i = 0; i < x.size(); ++i)
        {
            T li = 1;
            for(size_t j = 0;j < y.size();++j)
            {
                if (j != i){
                    li *= (xi - x[j]) / (x[i] - x[j]);
                }
            }
            yi += li * y[i];
            
        }
        return yi;
    }
}