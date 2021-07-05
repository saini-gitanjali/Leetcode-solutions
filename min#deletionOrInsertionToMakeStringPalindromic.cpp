// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        int n = S.length();
        string rev = S;
        reverse(rev.begin(), rev.end());
        
        int dp[n+1][n+1];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(S[i-1]==rev[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }   
        return n - dp[n][n];
    } 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
return 0;
}  // } Driver Code Ends