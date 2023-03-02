#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9
long long Gcd(long long a, long long b)
{
    long long c;
    while (b)
    {
        c = a;
        a = b;
        b = c % b;
    }
    return a;
}

int main()
{
    int n, t;
    cin >> t;
    while (t--)
    {
        vector<long long int> arr(1000 + 5, 1);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            if (i != 1)
            {
                arr[i] = arr[i - 1] / Gcd(arr[i - 1], arr[i]) * arr[i];
            }
        }
        if (arr[n] > INF)
            cout << -1 << endl;
        else
            cout << arr[n] << endl;
    }
    return 0;
}