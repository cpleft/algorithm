/* file		: 1.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Sun May 26 15:09:00 CST 2019
 * last update	: Wed May 29 08:32:54 CST 2019
 * 
 * description	: 
 * 0/1 Knapsack Problem. There are 5 items that have a value and 
 * weight list below, the knapsack can contain at most 100 Lbs.
 * Solve the problem using back-tracking algorithm and try to draw 
 * the tree generated.
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define  MAX_KNAPSACK       100
#define  MAX_GOODS_NUM      5

struct good {
    int value;
    int weight;
    double div;
};
typedef struct good Good;
vector<Good> goods;

void initGoods()
{
    Good g1;
    g1.value = 20;
    g1.weight = 10;
    g1.div = 2;
    Good g2;
    g2.value = 30;
    g2.weight = 20;
    g2.div = 1.5;
    Good g3;
    g3.value = 65;
    g3.weight = 30;
    g3.div = 2.1;
    Good g4;
    g4.value = 40;
    g4.weight = 40;
    g4.div = 1;
    Good g5;
    g5.value = 60;
    g5.weight = 50;
    g5.div = 1.2;

    goods.push_back(g1);
    goods.push_back(g2);
    goods.push_back(g3);
    goods.push_back(g4);
    goods.push_back(g5);
}

int curValue = 0;
int curWeight = 0;
int bestValue = 0;

void traceback(int p)               // the p-th good
{
    if (p > MAX_GOODS_NUM)         // no good remain
        return;

    if (p == MAX_GOODS_NUM)
    {
        if (curWeight > MAX_KNAPSACK)
            return;
        if (curValue > bestValue)
        {
            bestValue = curValue;
            return;
        }
    }

    for (int i = 0; i <= 1; ++i)
    {
        if (i == 0)                 // do not take this good
            traceback(p+1);
        else {                      // take this good
            curValue += goods[p-1].value;
            curWeight += goods[p-1].weight;
            traceback(p+1);
            curWeight -= goods[p-1].weight;
            curValue -= goods[p-1].value;

        }
        
    }
}

int main()
{
    initGoods();
    traceback(1);
    cout << bestValue << endl;

    return 0;
}
