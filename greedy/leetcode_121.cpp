#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int max = 0;
        int min = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if (min > prices[i])
            {
                min = prices[i];
            }           
            if ((prices[i] - min) > max)
            {
                max = prices[i] - min;
            }
        }
        return max;
    }
};

int main()
{
    Solution solution;
    vector<int> v1 = {7, 1, 5, 3, 6, 4};
    vector<int> v2 = {7, 6, 4, 3, 1};
    vector<int> v3 = {2, 4, 1};
    int ans1 = solution.maxProfit(v1);
    int ans2 = solution.maxProfit(v2);
    int ans3 = solution.maxProfit(v3);
    std::cout<<"ans1 = "<<ans1<<"\n";
    std::cout<<"ans2 = "<<ans2<<"\n";
    std::cout<<"ans3 = "<<ans3<<"\n";
}
