#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[20],c=0,key,diff;
        for(int i=0;i<n;i++)
        cin>>a[i];
        cin>>key;
        for(int i=0;i<n;i++)
        {
            diff = a[i]+key;
            for(int j=0;j<n;j++)
          {
              if(a[j]==diff)
              ++c;
          }
        }
        cout<<c<<endl;
    }
}
