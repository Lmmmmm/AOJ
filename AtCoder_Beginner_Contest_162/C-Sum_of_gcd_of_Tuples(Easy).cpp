#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> 
using namespace std;

int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
int main()
{   
    int n;
    cin >> n;
    long long  num = 0;
    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1; k <= n ; k++ ){
                    int tmp = gcd(k,i);
                    num += gcd(tmp,j);
            }
        }
    }
    cout << num <<endl;
    return 0;
}
