/* file		: 4.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Apr 10 13:53:55 CST 2019
 * last update	: Wed Apr 10 16:37:01 CST 2019
 * 
 * description	: 
 * Give a divide and conquer algorithm for the following problem: you are given two
 * sorted lists of size m and n, and are allowed unit time access to the ith element of
 * each list. Give an O(lg m + lgn) time algorithm for computing the kth largest
 * element in the union of the two lists. (For simplicity, you can assume that the
 * elements of the two lists are distinct).
 */
#include <iostream>
#include <queue>
using namespace std;

template <typename Container, typename Compare>
typename Container::value_type my_mergePop(Container &c1, Container &c2, 
                Compare comp)
{
    typename Container::value_type temp;
    if (!c1.empty() && !c2.empty())
    {
        if (comp(c1.front(), c2.front()))
        {
            temp = c1.front();
            c1.pop();
            return temp;
        }
        else {
            temp = c2.front();
            c2.pop();
            return temp;
        }
    }
    else if (!c1.empty() && c2.empty())
    {
        temp = c1.front();
        c1.pop();
        return temp;
    }
    else if (c1.empty() && !c2.empty())
    {
        temp = c2.front();
        c2.pop();
        return temp;
    }
    else {
    }
}

template <typename Container>
typename Container::value_type my_mergePop(Container &c1, Container &c2)
{
    my_mergePop(c1, c2, std::less<typename Container::value_type>());
}


int main()
{
    queue<double> v1;
    queue<double> v2;
    int sm, sn;
    cout << "Input the size of list m:" << endl;
    cin >> sm;
    cout << "Input list m:" << endl;
    while (sm--)
    {
        double x;
        cin >> x;
        v1.push(x);
    }

    cout << "Input the size of list n:" << endl;
    cin >> sn;
    cout << "Input list n:" << endl;
    while (sn--)
    {
        double x;
        cin >> x;
        v2.push(x);
    }

    int k;
    cout << "Input k:" << endl;
    cin >> k;

    int size = v1.size() + v2.size();

    while (k-- && size--)
    {
        double x = my_mergePop(v1, v2);
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
