//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
            int outde[V];
            vector<int> adjrev[V];
            memset(outde,0,sizeof(outde));
             for(int i=0;i<V;i++)
             {
               for(auto c:adj[i])
               {
                    outde[i]++;
                    adjrev[c].push_back(i);
               }  
             }
             queue<int>q;
             for(int i=0;i<V;i++)
             {
                    if(outde[i]==0)
                    {
                        q.push(i);
                    }
             }
             vector<int>v;
             while(q.size()>0)
             {
                int tp=q.front();
                v.push_back(tp);
                q.pop();
                for(auto c:adjrev[tp])
                {
                    outde[c]--;
                    if(outde[c]==0) q.push(c);
                }
             }
             sort(v.begin(),v.end());
            return v;
         } 
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends