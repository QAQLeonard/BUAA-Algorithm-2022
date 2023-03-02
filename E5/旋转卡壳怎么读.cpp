#include <bits/stdc++.h>
using namespace std;

struct Point
{
public:
    double x;
    double y;

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point()
    {
        this->x = 0;
        this->y = 0;
    }

} points[1000010];

double cross_product(Point p0, Point p1, Point p2)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double dis(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool operator<(const Point &p1,const Point &p2)
{
    double temp = cross_product(points[0], p1, p2);
    if (fabs(temp) < 1e-6) //极角相等按照距离从小到大排序
        return dis(points[0], p1) < dis(points[0], p2);
    else
        return temp > 0;
}

vector<Point> Graham_scan(int n)
{
    vector<Point> ch;
    if (n <= 2)
    {
        for (int i = 0; i < n; i++)
            ch.push_back(points[i]);
        return ch;
    }
    int top = 2;
    int index = 0;
    for (int i = 1; i < n; ++i)
    {
        if (points[i].y < points[index].y || (points[i].y == points[index].y && points[i].x < points[index].x))
            index = i;
    }
    swap(points[0], points[index]);
    ch.push_back(points[0]);
    sort(points + 1, points + n);
    ch.push_back(points[1]);
    ch.push_back(points[2]);
    for (int i = 3; i < n; ++i)
    {
        while (top > 0 && cross_product(ch[top - 1], points[i], ch[top]) >= 0)
        { //当(p1-p0)叉乘(p2-p0)为正时，即待添加点在当前栈顶点的右侧时，弹出栈顶点
            --top;
            ch.pop_back();
        }
        ch.push_back(points[i]);
        ++top;
    }
    return ch;
}

double rotating_caliper(vector<Point> v)
{
    double max_dis = 0.0;
    int n = v.size();
    if (n == 2)
        max_dis = dis(v[0], v[1]);
    else
    {
        v.push_back(v[0]);
        int j = 2;
        for (int i = 0; i < n; ++i)
        {
            while (cross_product(v[i], v[i + 1], v[j]) < cross_product(v[i], v[i + 1], v[j + 1]))
                j = (j + 1) % n;
            max_dis = max(max_dis, max(dis(v[j], v[i]), dis(v[j], v[i + 1])));
        }
    }
    return max_dis;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> ch = Graham_scan(n);
    double ans = rotating_caliper(ch);
    printf("%.6f\n", ans);
}