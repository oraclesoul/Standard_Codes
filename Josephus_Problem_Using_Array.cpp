#include<bits/stdc++.h>
using namespace std;

int findLastP(vector<int>&v,int k,int start)
{
   // for(auto i:v) cout<<i<<" "; cout<<endl;
   if(v.size()==1) return v[0];
   int pos =( start +k - 1 )%v.size();
   v.erase(v.begin()+pos);
   
   return findLastP(v,k,pos);
}

int main()
{
   #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   
   int n,k; cin>>n>>k;

   vector< int > v(n);
   for(int i=0;i<n;i++) v[i] = i+1;

   int lastPersonAlive = findLastP(v,k,0);
   cout<<lastPersonAlive<<endl;

   return 0;
}
