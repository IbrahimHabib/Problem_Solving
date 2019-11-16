#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
unsigned int n = 0;
cin>>n;
unsigned int m = 0;
cin>>m;
//unsigned int a = 0,b = 0;
pair<int,int> mbm;
vector<pair<int,int>> container;
unsigned int result{0};
while (m > 0)
{
    cin>>mbm.second;
    cin>>mbm.first;
    container.push_back(mbm);
    m--;
}
sort(container.begin(),container.end());
while (n > 0 )
{
    if (n >= container.back().second)
    {
        result = result + container.back().first*container.back().second;
        n = n-container.back().second;
        container.pop_back();
    }
    else if(n != 0)
    {
        result = result + n*container.back().first;
        container.pop_back();
        n = 0;
    }
    if (container.size() == 0)
        break;

}
  /*  for (int i=0; i<container.size(); i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << container[i].first << " "
             << container[i].second << endl;
    }
    */

    cout<<result<<endl;
}