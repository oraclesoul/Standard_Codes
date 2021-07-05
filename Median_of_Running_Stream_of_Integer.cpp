#include<bits/stdc++.h>
using namespace std;

int main()
{
   #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   
   priority_queue<int>mxpq;
   priority_queue<int,vector<int>,greater<int>>mnpq;

   // 1 2 3 4     5  6 7
   // mxpq         mnpq

   int a; 
   while(cin>>a)
   {
      if(mxpq.empty() || mxpq.top()>a) mxpq.push(a);
      else mnpq.push(a);

      if(mxpq.size()>mnpq.size()+1) 
      {
         mnpq.push(mxpq.top());
         mxpq.pop();
      }
      else if(mnpq.size()>mxpq.size()+1)
      {
         mxpq.push(mnpq.top());
         mnpq.pop();
      }
      // size difference will never exceed by 1 as updating as every new number come.
      
      if(mxpq.size()>mnpq.size())
      {
         cout<<mxpq.top()<<endl;
      }else if(mxpq.size()<mnpq.size())
      {
         cout<<mnpq.top()<<endl;
      }else
      {
         cout<<((double)(mxpq.top()+mnpq.top()))/2<<endl;
      }
   }

   return 0;
}
