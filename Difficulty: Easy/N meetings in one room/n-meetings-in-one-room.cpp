//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    static bool comparator(pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    }
    
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>> time;
        for(int i=0;i<n;i++){
            time.push_back({start[i],end[i]});
        }
        
        sort(time.begin() , time.end(),comparator);
        
        int count = 1;
        int lastMeeting = time[0].second;
        
        int i=1;
        while(i!=n){
            if(time[i].first>lastMeeting){
                count++;
                lastMeeting = time[i].second;
            }
            i++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends