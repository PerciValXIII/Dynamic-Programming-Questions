// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int n , int sum )
    {
       
        long long int t[n+1][sum+1];
        
        //initialization
        int i;
        int j;
        for(i=0;i<n+1;i++)
            t[i][0] = 1;
        
        for(i=1;i<sum+1;i++)
            t[0][i] = 0;
            
        
        for(i =1;i<n+1;i++)
        {
            for(j =1;j<sum+1;j++)
            {
                if(S[i-1]<=j)
                {
                    t[i][j]= t[i-1][j] + t[i][j-S[i-1]];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][sum];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
