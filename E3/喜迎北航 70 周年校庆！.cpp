#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long int lessMoney2(priority_queue<long long int,vector<long long int>,greater<long long int>> arr)
{
    long long int sum = 0;
    long long int cur = 0;
    while (arr.size() > 1)
    {
        // 3、每次弹出两个数字进行结合
        cur = arr.top();
        arr.pop();
        cur += arr.top();
        arr.pop();
        sum += 2*cur;
        //cout<<sum<<endl;
        // 4、把结合的数扔到小根堆中
        arr.push(cur);
    }
    return sum;
}

int main()
{
    int num;
    cin >> num;
    priority_queue<long long int,vector<long long int>,greater<long long int>> length;
    int temp;
    for(int i=0;i<num;i++)
    {
        cin>>temp;
        length.push(temp);
    }
    cout<<lessMoney2(length)<<endl;
    return 0;
}