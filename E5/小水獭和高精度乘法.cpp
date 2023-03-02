#include <bits/stdc++.h>
#define Pi (acos(-1.0))
using namespace std;
int getint()
{
    char ch = getchar();
    int ret = 0, flag = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ret = (ret << 3) + (ret << 1) + ch - '0';
        ch = getchar();
    }
    return ret * flag;
}
struct Complex
{
    double real, imag;
    Complex operator+(Complex b)
    {
        Complex ret;
        ret.real = real + b.real;
        ret.imag = imag + b.imag;
        return ret;
    }
    Complex operator-(Complex b)
    {
        Complex ret;
        ret.real = real - b.real;
        ret.imag = imag - b.imag;
        return ret;
    }
    Complex operator*(Complex b)
    {
        Complex ret;
        ret.real = real * b.real - imag * b.imag;
        ret.imag = real * b.imag + b.real * imag;
        return ret;
    }
} wi[1000005];
int rev[1000005];
int pre(int x)
{
    int l = ceil(log2(x)), len = 1 << l;
    for (int i = 1; i < len; i++)
        rev[i] = rev[i >> 1] >> 1 | ((i & 1) << (l - 1));
    return len;
}
void FFT(Complex A[], int len, int f)
{
    for (int i = 0; i < len; i++)
        if (rev[i] < i)
            swap(A[i], A[rev[i]]);
    for (int i = 1; i < len; i <<= 1)
    {
        Complex wn = {cos(1.0 * f * Pi / i), sin(1.0 * f * Pi / i)};
        wi[0] = {1, 0};
        for (int j = 1; j < i; j++)
            wi[j] = wi[j - 1] * wn;
        for (int j = 0; j < len; j += i << 1)
        {
            for (int k = 0; k < i; k++)
            {
                Complex x = A[j + k], y = A[j + k + i] * wi[k];
                A[j + k] = x + y;
                A[j + k + i] = x - y;
            }
        }
    }
    if (f == -1)
        for (int i = 0; i < len; i++)
            A[i].real = A[i].real / len;
}
int n, sum[1000005], tot;
Complex a[1000005], b[1000005];
char c[1000005];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        
        scanf("%s", c + 1);
        n = strlen(c + 1);
        int length=strlen(c + 1);
        for (int i = 0; i < length; i++)
            a[i].real = c[length - i] ^ 48;
        scanf("%s", c + 1);
        length=strlen(c + 1);
        n = n > length ? n : length;
        for (int i = 0; i < length; i++)
            b[i].real = c[length - i] ^ 48;
        n = pre(n << 1);
        FFT(a, n, 1);
        FFT(b, n, 1);
        for (int i = 0; i < n; i++)
        {
            a[i] = a[i] * b[i];
        }
        FFT(a, n, -1);
        for (int i = 0; i < n; i++)
        {
            sum[i] += (a[i].real + 0.5);
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        int l = n;
        while (!sum[l])
            l--;
        while (l >= 0)
            putchar(sum[l--] ^ 48);
        putchar('\n');
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(sum, 0, sizeof(sum));
    }
    return 0;
}