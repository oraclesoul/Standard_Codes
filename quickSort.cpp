#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v,int low,int high)
{
   // taking first element as pivot
   int pivot = low;
   int i=low+1;
   int j=low+1;
   while(j<=high)
   {
      if(v[j]<v[pivot])
      {
         swap(v[i],v[j]);
         i++;
      }
      j++;
   }
   swap(v[i-1],v[pivot]);
   return i-1;
}

void quickSort(vector<int>&v,int low,int high)
{
   if(low<high)
   {
      int pivotPos = partition(v,low,high);
      quickSort(v,low,pivotPos-1);
      quickSort(v,pivotPos+1,high);
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
   quickSort(v,0,n-1);

   for(auto i:v) cout<<i<<" ";
   cout<<endl;


   return 0;
}
