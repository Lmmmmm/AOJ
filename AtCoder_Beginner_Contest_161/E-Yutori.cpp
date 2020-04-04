#include <iostream>
#include <string>
 
using namespace std;

int main()
{
  int n, k, c; string s; cin >> n >> k >> c >> s;
  
  int a[200000]; int b[200000];
  for (int i = 0, idx = 0; i < n; ++i) if (s[i] == 'o') {a[idx++] = i; i += c;}
  for (int i = n-1, idx = k-1; i >= 0; --i) if (s[i] == 'o') {b[idx--] = i; i -= c;}
  
  for (int i = 0; i < k; ++i) if (a[i] == b[i]) cout << a[i]+1 << endl;
  return 0;
}