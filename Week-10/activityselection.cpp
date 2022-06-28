#include<bits/stdc++.h>
using namespace std;
struct activity
{
    int index;
    int start;
    int finish;
};
bool cmp(activity a, activity b)
{
   if(a.finish  <= b.finish)
   return true;
   else return false;
}
void activity_selection(activity acc[],int n)
{
    sort(acc,acc+n,cmp);
    cout<<acc[0].index + 1<<" ";
    int total = 1;
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(acc[j].start >= acc[i].finish) {
        cout<<acc[j].index+1<<" ";
        total++;
        i = j;
        }
    }
    cout<<endl;
    cout<<"No. of non conflicting activites: "<<total<<"\n";
}
int main()
{
    int t;
    cin >> t;
    activity acc[t];
    for(int i= 0;i<t;i++)
    acc[i].index = i;
    for(int i= 0;i<t;i++)
    cin>>acc[i].start;
    for(int i= 0;i<t;i++)
    cin>>acc[i].finish;
    activity_selection(acc,t);

}
