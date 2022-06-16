#include<iostream>
using namespace std;
void count_sort(char *a,int n)
{
    char f[26] = {0};
    for(int i=0;i<n;i++)
    f[a[i]-'a']++;
    int max=1,index=0;
    for(int i=0;i<26;i++)
    {
        if(max<f[i])
        {
            max = f[i];
            index = i;
        }
    }
    if(max!=1)
    {
        char ch = 'a' + index;
        cout<<ch<<"-"<<max;
    }
    else
    cout<<"No duplicates present!\n";
}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
    cin>>n; 
    char* a = (char*)new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    count_sort(a,n);
    }
}
