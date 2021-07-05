#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&v)
{
   int n = v.size();
   for(int i=1;i<n;i++)
   {
      int val = v[i];
      int j;
      for(j=i-1;j>=0;j--)
      {
         if(v[j]>val) v[j+1] = v[j];
         else break;
      }
      v[j+1] = val;
   }
}

int main()
{
   #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   
   int n; cin>>n;
   vector< int > v(n);
   for(auto &i:v) cin>>i;
   insertionSort(v);
   for(auto i:v) cout<<i<<" "; cout<<endl;


   return 0;
}
