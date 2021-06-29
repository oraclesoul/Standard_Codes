#include<bits/stdc++.h>
using namespace std;

// 0 based pos and answer
int leftP(int n,int k)
{
   if(n==1) return 0;
   return (k+leftP(n-1,k))%n;
}

int main()
{
   #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   
   int n , k; cin>>n>>k;
   cout<<leftP(n,k)<<endl;

   return 0;
}
