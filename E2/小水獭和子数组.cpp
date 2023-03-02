#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int time;
    cin >> time;

    vector<int> arr;

    vector<vector<int>> recoder;

    __int128_t ans=0;

    for (int t = 0; t < time; t++)
    {
        int n;
        cin >> n;

        stack<int> MINLeft;
        stack<int> MINRight;
        stack<int> MAXLeft;
        stack<int> MAXRight;

        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            arr.push_back(temp);
            recoder.push_back(vector<int>(4, 0));
        }
        int tempL = 0, tempR = 0;

        for (int i = 0; i < n; i++)
        {
            tempL = arr[i];
            tempR = arr[n - 1 - i];

            while (!MAXLeft.empty() && arr[MAXLeft.top()] <= tempL)
            {
                MAXLeft.pop();
            }
            recoder[i][0] = (MAXLeft.empty() ? -1 : MAXLeft.top());
            MAXLeft.push(i);

            while (!MINLeft.empty() && arr[MINLeft.top()] >= tempL)
            {
                MINLeft.pop();
            }
            recoder[i][2] = (MINLeft.empty() ? -1 : MINLeft.top());
            MINLeft.push(i);

            while (!MAXRight.empty() && arr[MAXRight.top()] <= tempR)
            {
                MAXRight.pop();
            }
            recoder[n - 1 - i][1] = (MAXRight.empty() ? n : MAXRight.top());
            MAXRight.push(n - 1 - i);

            while (!MINRight.empty() && arr[MINRight.top()] >= tempR)
            {
                MINRight.pop();
            }
            recoder[n - 1 - i][3] = (MINRight.empty() ? n : MINRight.top());
            MINRight.push(n - 1 - i);
        }

        for(int i=0;i<n;i++)
        {
            ans+=arr[i]*(i-1);
        }


        arr.clear();
    }
}