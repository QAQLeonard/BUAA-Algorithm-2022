#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 100000 + 5

struct Point
{
    long long int x;
    long long int y;
} points[1005];

//计算叉积，小于0说明p1在p2的逆时针方向(右边)，即p0p1的极角大于p0p2的极角
long double cross_product(Point p0, Point p1, Point p2)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

//计算距离
long double distance(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool cmp(const Point &p1, const Point &p2)
{
    long double temp = cross_product(points[0], p1, p2);
    if (fabs(temp) < 1e-6) //极角相等按照距离从小到大排序
        return distance(points[0], p1) < distance(points[0], p2);
    else
        return temp > 0;
}

//格拉汉姆扫描法（求凸包）
vector<Point> Graham_scan(long long int n)
{
    vector<Point> ch;
    int top = 2;
    int index = 0;
    for (int i = 1; i < n; ++i)
    { //选出Y坐标最小的点，若Y坐标相等，选择X坐标小的点
        if (points[i].y < points[index].y || (points[i].y == points[index].y && points[i].x < points[index].x))
            index = i;
    }
    swap(points[0], points[index]);
    ch.push_back(points[0]);

    sort(points + 1, points + n, cmp);
    ch.push_back(points[1]);
    ch.push_back(points[2]);
    for (int i = 3; i < n; ++i)
    {
        while (top > 0 && cross_product(ch[top - 1], points[i], ch[top]) >= 0)
        { //当(p1-p0)叉乘(p2-p0)为正时，即待添加点在当前栈顶点的右侧时，弹出栈顶点
            top--;
            ch.pop_back();
        }
        ch.push_back(points[i]);
        top++;
    }
    return ch;
}

double count(Point a, Point b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main()
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        double res = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld", &points[i].x, &points[i].y);
        }

        vector<Point> ch = Graham_scan(n);
        for (int i = 0; i < ch.size(); i++)
        {
            res += count(ch[i % ch.size()], ch[(i + 1) % ch.size()]);
        }

        printf("%lf\n", res);
    }
    return 0;
}
