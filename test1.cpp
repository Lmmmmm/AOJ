#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

// int main(void)
// {
//    int 
// }


// int sum(int n)
// {
// 	int sum = 1;
// 	for (int i = 2; i < n; i++)
// 	{
// 		if (n % i == 0){
// 			sum += i;
//             cout << i << endl;
//         }
// 	}
// 	return sum;
// }
 
 
int main()
{
	int n;
	cin >> n;
    int cnt = 0;
    for (int i = 2; i*i < n; i++){
        int tmp = n;
        // while(tmp >= ){
        //     if(tmp % i == 0) tmp /= i;
        //     else if(tmp % i == 1) {
        //         cnt++;
        //         break;
        //     }
        //     // cout << tmp <<endl;
        // }
        if(tmp % i == 0 && tmp % (i+1+i) == 0) cnt++;
    }
 
 
	cout << cnt+2 << endl;
	
	return 0;
}