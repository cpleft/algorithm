/* file		: 2.cpp 
 * by		: yang yi   16130120200	    429426523@qq.com
 * date		: Wed May  8 20:24:41 CST 2019
 * last update	: Wed May  8 20:24:41 CST 2019
 * 
 * description	: describe
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;      // n jobs
    cin >> n;
    int jobs[50];
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i];
    }

    sort(jobs, jobs+n);

    int sum = 0;
    int stage = 0;
    for (int i = 0; i < n; ++i) {
        sum += stage + jobs[i];
        stage += jobs[i];
    }
    double ACT = (double)sum / n;
    cout << "Average Complete Time is: " << ACT << endl;

    return 0;
}
