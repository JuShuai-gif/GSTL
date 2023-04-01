#include "algorithm_test.h"
#include "Stack.h"
#include "GMath.h"
int main()
{
    std::vector<int> v1{45,42,12,15,46};
    std::vector<int> v2{45,42,16,48,59};
    auto t = G::minmax_element(v1.begin(),v1.end());
    std::cout << *t.first<< *t.second << std::endl;
    auto b = G::equal(v1.begin(),v1.end(),v2.begin());
    std::cout << b << std::endl;
    return 0;
}