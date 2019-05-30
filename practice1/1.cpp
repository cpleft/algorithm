/* file         : practice1/1.cpp
 * by           : yangyi    429426523@qq.com    16130120200
 * date         : Mon Mar 18 16:35:54 CST 2019
 * last update  : Tue Mar 19 11:13:37 CST 2019
 * 
 * 描述一个运行时间为 Θ(nlgn) 的算法，给定n个整数集合 S 和另一个整数 x，
 * 该算法能确定 S 中是否存在两个其和刚好为 x 的元素。
 */

#include <iostream>
#include <set>
using namespace std;

#define MAX_N   1000

int main()
{
    int n, x;
    cin >> n >> x;
    set<int> bst;
    set<int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        bst.insert(a);
    }

    for (it = bst.begin(); it != bst.end(); ++it)
    {
        int t = x - (*it);
        if (bst.find(t) != bst.end())           // successfully find t
        {
            cout << 1 << endl;
            return 0;
        }
    }

    // failed to find t
    cout << 0 << endl;
    return 0;
}
