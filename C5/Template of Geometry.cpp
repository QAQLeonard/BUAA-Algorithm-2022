#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
#define linesegment 2;
#define beeline 1;
struct line
{
    long long int x1;
    long long int y1;
    long long int x2;
    long long int y2;
    int type0;
} lines[2];
int main()
{
    int t;
    cin >> t;
    pair<long long, long long> a, b, c;

    while (t--)
    {
        cin >> lines[0].type0 >> lines[0].x1 >> lines[0].y1 >> lines[0].x2 >> lines[0].y2;
        cin >> lines[1].type0 >> lines[1].x1 >> lines[1].y1 >> lines[1].x2 >> lines[1].y2;
        if (lines[0].type0 == 1 && lines[1].type0 == 1) //都为直线
        {
            if ((lines[0].x2 - lines[0].x1) * (lines[1].y2 - lines[1].y1) == (lines[1].x2 - lines[1].x1) * (lines[0].y2 - lines[0].y1)) // k1==k2
            {
                if ((lines[0].x2 * lines[0].y1 - lines[0].x1 * lines[0].y2) * (lines[1].x2 - lines[1].x1) == (lines[1].x2 * lines[1].y1 - lines[1].x1 * lines[1].y2) * (lines[0].x2 - lines[0].x1))
                {
                    cout << "Coincide" << endl;
                }
                else
                {
                    cout << "Parallel" << endl;
                }
            }
            else
            {
                cout << "Intersect" << endl;
            }
        }
        else if (lines[0].type0 == 2 && lines[1].type0 == 2) //两条线都为线段
        {
            if ((lines[0].x2 - lines[0].x1) * (lines[1].y2 - lines[1].y1) == (lines[1].x2 - lines[1].x1) * (lines[0].y2 - lines[0].y1)) // k1==k2
            {
                if ((lines[0].x2 * lines[0].y1 - lines[0].x1 * lines[0].y2) * (lines[1].x2 - lines[1].x1) == (lines[1].x2 * lines[1].y1 - lines[1].x1 * lines[1].y2) * (lines[0].x2 - lines[0].x1))
                {
                    
                }
                else
                {
                    cout << "Don't intersect" << endl;
                }
            }
        }
    }
    return 0;
}
