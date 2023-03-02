#include <iostream>
#include <vector>
using namespace std;

string ch;

void Towers(int n, char a, char b, char c)
{
    if (n == 1) // a->c
    {
        if (ch[0] == 'r')
        {
            if ((c - a + 3) % 3 == 1)
                cout << "move " << n << " from " << a << " to " << c << endl;
            else
            {
                cout << "move " << n << " from " << a << " to " << b << endl;
                cout << "move " << n << " from " << b << " to " << c << endl;
            }
        }

        else if (ch[0] == 'l')
        {
            if ((a - c + 3) % 3 == 1)
                cout << "move " << n << " from " << a << " to " << c << endl;
            else
            {
                cout << "move " << n << " from " << a << " to " << b << endl;
                cout << "move " << n << " from " << b << " to " << c << endl;
            }
        }
    }
    else
    {

        // move n from a to c
        if (ch[n - 1] == 'r')
        {
            if ((c - a + 3) % 3 == 1)
            {
                Towers(n - 1, a, c, b);
                cout << "move " << n << " from " << a << " to " << c << endl;
                Towers(n - 1, b, a, c);
            }

            else
            {
                Towers(n - 1, a, b, c);
                cout << "move " << n << " from " << a << " to " << b << endl;
                Towers(n - 1, c, b, a);
                cout << "move " << n << " from " << b << " to " << c << endl;
                Towers(n - 1, a, b, c);
            }
        }

        else if (ch[n - 1] == 'l')
        {
            if ((a - c + 3) % 3 == 1)
            {
                Towers(n - 1, a, c, b);
                cout << "move " << n << " from " << a << " to " << c << endl;
                Towers(n - 1, b, a, c);
            }
            else
            {
                Towers(n - 1, a, b, c);
                cout << "move " << n << " from " << a << " to " << b << endl;
                Towers(n - 1, c, b, a);
                cout << "move " << n << " from " << b << " to " << c << endl;
                Towers(n - 1, a, b, c);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int n;

    while (cin >> n >> ch)
    {
        Towers(n, 'A', 'B', 'C');
        cout<<endl;
    }

    return 0;
}