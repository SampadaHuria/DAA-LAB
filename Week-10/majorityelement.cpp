#include<bits/stdc++.h>
using namespace std;
void majority_element(int arr[],int n)
{
    int max = INT_MIN;
   for(int i=0;i<n;i++)
   {
      if(arr[i] > max)
      max = arr[i];
   }
   int result[max]={0};
   for(int i=0;i<n;i++)
   {
    result[arr[i]]+=1;
   }
   for(int i=0;i<max;i++)
   {
    if(result[i] >= (n/2))
    {
        cout<<"Yes\n";
        return;
    }
   }
   cout<<"No\n";
}
void median(int arr[],int n)
{
    int i = n/2;
    if(n%2!=0) //odd number
    {
       cout<<arr[i]<<endl;
    }
    else{
        int j = n/2 - 1;
        int sum = arr[i] + arr[j];
        cout<<sum/2<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    majority_element(a,n);
    median(a,n);
}
