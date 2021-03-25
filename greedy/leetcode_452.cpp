#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        auto cmp = [] (vector<int>& a, vector<int>& b) {return a[1] < b[1];};
        if (points.size() < 1)
            return 0;
        sort(points.begin(), points.end(), cmp);
        int arrows = 1;
        int pointer = points[0][1];
        for(int i = 0; i < points.size(); ++i)
        {
            if (points[i][0] > pointer)
            {
                arrows += 1;
                pointer = points[i][1];
            }
        }
       return arrows;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> v1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    vector<vector<int>> v2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    vector<vector<int>> v3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    vector<vector<int>> v4 = {{1, 2}};
    vector<vector<int>> v5 = {{2, 3}, {2, 3}};
    int ans1 = solution.findMinArrowShots(v1);
    int ans2 = solution.findMinArrowShots(v2);
    int ans3 = solution.findMinArrowShots(v3);
    int ans4 = solution.findMinArrowShots(v4);
    int ans5 = solution.findMinArrowShots(v5);
    std::cout<<"ans1 = "<<ans1<<"\n";
    std::cout<<"ans2 = "<<ans2<<"\n";
    std::cout<<"ans3 = "<<ans3<<"\n";
    std::cout<<"ans4 = "<<ans4<<"\n";
    std::cout<<"ans5 = "<<ans5<<"\n";
}
