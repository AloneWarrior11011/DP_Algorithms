// You are given weights and values of items, and put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
// Note that we have only one quantity of each item.
// In other words, given two integer arrays val and wt which represent values and weights associated with items respectively. 
// Also given an integer W which represents knapsack capacity, find out the maximum sum values subset of val[] such that the sum 
// of the weights of the corresponding subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don't pick it (0-1 property).

// Examples :

// Input: W = 4, val[] = {1,2,3}, wt[] = {4,5,1}
// Output: 3
// Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 
// Input: W = 3, val[] = {1,2,3}, wt[] = {4,5,6}
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int memo[1001][1001];
    
    int knapsack01(int idx, int w, vector<int>& wt, vector<int>& val){
        if(idx == 0) return 0;
        
        if(memo[idx][w] != -1) return memo[idx][w];
        int ans = 0;
        
        // Include (take item)
        if(wt[idx-1] <= w){
          ans += val[idx-1] + knapsack01(idx - 1, w - wt[idx-1], wt, val);  
        }
        // exclude (not take that item (skip))
        ans = max(ans, knapsack01(idx - 1, w, wt, val));
        
        memo[idx][w] = ans;
        return ans;
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = wt.size();
        
        memset(memo, -1, sizeof(memo));
        return knapsack01(n, W, wt, val);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends
