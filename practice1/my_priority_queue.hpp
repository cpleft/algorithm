/* file		: my_priority_queue.hpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Mar 27 12:17:00 CST 2019
 * last update	: Wed Mar 27 12:17:00 CST 2019
 * 
 * description	: implement user-defined container my_priority_queue by template.
 */

#ifndef  MY_P_Q_
#define  MY_P_Q_

#include <vector>
#include "my_heap.hpp"
#include <functional>           // std::less<>()   std::greater<>()

namespace myContainer
{
    template <typename T, 
             typename Container = std::vector<T>, 
             typename Compare = std::less<typename Container::value_type> >
    class my_priority_queue
    {
    public:
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef Container container_type;

    protected:
        Compare comp;
        Container c;

    public:
        /* constructors */
        my_priority_queue(const Compare& cmp = Compare(),
                            const Container& cont = Container())
            : comp(cmp), c(cont)
        {
            myAlgorithm::make_heap(c.begin(), c.end(), comp);
        }


        /* operator */
        void push(const value_type& x)
        {
            c.push_back(x);
            myAlgorithm::push_heap(c.begin(), c.end(), comp);
        }

        void pop()
        {
            myAlgorithm::pop_heap(c.begin(), c.end(), comp);
            c.pop_back();
        }

        bool empty() const { return c.empty(); }

        size_type size() const { return c.size(); }

        const value_type& top() const { return c.front(); }

    };
}

#endif
