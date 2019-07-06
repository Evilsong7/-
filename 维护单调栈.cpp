/*
链接：https://ac.nowcoder.com/acm/contest/984/A
来源：牛客网

一些Farmer John的N头牛（1≤N≤80,000）头发很糟糕！由于每头奶牛都对自己凌乱的发型有着自我意识，因此FJ想要计算其他可以看到其他奶牛头顶的奶牛的数量。
每头奶牛我都有一个特定的高度hi（1≤hi≤1,000,000,000），并且站在一排面向东方（在图中右侧）的奶牛中。因此，牛可以看到她前面的奶牛头顶（即奶牛i + 1，i + 2等），只要这些奶牛严格比奶牛短。
考虑这个例子：
= 
= = 
= - =面向右边的奶牛 - > 
= = = 
= - = = =
= = = = = =

1 2 3 4 5 6奶牛＃1可以看到奶牛的发型＃2,3,4 
奶牛＃2可以看到没有奶牛的发型
奶牛＃3可以看到奶牛的发型＃4 
奶牛＃4可以看到没有奶牛的发型
牛＃ 5可以看到牛的发型6 
牛＃6可以看到没有奶牛！
设ci表示从牛i可以看到发型的奶牛数量; 请计算c1到cN的总和。对于这个例子，所需的是答案3 + 0 + 1 + 0 + 1 + 0 = 5。
输入描述：
第1行：奶牛的数量，N。
行2..N + 1：行i + 1包含一个整数，即牛i的高度。
输出描述：
第1行：一个整数，它是c1到cN的总和。
示例1
输入
复制
6
10
3
7
4
12
2
输出
复制
五
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10;

int n,m;
ll a[maxn];
ll dp[maxn];
ll res[maxn];
int main(){
    cin >> n ;
    for(int i=0;i<n;i++) cin >> a[i];
    ll top=0,ans=0;
    for(int i=0;i<n;i++){
        if(a[i]<res[top]) ans+=top;
        else{
            while(a[i]>=res[top]&&top){
                top--;
            }
            ans+=top;
        }
        res[++top]=a[i];
    }
    cout << ans << endl;
    return 0;
}


/*10 3 7 4 12 2
5  2 4 3 6 1
*/


