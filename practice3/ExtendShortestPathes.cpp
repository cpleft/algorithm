#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    int W[7][7];      // from 1x1 on
    int L[7][7];
    memset(W, 9999, sizeof W);
    memset(L, 9999, sizeof L);
    int n, m;                   // 0~n, m edges
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int fr, to, we;
        cin >> fr >> to >> we;
        W[fr][to] = we;
    }
    for (int i = 1; i <= n; ++i) {
        W[i][i] = 0;
    }

    // Init L
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            L[i][j] = W[i][j];
        }
    }
    // print L
    cout << endl;
    cout << "1: " << endl;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // SLOW-ALL-PAIRS=SHORTEST-PATHS
    for (int o = 2; o <= n-1; ++o) {
        int L_[7][7];      // from 1x1 on
        memset(L_, 9999, sizeof L_); 

        for (int i = 1; i <= 6; ++i) {
            for (int j = 1; j <= 6; ++j) {
                for (int k = 1; k <= 6; ++k) {
                    L_[i][j] = min(L_[i][j], L[i][k] + W[k][j]);
                }
            }
        }

        // print L_
        cout << o << ": " << endl;
        for (int i = 1; i <= 6; ++i) {
            for (int j = 1; j <= 6; ++j) {
                cout << L_[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        // replace L with L_
        for (int i = 1; i <= 6; ++i) {
            for (int j = 1; j <= 6; ++j) {
                L[i][j] = L_[i][j];
            }
        }

    }

    return 0;
}


/* input
6 10
1 5 -1
2 1 1
2 4 2
3 2 2
3 6 -8
4 1 -4
4 5 3
5 2 7
6 3 10
6 2 5
*/
