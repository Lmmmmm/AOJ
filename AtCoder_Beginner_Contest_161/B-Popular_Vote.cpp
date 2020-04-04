#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;
 
int main()
{   
    int n,m;
    cin >> n >> m;
    int a[n];
    int cnt = 0;
    int all = 0;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        all += a[i];
    }
    double ave = double(all) / (4 * m);
 
    for(int i = 0; i< n; i++){
        if(double(a[i])  >= ave) cnt++;
    }
 
    if(cnt >= m)  cout << "Yes"<<endl; 
    else  cout <<"No"<<endl;
    return 0;
}