#include <iostream>
#include <vector>
using namespace std;
// To check if collision will take place and if yes return vector of pair of the position of the particle going to collide 
vector<int> collision(vector<char> dir)
{
    bool R_isfound = false;
    int R_pos;
    vector<int> indx{};
    for (int i = 0; i < dir.size(); i++)
    {
        if (dir[i] == 'R')
        {
            R_isfound = true;
            R_pos = i;
            //  cout << "R is found: " << i << endl;
        }
        if (dir[i] == 'L' && R_isfound)
        {
            indx.push_back(R_pos);
            indx.push_back(i);
            R_isfound = false;
        }
    }

    return indx;
}
//Calculate the least time of all the particles that are going to collide and return it 
void LeastTime(vector<int> indx, vector<int> pos)
{
    int leasttime = pos[indx[1]] - pos[indx[0]];
    int newtime;
    for (int i = 0; i < indx.size(); i += 2)
    {
        newtime = pos[indx[i + 1]] - pos[indx[i]];
        if (newtime < leasttime)
        {
            leasttime = newtime;
        }
    }
    //Divide the least time by 2 because the particles having the same speed and moving towards each other
    cout << leasttime / 2 << endl;
}

int main()
{
    int n;
    cin >> n;
    char d;
    int p;
    vector<char> dir;
    vector<int> pos;
    vector<int> indx{};
    //Read iput dir
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        dir.push_back(d);
    }
    //Read input pos
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        pos.push_back(p);
    }
    // get the index vector of collide paritcles
    indx = collision(dir);
    //check if the vector is empty and if yes no collision will take place
    if (indx.empty())
    {
        cout << "-1" << endl;
    }
    else
    {
        LeastTime(indx, pos);
    }
}