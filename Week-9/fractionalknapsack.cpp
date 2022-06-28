#include<bits/stdc++.h>
using namespace std;
struct item
{
    int value;
    int wt;
    item(int value , int wt)
    {
        this->value = value;
        this->wt = wt;
    }
};
bool cmp(item a, item b)
{
   double a1 = (double)a.value / (double)a.wt;
   double a2 = (double)b.value / (double)b.wt;
   return a1 > a2;
}
double fractional_knapsack(int total_w, item arr[], int n)
{
    sort(arr,arr+n,cmp);
    double profit = 0.0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].wt <= total_w){
            total_w -=arr[i].wt;
            profit += arr[i].value;
        }
        else{
            profit += arr[i].value * ((double)total_w / (double)arr[i].wt);
            break;
        }
    }
    return profit;
}
int main()
{
    int n;
    item arr[] = {{6,6},{2,10},{1,3},{8,5},{3,1},{5,3}};
    int weight;
    cin >> weight;
    n = sizeof(arr) / sizeof(arr[0]);
    double value  = fractional_knapsack(weight,arr,n);
    cout<<"Maximum value : "<<value<<endl;
    return 0;
}
