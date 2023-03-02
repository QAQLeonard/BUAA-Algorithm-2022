#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int StationNum;
    cin >> StationNum;

    vector<long long> arr;
    vector<int> line_first(StationNum, 0);
    vector<int> line_second(StationNum, 0);
    int second_to_first;
    int first_to_second;
    int temp = 0;
    for (int m = 0; m < 2; m++)
    {
        for (int i = 0; i < StationNum; i++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        // p.push_back(arr);
        // arr.clear();
    }

    vector<vector<long long>> t;
    for (int m = 0; m < 2; m++)
    {
        for (int i = 0; i < 2; i++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        t.push_back(arr);
        arr.clear();
    }
    vector<int> dp_first(StationNum, 0);
    vector<int> dp_second(StationNum, 0);
    for (int i = 0; i < StationNum; i++)
    {
        dp_first[i] = min(dp_first[i - 1] + line_first[i], dp_second[i - 1] + line_first[i] + second_to_first);
        dp_second[i] = min(dp_second[i - 1] + line_second[i], dp_first[i - 1] + line_second[i] + first_to_second);
    }

    return 0;
}