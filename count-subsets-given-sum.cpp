// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

#define mod 1000000007


	public:
	int perfectSum(int arr[], int N, int sum)
	{
        int t[N+1][sum+1];
        
        //initialization
        int i;
        for(i=0;i<N+1;i++)
            t[i][0] = 1;
        
        for(i=1;i<sum+1;i++)
            t[0][i] = 0;    
        
        
         for(int i=1;i<N+1;i++){
            for(int j =1;j<sum+1;j++){
                if(arr[i-1] <= j)//include or not include the element
                {
                    t[i][j] = t[i-1][j-arr[i-1]]%mod + t[i-1][j]%mod;
                } 
                
                else //not include element as its value greater than sum
                {
                    t[i][j] = t[i-1][j]%mod;
                }
            }
        }
        
        return t[N][sum]%mod;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
