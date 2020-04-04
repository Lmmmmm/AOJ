#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;
 
int main()
{   
    long long n,k;
    cin >> n>>k;
 
    long long tmp = n % k;
 
    if(tmp <= abs(tmp-k))cout << tmp <<endl;
    else cout <<  abs(tmp-k)<< endl;
 
    return 0;
}