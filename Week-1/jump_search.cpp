#include<iostream>
using namespace std;
int Jump_Search(int *a,int n, int key)
{
    int jmp = 1,flag = 0,comp=0;
       while(jmp<n)
    {
        if(a[jmp]==key)
        {
            comp++;
            flag = 1;
        }
        else if(a[jmp]>key)
        {
            for(int i=jmp/2;i<jmp;i++)
            {
                if(a[i]==key)
                    flag = 1;
            }
        }
       jmp = jmp*2;
    }

    if(flag == 1)
    {
        cout<<"Present"<<endl;
    }
    else
    cout<<"Not Present"<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
         int *a =  new int [n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int key;
        cin>>key;
         Jump_Search(a,n,key);
    }
}
