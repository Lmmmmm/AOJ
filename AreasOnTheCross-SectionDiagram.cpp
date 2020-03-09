#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    stack<int> S1;
    stack<pair<int,int> > S2;
    int sum=0;
    char ch;
    for(int i = 0; cin>>ch;i++){
        if(ch == '\\') S1.push(i);//当要cin\的时候必须用双线,如果是\则将该字符位置的整数i压入栈中
        else if (ch == '/' && S1.size() >0){//如果是/,则从S1顶部取出与之对应的\的位置,算出二者距离并累加进总面积里
            int j = S1.top(); S1.pop();//这里的top指的是最上面,也就是最后放入的数字
            sum += i-j;
            int a = i-j;
            //取出S2中引用的多个面积,然后将新算出的面积压入S2(S2每一行对应的数据分别是该积水处最左侧的\的位置 和 该积水处当前的面积)
            //while主要处理的是对于比较深的积水处,我们不能一次性遍历完整个深水处,因此定义了一个S2.top.first >j,意思为只要是一个水池,那么就把他们的值叠加起来
            //这样做的好处是除非有多个积水池,不然都会统一到一行上
            while(S2.size()>0 &&S2.top().first >j){
                a += S2.top().second; S2.pop();//S2就只有一组,虽然top是访问栈顶,pop是取出最后入的(LIFO)
            }
            S2.push(make_pair(j,a));//算完的面积压入S2(避免S2为0的情况下没有push进去)
            // cout << "S2=" <<S2.top().first<<S2.top().second <<endl;
        }
    }

    vector<int> ans;
    while(S2.size()>0) {ans.push_back(S2.top().second); S2.pop();}
    reverse(ans.begin(),ans.end());
    cout << sum<<endl;
    cout << ans.size();
    for(int i = 0; i< ans.size(); i++){
        cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}