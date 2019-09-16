#include <iostream>
#include <string>
using namespace std;

void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
int main()
{
    int n = 0;
    int x = 0;
    string encoding = "";
    string decode = "";
    string rem = "";
    cin >> x;
    n = x - 1;
    cin >> encoding;
    while (n > 0)
    {
        decode += encoding[n - 1];
        rem += encoding[n];
        n = n - 2;
        // cout<<decode<<endl;
    }
    reverseStr(rem);
    if (x % 2 == 0)
    {
        cout << decode + rem << endl;
    }
    else
    {
        cout << decode + encoding[0] + rem << endl;
    }
}