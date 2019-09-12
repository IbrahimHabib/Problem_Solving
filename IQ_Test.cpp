#include <iostream>
#include <vector>
using namespace std;

char inp[4][4]; // input array
bool test(int i, int j)
{
    if (i+1 == 4 || j+1 == 4) // do not test outside array
    {
        return false;
    }
    return inp[i][j] == inp[i][j + 1] && inp[i][j] == inp[i + 1][j] && inp[i][j] == inp[i + 1][j + 1];
}
bool test()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (test(i, j))
            {
                return true;
            }
        }
        
    }
    return false;
}

int main()
{
    bool done = false;
    //read input grid
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> inp[i][j];
        }
    }
    //check if the 2x2 square alreaady exists
    done = test();
    if (done == false)
    {
        //change items and test again
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                char base = inp[i][j];
                if (inp[i][j] == '.')
                {
                    inp[i][j] = '#';
                }
                else
                {
                    inp[i][j] = '.';
                }
                if (test())
                {
                    done = true;
                    inp[i][j] = base;
                    break;
                }
                inp[i][j] = base;
            }
            if (done)
            {
                break;
            }
        }
    }
    if (done)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}