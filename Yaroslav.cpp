#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
 int n;
 int l;
 vector<int> array;
 cin>>n;
 int i =0;
 while (i<n)
 {
     cin>>l;
     array.push_back(l);
     i++;
 }
 sort(array.begin(),array.end());
 std::map<int, int> counters;
for(auto i: array)
{
    ++counters[i];
}
using pair_type = decltype(counters)::value_type;
auto pr = std::max_element
(
    std::begin(counters), std::end(counters),
    [] (const pair_type & p1, const pair_type & p2) {
        return p1.second < p2.second;
    }
);
int x = (pr->first);
// std::cout << x << '\n';
// cout << counters[x] <<endl;
 int max = 2* (counters[x]) - 1 ;
 if (n >= max )  
 {
     cout << "YES"<< endl;;
 }
 else
 {
     cout<< "NO"<< endl; ;
 }
 
 
}