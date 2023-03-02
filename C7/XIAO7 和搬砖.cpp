#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct brick
{
    int m; // 块数
    int d; // 每块价值
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int N, T;
        cin >> N;
        vector<brick> v;
        
        for (int i = 0; i < N; i++)
        {
            brick b;
            cin >> b.m >> b.d;
            v.push_back(b);
        }
        sort(v.begin(), v.end(), [](brick a, brick b)
             { return a.d < b.d; });
        cin >> T;
        vector<long long int> s;
        for (int i = 0; i < T; i++)
        {
            int x;
            cin >> x;
            s.push_back(x);
        }
        sort(s.begin(), s.end());
        long long int F = 1;
        long long int ans = 0;
        long long int step = 0;
        long long int j = 0;
        for (int i = 0; i < N; i++)
        {
            brick b = v[i];

            while (j < T && !(step + b.m < s[j]))
            {
                ans += F * b.d * (s[j] - step);
                b.m -= s[j] - step;
                step += s[j] - step;
                j++;
                F++;
            }
            ans += F * b.d * b.m;
            step += b.m;
        }
        cout << ans << endl;
    }
}