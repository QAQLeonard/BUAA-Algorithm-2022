#include <cstdio>
#include <cstring>
#include <vector>

#define MaxN 1000000 + 5
#define MaxM 1000000 + 5
using namespace std;
char pattern[MaxM];
int prefix[MaxM];

void get_prefix(int size)
{
    prefix[0] = -1;
    prefix[1] = 0;
    for (int i = 2; i <= size; i++)
    {
        if (pattern[i - 1] == pattern[prefix[i - 1]])
        {
            prefix[i] = prefix[i - 1] + 1;
        }
        else
        {
            int ptr = prefix[i - 1];
            while (ptr >= 0 && pattern[i - 1] != pattern[ptr])
            {
                ptr = prefix[ptr];
            }
            if (ptr == -1)
            {
                prefix[i] = 0;
            }
            else
            {
                prefix[i] = ptr + 1;
            }
        }
    }
}



void KMP()
{
    scanf("%s", pattern);
    int pattern_size = (int)strlen(pattern);
    get_prefix(pattern_size);

}
int main()
{
    KMP();
    

}