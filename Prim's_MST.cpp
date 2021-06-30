#include<bits/stdc++.h>
using namespace std;

int MST_Prims(int V,vector<pair<int,int>> adj[])
{
   priority_queue< pair< int , int > > pq;
   pq.push({0,0});
   
   vector<bool>mst_included(V,false);
   vector<int>mst(V,0);
   while(!pq.empty())
   {
      pair<int,int> a = pq.top();
      pq.pop();
      if(mst_included[a.second]) continue;
      mst_included[a.second] = true;
      mst[a.second] = -a.first;
      for(auto i:adj[a.second])
      {
         if(!mst_included[i.first])
         {
            pq.push({-i.second,i.first});
         }
      }
   }

   int sum = 0;
   for(auto i:mst) sum += i;
   return sum;

}

int main()
{
   #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   
   int V , E; 
   cin>>V>>E;
   vector< pair<int,int> > adj[V];
   while(E--)
   {
      int a,b,c; cin>>a>>b>>c;
      adj[a].push_back({b,c});
      adj[b].push_back({a,c});
   }

   int mst_cost = MST_Prims(V,adj);
   cout<<mst_cost<<endl;


   return 0;
}
