#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int W[7][7];      // from 1x1 on
    int D[7][7];
    memset(W, 9999, sizeof W);
    memset(D, 9999, sizeof D);
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
    // Init D
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            D[i][j] = W[i][j];
        }
    }
    // print D
    cout << endl;
    cout << "0: " << endl;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int k = 1; k <= n; ++k) {
        int D_[7][7];      // from 1x1 on
        memset(D_, 9999, sizeof D_); 

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                D_[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }

        // print D_
        cout << k << ": " << endl;
        for (int i = 1; i <= 6; ++i) {
            for (int j = 1; j <= 6; ++j) {
                cout << D_[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        // replace D with D_
        for (int i = 1; i <= 6; ++i) {
            for (int j = 1; j <= 6; ++j) {
                D[i][j] = D_[i][j];
            }
        }
        
    }

    return 0;
}
