
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    long long int x;
    long long int y;
};

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<Point> p;
        long long int x, y;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            p.push_back({x, y});
        }
        bool flag = true;
        int dx = p[1].x - p[0].x;
        int dy = p[1].y - p[0].y;
        for (int i = 2; i < n; i++)
        {
            if ((p[i].x - p[i - 1].x) * dy != (p[i].y - p[i - 1].y) * dx)
            {
                flag = false;
                break;
            }
        }

        cout << (flag ? "boo how! boo how!" : "how?") << endl;
    }
}
