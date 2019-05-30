/* file		: 4.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed Apr 10 20:10:47 CST 2019
 * last update	: Wed Apr 10 20:58:35 CST 2019
 * 
 * description	: 
 * Max Sum. The following is an instance.
 * a) (-2 , 11 , -4 , 13 , -5 , -2)
 *
 * solution     :
 * s[i] = max(s[i-1]+S[i], S[i])            i 是子段的后界
 */
#include <iostream>
using namespace std;

#define  MAX_LEN  200

int main()
{
    int S[MAX_LEN];

    // input
    int n;
    cout << "Input the length of sequence:" << endl;
    cin >> n;
    cout << "Input the sequence" << endl;
    for (int i = 1; i <= n; i++)
        cin >> S[i];

    int sum = 0;
    int max = 0;
    for (int i = 1; i <=n ; i++)
    {
        sum += S[i];
        if (sum > max)
            max = sum;
        if (sum < 0)
            sum = 0;
    }

    cout << "The Max length is:" << max << endl;

    return 0;
}
