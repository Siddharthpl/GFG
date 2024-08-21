//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    int count =0;
    
    if(s.length()<2 || s.length()%2 == 1){
        return -1;
    }
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if( s[i] == '{'){
            st.push(s[i]);
        }else{
            if(!st.empty() && st.top() != s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    }
    
        while(!st.empty()){
            char a = st.top(); st.pop();
            char b = st.top(); st.pop();
            
            if(a==b) count = count+1;
            else count = count+2;
        }
    
   
    
    return count;
    
    
    
    
}