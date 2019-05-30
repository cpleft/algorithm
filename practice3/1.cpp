/* file		: 1.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed May  8 12:01:29 CST 2019
 * last update	: Wed May  8 20:24:24 CST 2019
 * 
 * description	: Knapsack Problem. 
 * There are 5 items that have a value and 
 * weight list below, the knapsack can contain at most 100 Lbs. 
 * Solve the problem both as fractional knapsack
 * and 0/1 knapsack.
 * | value($US)   | 20 | 30  | 65  | 40 | 60  |
 * | weight(LBS)  | 10 | 20  | 30  | 40 | 50  |
 * | value/weight | 2  | 1.5 | 2.1 | 1  | 1.2 |
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define  MAX_KNAPSACK       100
#define  MAX_GOODS_NUM      50

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

void printusage()
{
    cout << "usage: 1.out {frac|01}" << endl;
}

bool comp(Good g1, Good g2)
{
    return g1.div > g2.div;
}

void fractional()
{
    int weightSum = 0;
    int valueSum = 0;
    int weightSumReserve = 0;
    int valueSumReserve = 0;
    sort(goods.begin(), goods.end(), comp);
    for (Good g:goods) {
        cout << g.value << " " << g.weight << " " << g.div << endl;
    }

    vector<Good>::iterator it = goods.begin();
    while (weightSum <= MAX_KNAPSACK && it != goods.end())
    {
        valueSumReserve = valueSum;
        weightSumReserve = weightSum;

        valueSum += (*it).value;
        weightSum += (*it).weight;

        ++it;
    }
    valueSumReserve += (*(--it)).div * (MAX_KNAPSACK - weightSumReserve);

    cout << "Total value is: " << valueSumReserve << endl;
    cout << "Total weight is: " << weightSumReserve << endl;
}

void zero_one()
{
    // use DP to solve 0-1 knapsack problem.
    int dp[MAX_GOODS_NUM][MAX_KNAPSACK];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= goods.size(); ++i) {
        for (int j = 1; j <= MAX_KNAPSACK; ++j) {
            if (j < goods[i-1].weight)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-goods[i-1].weight] 
                + goods[i-1].value);
        }
    }

    cout << "Total value is: " << dp[goods.size()][MAX_KNAPSACK] << endl;
}

int main(int argc, char* argv[])
{
    initGoods();
    if (argc != 2)
    {
        printusage();
        return -1;
    }
    else if (strcmp(argv[1], "frac") == 0)
    {
        fractional();
    }
    else if (strcmp(argv[1], "01") == 0)
    {
        zero_one();
    }
    else 
        printusage();
}

