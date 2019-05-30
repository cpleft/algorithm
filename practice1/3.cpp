/* file		: 3.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Apr 10 13:43:54 CST 2019
 * last update	: Wed Apr 10 13:44:14 CST 2019
 * 
 * description	: test my_qsort
 */

#include <iostream>
#include "my_qsort.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    vector<int> v;
    vector<int>::iterator it = v.begin();

    cout << "随机生成 1000000 个小于 10000 的自然数。" << endl;
    cout << "一共等待排序的数字有: " << 1000000 << " 个。" << endl;

    
    srand(time(0));
    for (int i = 0; i < 10000000; i++)
        v.push_back(rand()%10000);

    // for (it = v.begin(); it != v.end(); ++it)
        // cout << *it << " ";
    // cout << endl;
    
    clock_t startTime, endTime;
    startTime = clock();
    myAlgorithm::my_qsort(v.begin(), v.end());
    endTime = clock();

    // for (it = v.begin(); it != v.end(); ++it)
        // cout << *it << " ";
    // cout << endl;
    cout << "排序时间: " << (double)(endTime - startTime) / 
        CLOCKS_PER_SEC << "s" << endl;

    return 0;
}
