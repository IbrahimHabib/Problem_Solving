#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main()
{
   map<char, int> coins;
   vector<pair<char, int>> order;
   string balance;
   string result = "";
   coins.insert(pair<char, int>('A', 0));
   coins.insert(pair<char, int>('B', 0));
   coins.insert(pair<char, int>('C', 0));
   for (size_t i = 0; i < 3; i++)
   {
      cin >> balance;
      if (balance[1] == '>')
      {
         coins[balance[0]]++;
      }
      else
      {
         coins[balance[2]]++;
      }
   }
   if (coins['A'] == coins['B'] || coins['A']== coins['C'] ||coins['B']== coins['C'])
   {
      cout << "Impossible" << endl;
      return 0;
   }
   else if (coins['A'] + coins['B'] + coins['C'] < 3)
   {
      cout << "Impossible" << endl;
      return 0;
   }
   if (coins['A'] == 0)
   {
      result=result+"A";
   }
   else if (coins['B'] == 0)
   {
      result=result+"B";
   }
   else
   {
      result=result+"C";
   }
    if (coins['A'] == 1)
   {
      result=result+"A";
   }
   else if (coins['B'] == 1)
   {
      result=result+"B";
   }
   else
   {
      result=result+"C";
   }
    if (coins['A'] == 2)
   {
      result=result+"A";
   }
   else if (coins['B'] == 2)
   {
      result=result+"B";
   }
   else
   {
      result=result+"C";
   }
   cout<<result<<endl;
}