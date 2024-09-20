// Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

// Examples:

// Input: n = 6, arr[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output: 1 
// Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.
// Input: n = 6, arr[] = {3, 34, 4, 12, 5, 2} , sum = 30
// Output: 0 
// Explanation: There is no subset with sum 30.


#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
    int memo[101][10001];
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        memset(memo, -1, sizeof(memo));
        return subset(arr, sum, arr.size());
    }
    private :
    bool subset(vector<int> &arr,int sum, int n){
        if(n == 0) return sum == arr[n-1];
        // include
        if(sum == 0) return true;
        
        if(memo[n][sum] != -1) return memo[n][sum];
        
        if(arr[n-1] <= sum){
         return memo[n][sum] = subset(arr, sum - arr[n-1], n-1) || 
                               subset(arr, sum, n-1);
        }
        //exclude
        else if(arr[n-1] > sum){
         return memo[n][sum] = subset(arr, sum, n-1);
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
