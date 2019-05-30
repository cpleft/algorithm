#include <iostream>
#include <cstring>
using namespace std;

#define  MY_INF    9999

int adj[6][6];      // from 1x1 on

int main()
{
    memset(adj, MY_INF, sizeof adj);
    adj[1][2] = -1;
    adj[1][3] = 3;
    adj[2][3] = 3;
    adj[2][4] = 2;
    adj[2][5] = 2;
    adj[4][2] = 1;
    adj[4][3] = 5;
    adj[5][4] = -3;

    int dis[6];
    bool vis[6];
    memset(dis, MY_INF, sizeof dis);
    memset(vis, false, sizeof vis);
    vis[1] = true;

    for (int i = 1; i <= 5; ++i)
        cout << dis[i] << " ";
    cout << endl;
    for (int i = 1; i <= 5; ++i)
        if (adj[1][i] < MY_INF)
            dis[i] = adj[1][i];

    while (true) {
        int min = 0;
        for (int i = 1; i <= 5; ++i)
            if (dis[min] > dis[i] && vis[i] == false)
                min = i;
        if (min == 0)
            break;

        vis[min] = true;
        for (int i = 1; i <= 5; ++i)
            if (adj[min][i] < MY_INF)
                if (dis[i] > dis[min] + adj[min][i])
                    dis[i] = dis[min] + adj[min][i];
    }
    for (int i = 1; i <= 5; ++i)
        cout << dis[i] << " ";
    cout << endl;
}
