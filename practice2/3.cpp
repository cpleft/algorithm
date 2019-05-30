/* file		: 3.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Apr 10 19:56:43 CST 2019
 * last update	: Wed Apr 10 20:35:20 CST 2019
 * 
 * description	: 
 * Longest Common Substring. The following are some instances.
 * a) X: xzyzzyx Y: zxyyzxz
 * b) X:MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFIS
 * RLLAIVAD
 * Y:MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG
 *
 * solution     :
 * c[i][j] = 0                              if i=0 or j=0
 *         = c[i-1][j-1] + 1                if i,j>0 && X[i]==Y[j]
 *         = 0                              if i,j>0 && X[i]!=Y[j]
 */
#include <iostream>
#include <vector>
using namespace std;

#define  MAX_LEN  200


int main()
{
    char X[MAX_LEN];
    char Y[MAX_LEN];
    char Z[MAX_LEN];
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
            else
            {
                c[i][j] = 0;
                b[i][j] = 0;            // left or right
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

    // print result
    // find largest number in c[][]
    int max = 0;
    int i_max = 0;
    int j_max = 0;
    for (int i = 0; i <= lX; i++)
        for (int j = 0; j <= lY; j++)
            if (c[i][j] > max)
            {
                max = c[i][j];
                i_max = i;
                j_max = j;
            }
    for (int i = 0; i < max; i++)
    {
        cout << X[i_max-max+1+i] << " ";
    }
    cout << endl;

    return 0;
}
