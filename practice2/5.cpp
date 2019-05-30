/* file		: 5.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Apr 10 20:58:09 CST 2019
 * last update	: Wed Apr 10 22:38:13 CST 2019
 * 
 * description	: 
 * Shortest path in multistage graphs. Find the shortest path from 0 to 15 for the following
 * graph.
 * A multistage graph is a graph (1) G=(V,E) with V partitioned into K >= 2 disjoint subsets such that if
 * (a,b) is in E, then a is in V i , and b is in V i+1 for some subsets in the partition; and (2) | V 1 | = | V K | = 1.
 *
 * solution     :
 *
 */
#include <iostream>
#include <cstring>
using namespace std;

#define  MAX_LEN  200
#define  INF  99999

int main()
{
    // input
    int adjacency_matrix[MAX_LEN][MAX_LEN];
    memset(adjacency_matrix, 0, sizeof(adjacency_matrix));
    int n, m, e;                   // 0~n, m edges, e for end node
    cin >> n >> m >> e;
    for (int i = 1; i <= m; i++)
    {
        int fr, to, we;
        cin >> fr >> to >> we;
        adjacency_matrix[fr][to] = we;
        adjacency_matrix[to][fr] = we;
    }

    int dp[MAX_LEN];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    bool Vset[MAX_LEN];
    memset(Vset, false, sizeof(Vset));
    Vset[0] = 1;
    bool TempVset[MAX_LEN];
    int flag = 1;           // if found the end node

    // the distance from node 0
    while (flag)    // each stage
    {
        memset(TempVset, false, sizeof(TempVset));
        for (int i = 0; i <= n; i++)
        {
            if (Vset[i] == true)
            {
                for (int j = i; j <= n; j++)
                {
                    if (adjacency_matrix[i][j] > 0)
                        TempVset[j] = true;
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            if (TempVset[i] == true)
            {
                int min = INF;
                for (int j = 0; j <= n; j++)
                {
                    if (Vset[j] == true)
                    {
                        if (adjacency_matrix[i][j] > 0)
                        {
                            int t = dp[j] + adjacency_matrix[i][j];
                            if (t < min)
                                min = t;
                        }
                    }
                }
                dp[i] = min;
                if (i == e)         // find the end
                {
                    flag = 0;
                }
            }
        }
        swap(Vset, TempVset);
    } // end while

    cout << dp[e] << endl;

    return 0;
}

/* the input data: 
15 30 15
0 1 5
0 2 3
1 3 1
1 4 3
1 5 6
2 4 8
2 5 7
2 6 6
3 7 6
3 8 8
4 7 3
4 8 5
5 8 3
5 9 3
6 8 8
6 9 4
7 10 2
7 11 2
8 11 1
8 12 2
9 11 3
9 12 3
10 13 3
10 14 5
11 13 5
11 14 2
12 13 6
12 14 6
13 15 4
14 15 3
*/
