/*
Consider the example: arr[] = {{100, 20}, {60, 10}, {120, 30}}, W = 50.

Sorting: Initially sort the array based on the profit/weight ratio. The sorted array will be {{60, 10}, {100, 20}, {120, 30}}.

Iteration:

For i = 0, weight = 10 which is less than W. So add this element in the knapsack. profit = 60 and remaining W = 50 – 10 = 40.
For i = 1, weight = 20 which is less than W. So add this element too. profit = 60 + 100 = 160 and remaining W = 40 – 20 = 20.
For i = 2, weight = 30 is greater than W. So add 20/30 fraction = 2/3 fraction of the element. Therefore profit = 2/3 * 120 + 160 = 80 + 160 = 240 and remaining W becomes 0.
So the final profit becomes 240 for W = 50.

*/

//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Item {
    int value, weight;
    Item(int x, int y){
        this.value = x;
        this.weight = y;
    }
}

class GfG {
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
            String inputLine[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int w = Integer.parseInt(inputLine[1]);
            Item[] arr = new Item[n];
            inputLine = br.readLine().trim().split(" ");
            for(int i=0, k=0; i<n; i++){
                arr[i] = new Item(Integer.parseInt(inputLine[k++]), Integer.parseInt(inputLine[k++]));
            }
            System.out.println(String.format("%.6f", new Solution().fractionalKnapsack(w, arr, n)));
        }
    }
}
// } Driver Code Ends


/*
class Item {
    int value, weight;
    Item(int x, int y){
        this.value = x;
        this.weight = y;
    }
}
*/

class Solution
{
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        // Firstly we have to sort on the basis of value(profit)/weight ratio
        Arrays.sort(arr,(a,b)->{
            return Double.compare((double)b.value/(double)b.weight, (double)a.value/ (double)a.weight);
        });
        
        double maxProfit = 0;
        for(int i = 0; i < n ; i++){
            if(W >= arr[i].weight){
                W -= arr[i].weight;
                maxProfit += arr[i].value;
            }
            else{
                maxProfit += W * ((double) arr[i].value / (double) arr[i].weight);
                break;
            }
        }
        return maxProfit;
    }
}
