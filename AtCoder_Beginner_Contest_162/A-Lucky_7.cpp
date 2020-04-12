#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main()
{   
    int num;
    cin >> num;
    int tmp = 0,flag = 0;
    while(num > 0){
        tmp = num % 10;
        if(tmp == 7) {
            flag = 1;
            break;
        }
        num /= 10;
    }
    if(flag == 1)cout << "Yes" <<endl;
    else cout << "No" <<endl;
    return 0;
}
