#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v,int low,int mid,int high)
{
   vector<int>tmp; // temporary store the sorted data
   int i = low , j = mid+1;
   while(i<=mid && j<= high)
   {
      if(v[i]<v[j]) 
      {
         tmp.push_back(v[i]);
         i++;
      }else
      {
         tmp.push_back(v[j]);
         j++;
      }
   }

   while(i<=mid)
   {
      tmp.push_back(v[i]);
      i++;
   }

   while(j<=high)
   {
      tmp.push_back(v[j]);
      j++;
   }

    for(int k=high;k>=low;k--)
    {
       v[k] = tmp.back();
       tmp.pop_back();
    }
}

void mergeSort(vector<int>&v,int low,int high)
{
   if(low<high)
   {
      int mid = low + (high-low)/2;
      mergeSort(v,low,mid);
      mergeSort(v,mid+1,high);
      merge(v,low,mid,high);
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
   mergeSort(v,0,n-1);

   for(auto i:v) cout<<i<<" ";
   cout<<endl;


   return 0;
}
