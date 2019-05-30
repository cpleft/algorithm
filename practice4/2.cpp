/* file		: 2.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed May 29 08:34:55 CST 2019
 * last update	: 
 * 
 * description	: 
 * Solve the 8-Queen problem using back-tracking algorithm.
 */
#include <iostream>
#include <cstring>
using namespace std;

#define  N_Queen  8

int matrix[N_Queen+1][N_Queen+1];

bool conflict()
{
    for (int i = 1; i <= N_Queen; ++i)          // for each row
        for (int j = 1; j <= N_Queen; ++j)      // for each colume
            if (matrix[i][j] != 0) {            // a Queen is exist
                // 横
                for (int k = 1; k <= N_Queen; ++k)
                    if (k != j && matrix[i][k] != 0)    // conflict
                        return true;
                // 竖
                for (int k = 1; k <= N_Queen; ++k)
                    if (k != i && matrix[k][j] != 0)    // conflict
                        return true;
                // main-diagonal, 
                for (int k = i-1, l = j-1; k >= 1 && l >= 1; --k, --l)
                    if (matrix[k][l] != 0)
                        return true;
                for (int k = i+1, l = j+1; k <= N_Queen && l <= N_Queen; 
                        ++k, ++l)
                    if (matrix[k][l] != 0)
                        return true;
                // counter-diagonal
                for (int k = i-1, l = j+1; k >= 1 && l <= N_Queen; --k, ++l)
                    if (matrix[k][l] != 0)
                        return true;
                for (int k = i+1, l = j-1; k <= N_Queen && l >= 1; ++k, --l)
                    if (matrix[k][l] != 0)
                        return true;
            }
    return false;
}

int sum = 0;

void traceback(int p)
{
    if (p > N_Queen) {
        sum++;
        return;
    }

    for (int i = 1; i <= N_Queen; ++i) {
        matrix[p][i] = 1;
        if (!conflict())         // if do not conflict
            traceback(p+1);
        matrix[p][i] = 0;
    }
}

int main()
{
    traceback(1);
    cout << sum << endl;

    return 0;
}
