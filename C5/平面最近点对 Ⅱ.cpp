#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;

#define MAX 50001

struct point
{
    double x;
    double y;
} points[MAX];

int box[MAX];

bool comp_x(point a, point b)
{
    return a.x < b.x;
}

bool comp_y(int a, int b)
{
    return points[a].y < points[b].y;
}

long double dis_max(point a, point b)
{
    // cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl;
    // cout<<sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))<<endl;
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

long double min_dis(int p, int q)
{
    if (q - p == 0)
    {
        return 100000;
    }
    else if (q - p == 1)
    {
        return dis_max(points[p], points[q]);
    }
    else
    {
        long double dis_min;
        int m = (p + q) / 2;
        dis_min = min(min_dis(p, m - 1), min_dis(m + 1, q));
        // cout<<dis_min<<endl;
        //        int f_p = m;
        int tmp_p = 0;
        for (int i = p; i <= q; i++)
        {
            if (points[i].x >= (points[m].x - dis_min) && points[i].x <= (points[m].x + dis_min))
            {
                box[tmp_p] = i;
                tmp_p++;
            }
        }
        sort(box, box + tmp_p, comp_y);
        for (int i = 0; i < tmp_p; i++)
        {
            for (int j = i + 1; j < tmp_p; j++)
            {
                if (points[box[j]].y - points[box[i]].y >= dis_min)
                {
                    break;
                }
                dis_min = min(dis_min, dis_max(points[box[i]], points[box[j]]));
            }
        }
        return dis_min;
    }
}

int main()
{
    int n;
    cin >> n;
    memset(box, 1000000, sizeof(box));
    for (int i = 1; i <= n; i++)
    {
        cin >> points[i].x;
        cin >> points[i].y;
    }
    sort(points + 1, points + n + 1, comp_x);

    printf("%.4Lf", min_dis(1, n));

    return 0;
}
