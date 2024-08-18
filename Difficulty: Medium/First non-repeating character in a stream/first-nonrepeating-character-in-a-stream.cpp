//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public: 
		string FirstNonRepeating(string A){
		    unordered_map<char,int> freq;
		    queue<char> q;
		    string ans = "";
		    
		    for(int i=0;i<A.length();i++){
		        char ch = A[i];
		        freq[ch]++;
		        
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(freq[q.front()] == 1){
		                ans.push_back(q.front());
		                break;
		            }
		            else{
		                q.pop();
		            }
		        }
		        
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends