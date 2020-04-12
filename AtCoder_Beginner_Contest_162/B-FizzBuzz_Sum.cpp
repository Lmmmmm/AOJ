#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;
 
int main()
{   
    int n;
    cin >> n;
    int cnt = 0;
    long long num = 1,sum = 0;
    while(num <= n){
        if(num % 3 != 0 && num % 5 != 0){
            sum += num;
            cnt++;
        }
        num++;
    }
 
    cout << sum << endl;
    return 0;
}