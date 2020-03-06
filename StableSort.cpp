#include <iostream>
#include <algorithm>
using namespace std;

struct Card{ char suit, value;};
//冒泡是稳定的,所以选择排列也是看和冒泡的排列顺序是否一样来判断稳定性
//稳定性通俗地讲就是能保证排序前2个相等的数其在序列的前后位置顺序和排序后它们两个的前后位置顺序相同
void bubble(struct Card C1[], int n){
    for(int i = 0; i< n; i++){
        for(int j = n-1; j >= i+ 1;j--){
            if(C1[j].value < C1[j-1].value) swap(C1[j],C1[j-1]);
        }
    }
}

void selection(struct Card C2[], int n){
    int minj;
    for(int i = 0; i< n; i++){
        minj = i;
        for(int j=i; j<n;j++){
            if(C2[j].value < C2[minj].value) minj = j;
        }
        swap(C2[i],C2[minj]);
    }
}

bool isStable(struct Card C1[], struct Card C2[], int n){
    for(int i = 0; i< n; i++){
        if(C1[i].suit!= C2[i].suit) return false;
    }
    return true;
}

void print(struct Card C[], int n){
    for(int i=0; i< n; i++){
        if(i > 0) cout << " ";
        cout << C[i].suit<<C[i].value;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    Card C1[n],C2[n];
    for(int i = 0; i< n; i++) cin >> C1[i].suit >> C1[i].value;
    for(int i = 0; i< n; i++) C2[i] = C1[i];

    bubble(C1, n);
    selection(C2,n);

    print(C1,n);
    cout << "Stable"<<endl;

    print(C2,n);
    if(isStable(C1,C2,n))cout <<"Stable"<<endl;
    else cout << "Not stable" << endl;
    return 0;
}