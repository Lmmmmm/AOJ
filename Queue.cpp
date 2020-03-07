#include <iostream>
#include <string>
using namespace std;
#define LEN 100005

typedef struct pp {
    char name[100];
    int t;
} P;
P Q[LEN];
int head, tail, n, q;

/*
考察
用数组实现队列时,关键在于如何有效利用内存,
以及如何将 enqueue 和 dequeue 的算法 复杂度控制在0(1)。
实际上，只要使用环形缓冲区，就可以同时以复杂度0(1)实现enqueue和dequeue的操作。
*/

//enqueue函数用于在tail所指的位置添加X.由于元素数增加了1,所以tail也随之加1.
//此时tail如果超过了数组容量上限(MAX-1)则重置为0.另外,当队列为满时进行报错处理。
void enqueue(P x){
    Q[tail] = x;
    tail = (tail+1) % LEN;
}

// dequeue函数会将所指的队头元素暂时存人变量x,随后加1并返冋x的值.
//此时如果超过了数组容量上限(MAX -1) 则重置为0。
P dequeue(){
    P x =Q[head];
    head = (head+1) % LEN;
    return x;
}

int min(int a,int b) {return a < b ? a : b;}

int main(){
    cin >> n >> q;
    for(int i = 1; i< n+1; i++) cin >> Q[i].name>> Q[i].t;
    P u;
    int elaps =0,c;

    head = 1; //指示队列的开头位置
    tail = n+1; //指示队列末尾+1的位置(为了添加新元素)

    /* 模拟 */
    while( head != tail){//判断head和tail的值是否相等来判断队列是否为空
        u = dequeue();
        c = min(q,u.t);//执行时间片q或者或许时间u.t的处理
        u.t -= c;//计算剩余的所需时间
        elaps +=c;//累计已过的时间
        if(u.t > 0) enqueue(u);//如果处理尚未结束则重新添加至队列
        else cout << u.name << " "<<elaps<< endl;
    }

    return 0;
}