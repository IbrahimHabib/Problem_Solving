#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> farm(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> farm[i];
    }
    vector<int> count(n, 0);
    int x = 0;
    int after = 1;
    int before = 0;
    //count for the first part in the farm
    while (after < n && farm[x] >= farm[after])
    {
        count[0]++;
        x++;
        after++;
    }
    //count for the middle parts in the farm
    for (size_t i = 1; i < n - 1; i++)
    {
        x = i;
        after = i + 1;
        before = i - 1;
        //move backward
        while (before >= 0 && farm[x] >= farm[before])
        {
            count[i]++;
            x--;
            before--;
        }
        //move forward
        x = i;
        while (after < n && farm[x] >= farm[after])
        {
            count[i]++;
            x++;
            after++;
        }
    }
    //count for the last part in the farm
    x = n - 1;
    before = n - 2;
    while (before >= 0 && farm[x] >= farm[before])
    {
        count[n - 1]++;
        x--;
        before--;
    }
    sort(count.begin(), count.end());
    cout <<count[count.size()-1]+1<<endl;
}