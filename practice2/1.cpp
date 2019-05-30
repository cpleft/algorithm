/* file		: 1.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Apr 10 17:19:06 CST 2019
 * last update	: Wed Apr 10 19:31:14 CST 2019
 * 
 * description	: 
 * Matrix-chain product. The following are some instances.
 * a) <3, 5, 2, 1,10>
 * b) <2, 7, 3, 6, 10>
 * c) <10, 3, 15, 12, 7, 2>
 * d) <7, 2, 4, 15, 20, 5>
 */

#include <iostream>
#include <cstring>
using namespace std;

#define  MAX_N  200
#define  INF    99999999

void printOptimalParens(int s[][MAX_N], int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j]+1, j);
        cout << ")";
    }
}

int main()
{
    // input
    int p[MAX_N];
    int n;          // n matrices
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    int m[MAX_N][MAX_N];
    int s[MAX_N][MAX_N];
    memset(m, 0, sizeof(m));                    // m[1...n][1...n]
    memset(s, 0, sizeof(s));                    // s[1...n-1][2...n]

    for (int l = 2; l <= n; l++)
    {
        cout << "当l=" << l << "时：" << endl;
        for (int i = 1; i <= n-l+1; i++)
        {
            int j = i+l-1;
            m[i][j] = INF;
            cout << "i=" << i << ", j=" << j << endl;
            for (int k = i; k <= j-1; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                cout << "q=" << "m(" << i << "," << k << ")" << "+"
                    << "m(" << k+1 << "," << j << ")" << "+" << p[i-1] 
                    << "*" << p[k] << "*" << p[j] << "=" << q << endl;
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
            cout << "min q =" << m[i][j] << endl;
            cout << "----------s(" << i << ", " << j << ")=" << s[i][j] << endl;
        }
    }

    cout << m[1][n] << endl;
    printOptimalParens(s, 1, n);

    return 0;
}
