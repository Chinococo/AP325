#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define int long long
#define vec vector<int>
#define vecs vector<string>

#define x first
#define y second
#define maxlen 8
#define over 1e8

using namespace std;
int f(int x)
{
    //printf("f(%d)=%d\n",x,2*x-1);
    return 2*x-3;
}
int g(int x,int y)
{
    //printf("g(%d,%d)=%d\n",x,y,x+2*y-3);
    return 2*x+y-7;
}
int h(int x,int y,int z)
{
    //printf("g(%d,%d)=%d\n",x,y,x+2*y-3);
    return 3*x-2*y+z;
}
signed main() {
    IOS;
    stack<pair<char,int>> s;
    deque<int> pram;

    int index=0;
    string input,temp;
    getline(cin,input);
    stringstream ss;
    ss<<input;
    while(ss>>temp)
    {
        if(temp[0]=='f'||temp[0]=='g'||temp[0]=='h')
            s.push(make_pair(temp[0],0));
        else
        {
            //cout<<s.top().x;
            s.top().y++;
            pram.push_back(stoll(temp));
            while(!s.empty())
            {
                if(s.top().x=='f'&&s.top().y>0)
                {
                    int t=f(pram.back());
                    s.pop();
                    pram.pop_back();
                    pram.push_back(t);
                    if(!s.empty())
                    s.top().second++;

                    continue;
                }
                if(s.top().x=='g'&&s.top().y>1)
                {
                    int p1,p2;
                    p1=pram.back();
                    pram.pop_back();
                    p2=pram.back();
                    pram.pop_back();
                    int t=g(p2,p1);
                    s.pop();
                    pram.push_back(t);
                    if(!s.empty())
                    s.top().second++;

                    continue;
                }
                if(s.top().x=='h'&&s.top().y>2)
                {
                    int p1,p2,p3;
                    p1=pram.back();
                    pram.pop_back();
                    p2=pram.back();
                    pram.pop_back();
                    p3=pram.back();
                    pram.pop_back();
                    int t=h(p3,p2,p1);
                    s.pop();
                    pram.push_back(t);
                    if(!s.empty())
                        s.top().second++;
                    continue;
                }
                break;
            }

        }
    }
    cout<<pram.back();



}