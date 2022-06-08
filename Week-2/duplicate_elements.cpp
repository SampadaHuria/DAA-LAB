#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a[20],key,c=0,s,e;
        cin>>n;
        for(int i=0;i<n;i++)
        cin>>a[i];
        cin>>key;
         for(int s=0,e=n-1;s<e;s++,e--){
          if(a[s]==key && a[e]==key)
           c=c+2;
          else if(a[s]==key || a[e]==key)
          ++c;
      }
        if(c!=0)
        cout<<key<<" - "<<c<<endl;
        else cout<<"Key not Present "<<endl;
    }
}
