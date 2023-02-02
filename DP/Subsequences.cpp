#include<bits/stdc++.h>
using namespace std;

// best LIS at a Level
int n; 
int arr[100001];
int dp[100001];
int rec(int level)
{
    //best LIS ending at Level
    // base case
    if(level<0) return 0;
    // cache case
   if(dp[level]!=-1) return dp[level];
    // compute
    int ans=0;
    for(int prev_taken=0; prev_taken<level; prev_taken++)
    {
        // condition
        if(arr[prev_taken]<arr[level])
        {
            ans=max(ans,  1+rec(prev_taken));
        }
    }
    // save and return
      return dp[level]=ans;
}
void solve()
{
   cin>>n;
   for(int i=0; i<n; i++)
   {
    cin>>arr[i];
   }
   memset(dp, -1, sizeof(dp));
   int best=0;
   for(int i=0; i<n; i++)
   {
    best= max(best, rec(i));
   }
   cout<<best<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}