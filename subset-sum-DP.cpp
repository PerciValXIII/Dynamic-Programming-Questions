// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++


class Solution{   
public:
    
    bool isSubsetSum(int N, int arr[], int sum){
        
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
        
        return t[N][sum];
        
    }
    
    
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
