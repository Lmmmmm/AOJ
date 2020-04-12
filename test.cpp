#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <algorithm> 
using namespace std;

int main()
{   
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long cnt = 0;
    for(int i = 0; i <= n-3; i++){
        for(int j = i+1; j<= n-2; j++){
            if(s[i] == s[j]) continue;
            for(int k = j+1; k <= n-1 ; k++ ){
                if(s[j] == s[k] || s[i] == s[k] || j-i == k-j)continue;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}