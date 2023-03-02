#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    pair<long long, long long> a, b, c;

    while (t--)
    {
        scanf("%lld%lld%lld%lld%lld%lld", &a.first, &a.second, &b.first, &b.second, &c.first, &c.second);
        long double S = (long double)((b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second)) / 2;
        printf("%.1llf\n", abs(S));
    }
    return 0;
}
