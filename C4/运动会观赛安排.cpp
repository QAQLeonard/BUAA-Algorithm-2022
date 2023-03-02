#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
struct node
{
    int start;
    int end;
};
bool comp(const node &a, const node &b)
{
    return a.end < b.end;
}
void GREEDY_ACTIVITY_SELECTOR(vector<node> s, int n)
{
    int k = 1;
    int ans = 1;
    for (int m = 2; m <= n; m++)
    {
        if (s[m].start >= s[k].end)
        {
            ans++;
            k = m;
        }
    }
    cout << ans << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<node> v(n + 1);
    vector<int> s(n + 1, 0);
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].start >> v[i].end;
    }
    sort(v.begin() + 1, v.end(), comp);
    GREEDY_ACTIVITY_SELECTOR(v, n);
    return 0;
}
