//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool dfs(int node,int vis[],int parent,vector<int> adj[]){
        
        vis[node] = 1;
        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                if(dfs(adjacentNode,vis,node,adj)==true){
                    return true;
                }
            }else if(adjacentNode!=parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,-1,adj)==true){
                    return true;
                }
            }
        }
        
        return false;;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends