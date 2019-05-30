/* file		: 2.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Apr 10 10:46:37 CST 2019
 * last update	: Wed Apr 10 10:46:42 CST 2019
 * 
 * description	: test implemented my_priority_queue
 */

#include "my_priority_queue.hpp"
#include "my_heap.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    myContainer::my_priority_queue<int> pq;
    cout << "随机生成 30 个小于 10000 的自然数。" << endl;
    cout << "一共等待排序的数字有: " << 30 << " 个。" << endl;

    clock_t startTime, endTime;
    startTime = clock();
    for (int i = 0; i < 30; ++i) {
        pq.push(rand()%10000);
    }

    while (pq.size() != 0)
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    endTime = clock();
    cout << "排序时间: " << (double)(endTime - startTime) / 
        CLOCKS_PER_SEC << "s" << endl;

    return 0;
}
