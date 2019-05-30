/* file		: bellman_ford.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Fri May 17 21:02:45 CST 2019
 * last update	: Fri May 17 21:18:34 CST 2019
 * 
 * description	: Bellman-Ford Algorithm
 */
#include <iostream>
#include <cstring>
using namespace std;

#define  MAX_V      20
#define  MY_INF     9999

int adj[MAX_V+1][MAX_V+1];      // from 1x1 on
int dis[MAX_V+1];              

int main()
{
    // input
    memset(adj, MY_INF, sizeof adj);
    adj[1][2] = -1;
    adj[1][3] = 3;
    adj[2][3] = 3;
    adj[2][4] = 2;
    adj[2][5] = 2;
    adj[4][2] = 1;
    adj[4][3] = 5;
    adj[5][4] = -3;
    memset(dis, MY_INF, sizeof dis);
    dis[1] = 0;             // source is 1

    int n = 5;
    for (int i = 1; i <= n-1; i++) {
        // for each edge
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                if (adj[j][k] < MY_INF) {
                    // relax edge(j, k)
                    if (dis[k] > dis[j] + adj[j][k])
                        dis[k] = dis[j] + adj[j][k];
                }
            }
    }
    // for each edge
    for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++) {
            if (dis[k] > dis[j] + adj[j][k]) {
                cout << "存在负回路！" << endl;
                return -1;
            }
        }

    // print result
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << endl;

    return 0;
}
