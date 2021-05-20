// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(char* X, char* Y, int m, int n)
    {
        int t[m+1][n+1];
        for(int i=0;i<m+1;i++)
            t[i][0] = 0;
        
        for(int i=0;i<n+1;i++)
            t[0][i] = 0;
        
        
        for(int i = 1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                
                if(X[i-1] == Y[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
        return (m+n)-t[m][n];
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

  // } Driver Code Ends
