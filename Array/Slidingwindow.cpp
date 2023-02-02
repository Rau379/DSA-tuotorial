/*

Given an array of integers of size ‘n’.
Our aim is to calculate the maximum sum of ‘k’ 
consecutive elements in the array.

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4 
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole
array is 2. . 
*/
// #include<bits/stdc++.h>
// using namespace std;


// int main()
// {
//     int n, k;
//     cin>>n>> k;
//     int arr[n];
//     int prefix[n];
//     for(int i=0; i<n; i++)
//     {
//         cin>> arr[i];
//         if(i==0)
//         {
//             prefix[0]=arr[0];
//         }
//         else{
//             prefix[i]=arr[i]+prefix[i-1];
//         }
//     }
//     int j=0;
//     int i=0;
//     int maxi_sum=INT_MIN;
//     int curr=0;
//     while(j<n)
//     {
//        curr+=arr[j];
//        if(j-i+1==k)
//        {
//         maxi_sum= max(curr, maxi_sum);
//         curr-=arr[i];
//         i++;
//        }
//        j++;
//     }
//     cout<<maxi_sum<<endl;
// }


/*      ------------------------2nd problem---------------------*/
/*
Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Example:

Input:
2
5
-8 2 3 -6 10
2
8
12 -1 -7 8 -15 30 16 28
3

Output:
-8 0 -6 -6
-1 -1 -7 -15 -15 0 . */

// #include<bits/stdc++.h>
// using namespace std;
// # define ll long long
//  ll int mod=1e9+7;
// #define pb Push_back
// int main()
// {
//     int n;
//      cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++)
//     {
//         cin>>arr[i];
//     }
//     int k; 
//     cin>>k;
//        vector<int>res;
            
//              int i=0, j=0;
//              deque<ll>q;

//              while(j<n)
//              {
//                 //if number is less than zero
//                 if(arr[j]<0)
//                 {
//                  q.push_back(arr[j]);
//                 }
//                 // window size 
//                 if(j-i+1<k)
//                 {
//                     j++;
//                 }
//                 else if(j-i+1==k)
//                 {
//                     if(q.size()==0)
//                     {
//                     res.push_back(0);
//                     }
//                     else
//                     {
//                         res.push_back(q.front());
//                         if(arr[i]<0)
//                         {
//                             q.pop_front();
//                         }
//                     }
//                     i++;
//                     j++;
//                 }
//              }
//              // printing the elements

//     for(auto i:res)
//     {
//         cout<<i <<" ";
//     }

// }

/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.

*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int ans=0;
	    int n= txt.length();
	   unordered_map<char, int>mp;
	   int cnt=0;
	   int k= pat.length();
	   for(int i=0; i<k; i++)
	   {
	       mp[pat[i]]++;
	   }
	   cnt= mp.size();
	   int i=0, j=0;
	   while(j<n)
	   {
	       // calculation part
          if(mp.find(txt[j])!=mp.end())
          {
              mp[txt[j]]--;
              if(mp[txt[j]]==0)
              {
                  cnt--;
              }
          }
          if(j-i+1<k)
          {
              j++;
          }
          else if(j-i+1==k)
          {
              // calculation for ans
              if(cnt==0) ans++;
              // sliding conditions
              if(mp.find(txt[i])!=mp.end())
              {
                  mp[txt[i]]++;
                  if(mp[txt[i]]==1)
                  {
                      cnt++;
                  }
              }
              i++;
              j++;
          }
	   }
	   return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends


 