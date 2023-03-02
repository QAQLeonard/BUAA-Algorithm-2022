#include <iostream>
#include <limits.h>
#include <vector>
#include <stack>
using namespace std;

void read(vector<long long int> arr)
{
    if (arr[0] > arr[1])
    {
        arr[1] = arr[0];
    }
    long long int count1 = 0;
    long long int count2 = 0;
    for (int i = 2; i < arr.size(); ++i)
    {
        long long int count1 = arr[i] + arr[i - 2];
        long long int count2 = arr[i - 1];
        if (count1 > count2)
        {
            arr[i] = count1;
        }
        else
        {
            arr[i] = count2;
        }
    }
    printf("%lld", arr[arr.size() - 1]);
    printf("\n");
}

int main()
{
    int time;
    cin>>time;
    for(int t=0;t<time;t++)
    {
        vector<long long int> arr;
        int length;
        cin>>length;
        long long int temp=0;
        for(int i=0;i<length;i++)
        {
            cin>>temp;
            arr.push_back(temp);
        }
        read(arr);
    }
    return 0;
}