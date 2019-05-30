/* file		: 3.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed May  8 20:25:10 CST 2019
 * last update	: 
 * 
 * description	: Single-source shortest paths
 * adjacency matrix
 * |   | A | B  | C | D  | E |
 * | A |   | -1 | 3 |    |   |
 * | B |   |    | 3 | 2  | 2 |
 * | C |   |    |   |    |   |
 * | D |   | 1  | 5 |    |   |
 * | E |   |    |   | -3 |   |
 */
#include <iostream>
#include <cstring>
using namespace std;

#define  MAX_V  20
#define  MY_INF    9999

int adj[MAX_V+1][MAX_V+1];      // from 1x1 on

void userInput()
{
    memset(adj, MY_INF, sizeof adj);
    int n, m, e;                   // 0~n, m edges, e for end node
    cin >> n >> m >> e;
    for (int i = 1; i <= m; i++)
    {
        int fr, to, we;
        cin >> fr >> to >> we;
        adj[fr][to] = we;
    }
}

void defaultInput() 
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
}

void dijkstra()
{
    // The default single source is A(adj[1][1])
    int dis[MAX_V+1];
    bool vis[MAX_V+1];
    memset(dis, MY_INF, sizeof dis);
    memset(vis, false, sizeof vis);
    vis[1] = true;

    for (int i = 1; i <= MAX_V; ++i)
        if (adj[1][i] != MY_INF)
            dis[i] = adj[1][i];

    for (int i = 1; i <= MAX_V; ++i)
        cout << dis[i] << " ";
    cout << endl;

    while (true) {
        int min = 0;
        for (int i = 1; i <= MAX_V && vis[i] == false; ++i)
            if (dis[min] > dis[i])
                min = i;
        if (min == 0)
            break;

        vis[min] = true;
        for (int i = 1; i <= MAX_V; ++i)
            if (adj[min][i] != MY_INF)
                if (dis[i] > dis[min] + adj[min][i])
                    dis[i] = dis[min] + adj[min][i];
    } 
    for (int i = 1; i <= MAX_V; ++i)
        cout << dis[i] << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2 && argc != 1)
        cout << "usage: a.out [user-defined]" << endl;
    else if (argc == 1) 
    {
        defaultInput();
        dijkstra();
    }
    else if (strcmp(argv[1], "user-defined") == 0) 
    {
        userInput();
        dijkstra();
    }
    else
        cout << "usage: a.out [user-defined]" << endl;

    return 0;
}

/* 为什么设置的 MY_INF 是 9999，但在运行时是 2....... ？ */
