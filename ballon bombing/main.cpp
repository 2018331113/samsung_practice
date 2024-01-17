/*
https://w...content-available-to-author-only...e.com/watch?v=IFNibRVgFBo - Tushar Roy
 
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
 
Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167 
*/
 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int maxCoins(vector<int>& v){
    int n=v.size();
 
    vector<vector<int>> dp(n, vector<int>(n));
    for(int len=2; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int j = i+len-1;
            for(int k=i+1;k<j;k++){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
 
            }
        }
    }
    return dp[0][n-1];
 
 
}
 
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin>>n;
    vector<int>v(n+2,0);
    v[0]=v[n+1]=1;
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }
    cout<<maxCoins(v)<<endl;
    return 0;
}