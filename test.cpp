#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main()
{   
    int k;
    cin >>k;

    int cnt = 1;
    long res = 1;
    if(k <= 10) cout << k <<endl;

// 15 > 9
// 15 -> 6

    while(k >= 9*cnt){
        k -= 9*cnt;
        cnt++;
        res *= 10;
    }
    cout << res << " " << cnt<<endl;
// 2000 3  2100 2101 2102 2103
    res *= k / cnt;
    return 0;
}