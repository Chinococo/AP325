#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define int long long
#define vec vector<int>
#define vecs vector<string>

#define maxlen 8
#define over 1e8

using namespace std;
int n,p,c=0;
int data[36];

multiset<int> s1,s2;
set<int> s1_,s2_;

void cal1(int ans,int now,int end,int count)
{
    if(now>end)
    {
        if(count>0)
        {
            s1.insert(ans);
            s1_.insert(ans);
        }

        return;
    }
    cal1((ans*data[now])%p,now+1,end,count+1);
    cal1(ans,now+1,end,count);
}
void cal2(int ans,int now,int end,int count)
{
    if(now>end)
    {
        if(count>0)
        {
            s2.insert(ans);
            s2_.insert(ans);
        }

        return;
    }
    cal2((ans*data[now])%p,now+1,end,count+1);
    cal2(ans,now+1,end,count);
}

signed main() {

    cin>>n>>p;
    for(int i=0;i<n;i++)
        cin>>data[i];
    cal1(1,0,n/2,0);
    cal2(1,n/2,n-1,0);
    for(auto i : s1_)
    {
        if(i==1)
        {
            cout<<i<<"*"<<i<<"="<<i*i<<" %p "<<(i*i)%p;
            c+=(int)s1_.count(i)*(int)s2.count(1);
            c%=p;
            continue;
        }





    }
    cout<<c;

}