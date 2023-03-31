#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "algorithm.h"
namespace TEST {
	void algorithm_test(){
        std::cout << "distance()------" << std::endl;
        std::list<int> l{ 12,51,45,56 };
        G::distance(l.begin(), l.end()); // 1.
        std::cout << typeid(decltype(G::distance(l.begin(), l.end()))).name() << std::endl; // 2.
        std::cout << "print()------" << std::endl;
        G::print(l.begin(), l.end());

        std::vector<int> ll{ 12,51,45,56 };
        std::vector<int> v(4);
        std::cout << "copy()-----" << std::endl;
        G::copy(ll.begin(), ll.end(), v.begin());
        G::print(v.begin(), v.end());
        auto dis = G::find(ll.begin(), ll.end(), 51) - ll.begin();
        std::cout << dis << std::endl;
        std::cout << "find_if()-----" << std::endl;
        auto it = G::find_if(ll.begin(), ll.end(), [](int x) {
            return x > 42;
            });
        std::cout << *it << "  " << G::distance(ll.begin(), it) << std::endl;

        std::cout << "find_if_not()----" << std::endl;
        auto itt = G::find_if_not(ll.begin(), ll.end(), [](int x) {
            return x != 51;
            });
        std::cout << *itt << "  " << G::distance(ll.begin(), itt) << std::endl;

        std::vector<int> lll{ 12,51,45,56 };
        std::cout << "min_element()----" << std::endl;
        auto min = G::min_element(lll.begin(), lll.end());
        std::cout << "min: " << *min << std::endl;

        std::vector<int> llll{ 48,51,1,0,45,56 };
        // 这个如果不加G::的话会造成，函数调用歧义的错误
        auto minn = G::min_element(llll.begin(), llll.end(), [](int a,int b) {
            if (a < b)
                return true;
            else
                return false;
            });
        std::cout << "minn: " << *minn << std::endl;

        std::cout << "max_element()----" << std::endl;
        auto max = G::max_element(lll.begin(), lll.end());
        std::cout << "max: " << *max << std::endl;

        // 这个如果不加G::的话会造成，函数调用歧义的错误
        auto maxx = G::max_element(llll.begin(), llll.end(), [](int a, int b) {
            if (a < b)
                return true;
            else
                return false;
            });
        std::cout << "maxx: " << *maxx << std::endl;
	}
}