#include <iostream>
#include <limits.h>
#include <vector>
#include <stack>
using namespace std;

vector<int> p;
vector<long long> r(10005,0);

long long cut(vector<int>p,int n)
{
    if(n==0) return 0;
    for(int j=1;j<=n;j++)
    {
        long long int q=INT32_MIN;
        for(int i=1;i<=j;i++)
        {
            q=max(q,p[i]+r[j-i]);
        }
        r[j]=q;
    }
    return r[n];
}

int main()
{
    int length;
    cin>>length;
    int temp;
    p.push_back(0);
    for(int i=0;i<length;i++)
    {
        cin>>temp;
        p.push_back(temp);
    }
    // cout<<length<<" "<<p[0]<<endl;
    cout<<cut(p,length)<<endl;

    return 0;
}