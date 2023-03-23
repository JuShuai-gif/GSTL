#pragma once

#include <functional>
#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>

namespace G{
    inline void print(){
        std::cout << "这是algorithm.h" << std::endl;
    }

    template<typename InputIterator>
    // difference_type 表示两个迭代器之间的距离，也就是它们之间的元素个数。
    // 这个类型通常是一个有符号整数类型，可以用来表示迭代器之间的距离

    // traits是一种编程技术，用于在编译时获取类型信息和特性

    //`typename` 关键字用于标识一个名称是类型名称，而不是变量或函数名称。通常情况下，
    //当使用模板时，编译器无法确定某个名称是否表示类型，因此需要使用 `typename` 关键字来明确指示该名称是一个类型。

    //`std::input_iterator_tag` 是 C++ STL 中的一个迭代器标签（iterator tag），用于表示迭代器的类型或特性。它是一个空结构体，没有任何成员变量或成员函数。
    
    inline typename std::iterator_traits<InputIterator>::difference_type
    distance(InputIterator first,InputIterator last)
    {
        return G::distance(first,last,typename std::iterator_traits<InputIterator>::iterator_category());
    }

    template<typename RandomAccessIterator>
    inline typename std::iterator_traits<RandomAccessIterator>::difference_type
    distance(RandomAccessIterator first,RandomAccessIterator last,std::random_access_iterator_tag)
    {
        return last - first;
    }

    template<typename InputIterator>
    inline typename std::iterator_traits<InputIterator>::difference_type
    distance(InputIterator first,InputIterator last,std::input_iterator_tag)
    {
        typename std::iterator_traits<InputIterator>::difference_type n = 0;
        while (first!=last)
        {
            ++first;
            ++n;
        }
        return n;
    }
}