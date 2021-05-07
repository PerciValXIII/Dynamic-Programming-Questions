// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        cout << cutRod(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


// User function Template for C++

int cutRod(int price[], int n) {

vector<int> length;
int i;
for(i = 1;i<=n;i++)
    length.push_back(i);

// int size = length.size();
int t[n+1][n+1];

for(i=0;i<n+1;i++)
{
    t[i][0] = 0;
}

for(i=0;i<n+1;i++)
{
    t[0][i] = 0;
}


for(int i=1;i<n+1;i++)
{
    for(int j =1;j<n+1;j++)
    {   
        if(length[i-1]<=j)
            t[i][j] = max(t[i-1][j],price[i-1] +t[i][j-length[i-1]]);
            
        else
            t[i][j] = t[i-1][j];
    }
}


return t[n][n];
}

