/* file		: 2.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Apr 10 19:30:56 CST 2019
 * last update	: Wed Apr 10 19:56:02 CST 2019
 * 
 * description	: 
 * Longest Common Subsequence (LCS). The following are some instances.
 * a) X: xzyzzyx Y: zxyyzxz
 * b) X:MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFIS
 * RLLAIVAD
 * Y:MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFIS
 * RLLAIVAG
 *
 * solution     :
 * c[i][j] = 0                              if i=0 or j=0
 *         = c[i-1][j-1] + 1                if i,j>0 && X[i]==Y[j]
 *         = max(c[i-1][j], c[i][j-1])      if i,j>0 && X[i]!=Y[j]
 */

#include <iostream>
#include <vector>
using namespace std;

#define  MAX_LEN  200

void printLCS(int b[][MAX_LEN], char X[], int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1)
    {
        printLCS(b, X, i-1, j-1);
        cout << X[i] << " ";
    }
    else if (b[i][j] == 0)
        printLCS(b, X, i, j-1);
    else if (b[i][j] == 2)
        printLCS(b, X, i-1, j);
    else ;
}


int main()
{
    char X[MAX_LEN];
    char Y[MAX_LEN];
    char Z[MAX_LEN];
    int it = 0;
    int lX, lY, lZ;
    int c[MAX_LEN][MAX_LEN];
    int b[MAX_LEN][MAX_LEN];
    
    // input
    cout << "Input the length of X:" << endl;
    cin >> lX;
    cout << "Input X:" << endl;
    for (int i = 1; i <= lX; ++i) {
        cin >> X[i];
    }
    cout << "Input the length of Y:" << endl;
    cin >> lY;
    cout << "Input Y:" << endl;
    for (int i = 1; i <= lY; ++i) {
        cin >> Y[i];
    }
    
    // init
    for (int i = 1; i <= lX; i++)
    {
        c[i][0] = 0;
    }
    for (int i = 0; i <= lY; i++)
    {
        c[0][i] = 0;
    }

    for (int i = 1; i <= lX; i++)
    {
        for (int j = 1; j <= lY; j++)
        {
            if (X[i] == Y[j])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;            // upleft
            }
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;            // up
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 0;            // left
            }
        }
    }

    for (int i = 0; i <= lX; i++){
        for (int j = 0; j <= lY; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= lX; i++){
        for (int j = 0; j <= lY; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    printLCS(b, X, lX, lY);

    return 0;
}
