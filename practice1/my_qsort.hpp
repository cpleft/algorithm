/* file		: my_qsort.hpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Apr 10 11:25:06 CST 2019
 * last update	: Wed Apr 10 13:42:48 CST 2019
 * 
 * description	: implement quick_sort by template
 */
#ifndef  MY_QSORT
#define  MY_QSORT
 
#include <iostream>         // for cout
#include <functional>                       // std::less<>()
#include <utility>                          // std::swap()

namespace myAlgorithm
{
    /* mid3() 取要排序元素的首尾中三个值大小的均值作为比较的依据 */
    template <typename RandomAccessIterator, typename Compare>
    typename std::iterator_traits<RandomAccessIterator>::value_type
    mid3(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
    {
        RandomAccessIterator mid = first + (last - first) / 2;
        if (!comp(*first, *mid))
            std::swap(*first, *mid);
        if (!comp(*first, *last-1))
            std::swap(*first, *(last-1));
        if (!comp(*mid, *last-1))
            std::swap(*mid, *(last-1));

        std::swap(*mid, *(last-1));
        return *(last-1);
    }

    template <typename RandomAccessIterator, typename Compare>
    void my_qsort(RandomAccessIterator first, 
                    RandomAccessIterator last, 
                    Compare comp)
    {
        if (first >= last-1)        // empty or only one element
            return;
        
        RandomAccessIterator l = first;
        RandomAccessIterator r = last;

        auto pivot = mid3(first, last, comp);   // pivot is at (last-1)
        --r;                    // skip last-1
        while (true) 
        {
            while (comp(*l, pivot))
                ++l;
            --r;
            while (comp(pivot, *r))
                --r;
            if (!(l < r))
                break;
            std::swap(*l, *r);
            ++l;
        }
        std::swap(*l, *(last-1));
        // RandomAccessIterator it = first;
        // for (it = first; it != last; ++it)
            // std::cout << *it << " ";
        // std::cout << std::endl;
        // recursive
        my_qsort(first, l, comp);
        my_qsort(l+1, last, comp);
    }

    template <typename RandomAccessIterator>
    void my_qsort(RandomAccessIterator first, 
                    RandomAccessIterator last)
    {
        myAlgorithm::my_qsort(first, last,
                        std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
    }

} /* myAlgorithm */ 

#endif /* ifndef MY_QSORT */
