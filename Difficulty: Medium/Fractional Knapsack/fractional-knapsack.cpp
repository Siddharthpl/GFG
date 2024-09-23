//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        vector<double> ratio;
        for(int i=0;i<n;i++){
            double a = (arr[i].value*1.00000000)/arr[i].weight;
            ratio.push_back(a);
            
        }
        
        priority_queue<pair<double,pair<int,int>>> maxi;
        
        for(int i=0;i<n;i++){
            maxi.push({ratio[i],{arr[i].value,arr[i].weight}});
        }
        
        double ans = 0;
        
        while(w!=0 && !maxi.empty()){
            auto front = maxi.top();
            double ratio = front.first;
            int value = front.second.first;
            int weight = front.second.second;
            maxi.pop();
            
            if(w>weight){
                ans += value;
                w -= weight;
            }else{
                double valueToInclude = ratio*w;
                ans += valueToInclude;
                w = 0;
            }
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends