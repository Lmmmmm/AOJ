#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Node{
    int key;
    Node *next, *prev;
};

Node *nil;

void init(){
    nil = (Node *)malloc(sizeof(Node));
    //c++ nil = new Node();
    nil->next = nil;
    nil->prev = nil;
}

//从链表搜索出值为key的结点O(n)
Node* listSearch(int key){
    Node *cur = nil->next; //从头结点后面的元素开始访问;
    while(cur != nil && cur->key != key) cur = cur->next;
    return cur;
}

void printList(){
    Node *cur = nil->next;
    int flag = 0;
    while(1){
        if(cur == nil) break;
        if(flag++ > 0) cout<<" ";
        cout << cur->key;
        cur=cur->next;
    }
    cout<<endl;
}

void deleteNode(Node *t){
    if(t == nil) return;//t为头结点是不做处理
    t->prev->next = t->next;
    t->next->prev = t->prev;
    // 在C++中，我们必须手动释放已删除结点的内存。这里的free是C语言标准库中的函数，用于释放已不需要的内存空间 delete(t)
    free(t);
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

//deleteKey函数可以删除包含指定key的结点，它会先通过listSearch函数搜索出
//key—致的结点t，然后再使用deleteNote(t) 删除该结点。
void deleteKey(int key){
    //删除搜索到的结点
    deleteNode(listSearch(key));
}

// 在链表头部添加元素key
void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));//c++ Node *x = new Node();
    x->key = key;
    //在头结点后添加元素(建议看图理解p86)
    x->next = nil->next;
    nil->next->prev = x;
    nil->next=x;
    x->prev = nil;
}

int main(){
    int n, key; 
    int size=0, np=0,nd=0;//这三个变量和这题没有本质性关联,np表示insert的次数,nd表示delete的次数,size则是链长
    cin >> n;

    char c[20];
    // getchar();
    init();
    for(int i = 0; i < n; i++){
        scanf("%s %d", c, &key);//尤其注意这里,当输入deleteFirst和deleteLast的时候后面是没有数字的,所以不能用cin >> c>>key;
        if(c[0] == 'i'){
            insert(key);
            np++;
            size++;
        }
        else if(c[0] == 'd'){
            if(strlen(c) > 6){
                if(c[6]=='F') deleteFirst();
                else if(c[6]=='L') deleteLast();

            }
            else {
                deleteKey(key);
                nd++;
            }
            size--;
        }
    }
    printList();
    return 0;
}

/*
往双向链表中添加元素时，只需要更改几个指针的指向，因此算法复杂度为o(1)
数组访问 A[i] 所消耗的时间固定，但表需要通过指针一步步寻找元素。因此当表中含有 W 个元素时，搜索算法的复杂度为 O(N)。
删除双向链表开头或末尾的元素仅需 0O( 1 ) 的复杂度，但删除包含特定 key 的元素时需要 按顺序遍历链表，所以算法复杂度为 o(N)。
这里介绍的链表的实现方法中，由于搜索和删除的算法复杂度都高达O(N), 因此对单个 链表来说实用价值不大。但是，它们在之后的章节中将作为其他数据结构的零部件(或者实现 其他数据结构所需的知识 )出现并发挥作用。
*/