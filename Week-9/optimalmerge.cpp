#include<bits/stdc++.h>
using namespace std;
int optimal_merge(int files[],int n)
{
    sort(files,files+n);
    int sum1 = files[0], sum2 = 0;
    for(int i=1;i<n;i++) {
        sum1 += files[i];
        sum2 += sum1;
    }
    return sum2;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    cin >> ar[i];
    int cost = optimal_merge(ar,n);
    cout<<cost;
    return 0;
}
