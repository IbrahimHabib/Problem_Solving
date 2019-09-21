#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int location = 0;
    int count = 0;
    cin >> location;
    location--;
    vector<int> criminals(n, 0);
    for (size_t i = 0; i < n; i++)
    {
        cin >> criminals[i];
    }
    //cout<<location<<endl;
    if (location == 0 || location == n - 1)
    {
        for (auto &i : criminals)
        {
            if (i == 1)
            {
                count++;
            }
        }
        cout << count << endl;
        return 0;
    }
    else if (location > 0 && location < n - 1)
    {
        int stepF = n - location - 1;
        int stepB = location;
        int step = 0;
        // cout<<stepF<<stepB<<endl;
        if (stepF > stepB)
        {
            for (step = 0; step <= stepF; step++)
            {
                if (location - step >= 0)
                {
                    if (criminals[location - step] == criminals[location + step] && criminals[location + step] == 1)
                        count = count + 2;
                    // cout<<"here"<<endl;
                }
                else
                {
                    if (criminals[location + step] == 1)
                    {
                        count++;
                        //cout<<"why"<<endl;
                    }
                }
                // cout<<criminals[stepB - step-1]<<" = "<<
            }
            if (criminals[location] == 1)
                cout << count - 1 << endl;
            else
                cout << count << endl;
            return 0;
        }
        else
        {
            for (step = 0; step <= stepB; step++)
            {
                if (location + step <= criminals.size() - 1)
                {
                    if (criminals[location - step] == criminals[location + step] && criminals[location + step] == 1)
                    {
                        count = count + 2;
                        //cout<<"here"<<endl;
                    }
                }
                else
                {
                    if (criminals[location - step] == 1)
                    {
                        count++;
                        //cout<<"why"<<endl;
                    }
                }
                // cout<<criminals[stepB - step-1]<<" = "<<
            }
            if (criminals[location] == 1)
                cout << count - 1 << endl;
            else
                cout << count << endl;
            return 0;
        }
    }
}