#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{

    int alloc[5][3] = {{0, 1, 0},  // P0 // Allocation Matrix
                       {2, 0, 0},  // P1
                       {3, 0, 2},  // P2
                       {2, 1, 1},  // P3
                       {0, 0, 2}}; // P4

    int max[5][3] = {{7, 5, 3},  // P0 // MAX Matrix
                     {3, 2, 2},  // P1
                     {9, 0, 2},  // P2
                     {2, 2, 2},  // P3
                     {4, 3, 3}}; // P4

    int avail[3] = {3, 3, 2}; // Available Resources
    int np = 5;
    int nr = 3;
    int need[np][nr];
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int ans[np];
    unordered_map<int, int> maaap;
    int index = 0;
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < np; j++)
        {

            if (maaap.count(j) <= 0)
            { // Jo process free ni hua h
                bool canbe = true;

                for (int k = 0; k < nr; k++)
                {
                    if (need[j][k] > avail[k])
                    {
                        canbe = false;
                        break;
                    }
                }
                if (canbe)
                {
                    maaap[j] = 1;
                    ans[index++] = j;
                    for (int k = 0; k < nr; k++)
                    {
                        avail[k] += alloc[j][k];
                    }
                }
            }
        }
    }
    for (int i = 0; i < np; i++)
    {
        cout << " P" << ans[i];
    }
    
}
