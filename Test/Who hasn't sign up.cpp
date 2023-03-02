#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int HASHSET[1000000];
int main()
{
    int n;
    cin >> n;
    vector<string> str(n);
    vector<string> cmpStr(n);
    hash<string> hash_fn;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> cmpStr[i];
        HASHSET[hash_fn(cmpStr[i])%1000000] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (HASHSET[hash_fn(str[i])%1000000] == 0)
        {
            cout << str[i] << endl;
            break;
        }
    }
}