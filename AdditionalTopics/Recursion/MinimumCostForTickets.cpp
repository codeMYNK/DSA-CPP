#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minicostTicketsHelper(vector<int> &days, vector<int> &costs, int i)
    {
        if (i >= days.size())
            return 0;

        // 1 DAY PASS
        int cost1 = costs[0] + minicostTicketsHelper(days, costs, i + 1);

        // 7 DAY PASS
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost7 = costs[1] + minicostTicketsHelper(days, costs, j);

        // 30 DAY PASS
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost30 = costs[2] + minicostTicketsHelper(days, costs, j);
        return min(cost1, min(cost7, cost30));
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return minicostTicketsHelper(days, costs, 0);
    }
};