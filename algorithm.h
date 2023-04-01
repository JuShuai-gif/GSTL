#pragma once

#include <functional>
#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>

namespace G{
    template <typename InputIterator>
    inline void print(InputIterator beg, InputIterator end)
    {
        while (beg != end)
        {
            std::cout << *beg++ << ",";
        }
        std::cout << std::endl;
    }

    namespace detail {
        // 随机迭代器
        template<typename RandomAccessIterator>
        inline typename std::iterator_traits<RandomAccessIterator>::difference_type
            distance(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag)
        {
            return last - first;
        }
        // 输入迭代器
        template<typename InputIterator>
        inline typename std::iterator_traits<InputIterator>::difference_type
            distance(InputIterator first, InputIterator last, std::input_iterator_tag)
        {
            typename std::iterator_traits<InputIterator>::difference_type n = 0;
            while (first != last)
            {
                ++first;
                ++n;
            }
            return n;
        }
    }

    template<typename InputIterator>
    inline typename std::iterator_traits<InputIterator>::difference_type
    distance(InputIterator first,InputIterator last)
    {
        return detail::distance(first,last,typename std::iterator_traits<InputIterator>::iterator_category());
    }

    template <typename InputIterator, typename OutInterator>
    inline OutInterator copy(InputIterator beg, InputIterator end, OutInterator out)
    {
        while (beg != end) 
        {
            *out++ = *beg++;
        }
        return out;
    }

    template <typename InputIterator,typename T>
    InputIterator find(InputIterator beg,InputIterator end,const T& value) {
        for (; beg != end && *beg != value; beg++)
        {}
        return beg;
    }
    // 这个的UnaryPredicate是个匿名函数
    template<typename InputIterator,typename UnaryPredicate>
    InputIterator find_if(InputIterator beg,InputIterator end,UnaryPredicate pre) 
    {
        for(;beg!=end && !pre(*beg); beg++)
        {}
        return beg;
    }
    template <typename InputIterator,typename UnaryPredicate>
    InputIterator find_if_not(InputIterator beg,InputIterator end,UnaryPredicate pre) {
        for (; beg!=end && pre(*beg); beg++)
        {}
        return beg;
    }

    template <typename InputInerator,typename UnaryPredicate>
    InputInerator min_element(InputInerator beg,InputInerator end,UnaryPredicate comp) {
        if (beg == end)
            return beg;
        auto min = beg;
        while (++beg != end)
        {
            if (comp(*beg, *min))
                min = beg;
        }
        return min;
    }

    template <typename InputIterator>
    InputIterator min_element(InputIterator beg,InputIterator end) {
        return G::min_element(beg, end, std::less<decltype(*beg)>());
    }

    template <typename InputIterator,typename UnaryPredicate>
    InputIterator max_element(InputIterator beg,InputIterator end,UnaryPredicate pre) {
        if (beg == end)
            return beg;
        auto max = beg;
        while (++beg!=end)
        {
            if (pre(*max, *beg))
                max = beg;
        }
        return max;
    }

    template <typename InputIterator>
    InputIterator max_element(InputIterator beg,InputIterator end) {
        return G::max_element(beg, end, std::less<decltype(*beg)>());
    }

    template<typename ForwardIterator,typename Comp>
    std::pair<ForwardIterator,ForwardIterator>
        minmax_element(ForwardIterator beg,ForwardIterator end,Comp comp) {
        if (beg == end)
            return { beg,end };
        auto min = beg, max = end;
        while (++beg != end)
        {
            if (comp(*beg, *min))
                min = beg;
            if (comp(*max, *beg))
                max = beg;
        }
        return { min,max };
    }

    template<typename ForwardInterator>
    std::pair<ForwardInterator,ForwardInterator>
        minmax_element(ForwardInterator beg,ForwardInterator end) 
    {
        return G::minmax_element(beg, end, std::less<decltype(*beg)>());
    }

    template<typename InputIterator1,typename InputIterator2>
    bool equal(InputIterator1 beg1,InputIterator1 end1, InputIterator2 beg2){
        while(beg1 != end1){
            if (*beg1++ != *beg2++)
            {
                return false;
            }
        }
        return true;
    }

    template<typename InputIterator1,typename InputIterator2,typename Predicate>
    bool equal(InputIterator1 beg1,InputIterator1 end1,InputIterator2 beg2,Predicate pre){
        while (beg1 != end1)
        {
            if(!pre(*beg1++,*beg2++)){
                return false;
            }
        }
        return true;
    }
}