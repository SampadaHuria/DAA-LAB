#include<iostream>
using namespace std;
int main()
{
    int t,n,key,j,a[100];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        cin>>a[i];
        cin>>key;
        int c=0;
        for(j=0;j<n;j++)
        {
            if(a[j]==key)
            {
                ++c;
                break;
            }
            else ++c;
        }
        if(a[j]==key)
        cout<<"Present "<<c<<endl;
        else cout<<"Not present "<<c<<endl;
    }
}
