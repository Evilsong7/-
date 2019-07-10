/*
题目描述

Illyasviel："你想要最长不下降子序列吗？"

star-dust："好啊！"

Illyasviel："老板，给我整两个最长不下降子序列，要最大的。"

求序列 aa 中的两个不相交的不下降子序列使得他们的元素和的和最大，子序列可以为空。

注 1：序列 aa 不下降的定义是不存在 l<rl<r 且 a_l>a_ra 
l
​	
 >a 
r
​	
 
注 2：两个子序列不相交的定义是：不存在 a_ia 
i
​	
  即在第一个子序列中也在第二个子序列中。


输入描述

第一行一个数字 nn 代表序列 aa 的长度。

接下来一行 nn 个数，第 ii 个数代表 a_ia 
i
​	
 。

数据范围：

2 \le n \le 5002≤n≤500
1\leq a_i \leq 10^51≤a 
i
​	
 ≤10 
5
 

输出描述

一行一个整数代表两个不相交的不下降子序列的元素和的最大值。


样例输入 1 

9
5 3 2 1 4 2 1 4 6
样例输出 1

22

*/


#include <bits/stdc++.h>
#define N 505
using namespace std;

int a[N],dp[N][N];

int main(){
    int n,i,j,k,ans=0;
    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(k=1;k<=n;k++){
        for(i=0;i<k;i++){
            for(j=i;j<k;j++){
                if(a[i]<=a[k]) dp[j][k]=max(dp[j][k],dp[i][j]+a[k]);
                if(a[j]<=a[k]) dp[i][k]=max(dp[i][k],dp[i][j]+a[k]);
            }
        }
    }
    for(i=0;i<=n;i++)
            for(j=i+1;j<=n;j++)
                ans=max(ans,dp[i][j]);
    cout<<ans<<endl;
}
