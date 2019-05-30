/* file		: 4.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Fri May 17 21:20:02 CST 2019
 * last update	: Fri May 17 21:23:34 CST 2019
 * 
 * description	: Floyd
 */
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
    n = 5;
    W[1][2] = -1;
    W[1][3] = 3;
    W[2][3] = 3;
    W[2][4] = 2;
    W[2][5] = 2;
    W[4][2] = 1;
    W[4][3] = 5;
    W[5][4] = -3;
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
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
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
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << D_[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        // replace D with D_
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                D[i][j] = D_[i][j];
            }
        }
        
    }

    return 0;
}
