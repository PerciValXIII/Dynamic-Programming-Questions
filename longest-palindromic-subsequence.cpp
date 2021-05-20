// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int longestPalinSubseq (string A);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << longestPalinSubseq (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


//User function Template for C++

int longestPalinSubseq (string S)
{
    int n = S.size();
    string S2 = S;
    reverse(S.begin(),S.end());
    
    int t[n+1][n+1];
    memset(t,0,sizeof(t));
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(S[i-1] == S2[j-1])
                t[i][j] = 1+t[i-1][j-1];
                
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    
    return t[n][n];
}
