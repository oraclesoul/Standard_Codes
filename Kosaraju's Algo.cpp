class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void DFS1(vector<int> adj[],vector<bool>&vis,int v,vector<int>&stk)
    {
       vis[v] = true;
       for(auto i:adj[v])
       {
          if(!vis[i]) DFS1(adj,vis,i,stk);
       }
       stk.push_back(v);
       return;
    }

    void DFS2(vector<int> adj[],vector<bool>&vis,int v)
    {
       vis[v] = true;
       for(auto i:adj[v])
       {
          if(!vis[i]) DFS2(adj,vis,i);
       }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool>vis(V,false);
        vector<int>stk;
        for(int i=0;i<V;i++)
        {
           if(!vis[i]) DFS1(adj,vis,i,stk);
        }
        vector<int>tadj[V];
        for(int i=0;i<V;i++)
        {
           for(auto j:adj[i]) tadj[j].push_back(i);
        }
        vis.clear();
        vis.assign(V,false);
        int cnt = 0;
        while(!stk.empty())
        {
           int v = stk.back();
           stk.pop_back();
           if(vis[v]) continue;
           cnt++;
           DFS2(tadj,vis,v);
        }
        return cnt;
    }
};
