#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define int long long
#define vec vector<int>
#define vecs vector<string>


#define maxlen 8
#define over 1e8


using namespace std;
int p;
int pow_(int x,int y)
{

    if(y==1)
        return x;

    int t =pow_(x,y/2)%p;
    if(y&1)
        return (((t*t)%p)*x)%p;
    else
        return (((t*t)%p))%p;
}

signed main() {
    int x,y;
    cin>>x>>y>>p;
    cout<<pow_(x,y);
}
