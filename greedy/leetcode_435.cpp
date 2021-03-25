#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        if (intervals.size() < 1)
            return 0;

        sort(intervals.begin(), intervals.end(), cmp);
        int result = 0;
        int pointer = intervals[0][0];
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][0] >= pointer)
                pointer = intervals[i][1];
            else
                result += 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> v1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> v2 = {{1, 2}, {1, 2}, {1, 2}};
    vector<vector<int>> v3 = {{1, 2}, {2, 3}};
    vector<vector<int>> v4 = {{1, 2}, {2, 3}, {3, 4}, {-100, -2}, {5, 7}};
    int ans1 = solution.eraseOverlapIntervals(v1);
    int ans2 = solution.eraseOverlapIntervals(v2);
    int ans3 = solution.eraseOverlapIntervals(v3);
    int ans4 = solution.eraseOverlapIntervals(v4);
    std::cout<<"ans1 = "<<ans1<<"\n";
    std::cout<<"ans2 = "<<ans2<<"\n";
    std::cout<<"ans3 = "<<ans3<<"\n";
    std::cout<<"ans4 = "<<ans4<<"\n";
}
