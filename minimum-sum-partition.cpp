// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	 void isSubsetSum(int N, int arr[], int sum, vector<int> &v){
        
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
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                } 
                
                else //not include element as its value greater than sum
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        for(int j=0;j<sum+1;j++)
        {   
            if(t[N][j]==1)
                v.push_back(j);    
        }
        
    }
	
	
	int minDiffernce(int arr[], int n) 
	{ 
	
	int range = 0;
	for(int i=0;i<n;i++)
	{
	    range=range+arr[i];
	}
	int sum = range/2;
	
	vector<int> v;
	
	isSubsetSum(n,arr,sum,v);
	
	int mn = INT_MAX;
	for(int i =0;i<v.size();i++)
	{
	    mn = min(mn,range-2*v[i]);
	}
	
	return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
