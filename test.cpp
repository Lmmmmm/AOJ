#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main()
{   
    long double l;
    cin >> l;
    long double ans;
    if( (int)l %3 != 0) ans = l/3.0* (l/3.0-3.3621e-4932)*(l/3.0+3.3621e-4932);
    else ans = pow(l/3.0,3);
    cout << ans <<endl;
    return 0;
}