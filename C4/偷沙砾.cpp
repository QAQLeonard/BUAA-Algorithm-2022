#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef struct ss
{
    int weight;
    int value;
    double value_v;
} ss;

bool cmp(ss a, ss b)
{
    return a.value_v > b.value_v;
}

int main()
{
    int n;
    int Bag = 0;
    cin >> n;
    cin >> Bag;
    vector<ss> steel(n);
    for (int i = 0; i < n; i++)
    {
        cin >> steel[i].value>> steel[i].weight;
    }
    for (int i = 0; i < n; i++)
    {
        steel[i].value_v = (double)steel[i].value / (double)steel[i].weight;
    }
    
    sort(steel.begin(), steel.end(), cmp);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<steel[i].value_v<<endl;
    // }
    int Sum = Bag;
    double SumValue = 0;
    //cout<<Sum<<endl;
    for (int i = 0; i < n; i++)
    {
        if (Sum == 0)
            break;
        else if (Sum >= steel[i].weight)
        {
            SumValue += (double)steel[i].value;
            Sum -= steel[i].weight;
        }
        else if (Sum < steel[i].weight)
        {
            SumValue +=(double)Sum * steel[i].value_v;
            break;
        }
    }
    printf("%.3lf", SumValue);
    
    return 0;
}