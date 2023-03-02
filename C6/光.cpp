#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long c = std::__gcd(180 * b - 2 * a, 360 * b);
        long long d = 360 * b / c;
        printf("%lld\n", d - 1);
    }
}