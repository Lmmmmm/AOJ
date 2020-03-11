#include <iostream>
// #include<stack>
// #include<string>
// #include<vector>
#include <algorithm>
using namespace std;

int Binarysearch(int A[], int key, int n)
{
    int left = 0, right = n, mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (A[mid] == key)
            return 1;
        if (A[mid] < key)
            left = mid + 1;
        else if (A[mid] > key)
            right = mid;
    }
    return 0;
}

int main()
{
    int n, q, A[100000], key, sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> key;
        if (Binarysearch(A, key, n))
            sum++;
    }
    cout << sum << endl;
    return 0;
}