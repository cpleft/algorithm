/* file		: my_heap.hpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Mar 27 12:15:54 CST 2019
 * last update	: Fri Mar 29 16:26:51 CST 2019
 * 
 * description	: implement user-defined algorithm heap by template.
 */

#ifndef  MY_HEAP_HPP
#define  MY_HEAP_HPP

#include <functional>                       // std::less<>()
#include <utility>                          // std::swap()


namespace myAlgorithm
{
    /* shift_up */
    template <typename RandomAccessIterator,
             typename Compare>
    void my_shift_up(RandomAccessIterator first, 
                        RandomAccessIterator last,
                        RandomAccessIterator head,
                        Compare comp)
    {
        const auto size = last - first;
        const RandomAccessIterator father = first - 1 + (head - first + 1) / 2;
        if (father >= first && !comp(*father, *head))
        {
            std::swap(*father, *head);
            myAlgorithm::my_shift_up(first, last, father, comp);
        }
    }
    
    /* shift_down */
    template <typename RandomAccessIterator,
             typename Compare>
    void my_shift_down(RandomAccessIterator first, 
                        RandomAccessIterator last,
                        RandomAccessIterator head,
                        Compare comp)
    {
        const auto size = last - first;
        const RandomAccessIterator l = first - 1 + (head - first + 1) * 2;
        const RandomAccessIterator r = first - 1 + (head - first + 1) * 2 + 1;
        RandomAccessIterator book = head;
        if (l < last && !comp(*head, *l))
            book = l;
        else 
            book = head;
        if (r < last && !comp(*book, *r))
            book = r;
        if (book != head)
        {
            std::swap(*book, *head);
            myAlgorithm::my_shift_down(first, last, book, comp);
        }
    }

    /* make_heap */
    template <typename RandomAccessIterator,
             typename Compare>
    void make_heap(RandomAccessIterator first, RandomAccessIterator last, 
                    Compare comp)
    {
        if (first == last)      // iterator point to nothing
            return;
        const auto size = last - first;
        for (RandomAccessIterator i = first+size/2-1; i >= first; --i)
            myAlgorithm::my_shift_down(first, last, i, comp);
    }
    template <typename RandomAccessIterator>
    void make_heap(RandomAccessIterator first, RandomAccessIterator last)
    {
            myAlgorithm::make_heap(first, last, std::less<typename RandomAccessIterator::value_type>());
    }

    /* push_heap */
    template <typename RandomAccessIterator>
    void push_heap(RandomAccessIterator first, RandomAccessIterator last)
    {
        myAlgorithm::push_heap(first, last, std::less<typename RandomAccessIterator::value_type>());
    }
    template <typename RandomAccessIterator,
             typename Compare>
    void push_heap(RandomAccessIterator first, RandomAccessIterator last,
                    Compare comp)
    {
        if (first == last)      // iterator point to nothing
            return;
        myAlgorithm::my_shift_up(first, last, last-1, comp);
    }

    /* pop_heap */
    template <typename RandomAccessIterator>
    void pop_heap(RandomAccessIterator first, RandomAccessIterator last)
    {
        myAlgorithm::pop_heap(first, last, std::less<typename RandomAccessIterator::value_type>());
    }
    template <typename RandomAccessIterator,
             typename Compare>
    void pop_heap(RandomAccessIterator first, RandomAccessIterator last,
                    Compare comp)
    {
        if (first == last)      // iterator point to nothing
            return;
        std::swap(*first, *(last-1));
        myAlgorithm::my_shift_down(first, last-1, first, comp);
    }
} /* myAlgorithm */ 




#endif /* ifndef MY_MAKE_HEAP_HPP */
