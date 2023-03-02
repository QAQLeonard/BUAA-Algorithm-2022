#include <bits/stdc++.h>
using namespace std;

struct Point
{
public:
    long long int x;
    long long int y;
    // Point(long long int x, long long int y)
    // {
    //     this->x = x;
    //     this->y = y;
    // }
    Point operator-(const Point &p)
    {
        Point temp;
        temp.x = this->x - p.x;
        temp.y = this->y - p.y;
        return temp;
    }
    Point operator+(const Point &p)
    {
        Point temp;
        temp.x = this->x + p.x;
        temp.y = this->y + p.y;
        return temp;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        // long long int x,y;
        vector<Point> points(n + 1);
        for(int i=0;i<n;i++)
        {
            cin>>points[i].x>>points[i].y;
            // cin >> x >> y;
            // points.push_back(Point(x,y));
        }
        // points.push_back(points[0]);
        points[n] = points[0];
        long long int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans+=(points[i].x*points[i+1].y-points[i+1].x*points[i].y);
        }
        cout << abs(ans/2) << endl;
    }
    return 0;
}