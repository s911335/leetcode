#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int max = nums[0];
        int interval_max = 0;
        int pointer = 0;
        while (pointer < nums.size())
        {
            interval_max += nums[pointer];
            if (interval_max < nums[pointer])
            {
                interval_max = nums[pointer];
            }
            if (interval_max > max)
                max = interval_max;
            pointer++;
        }
        return max;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums2 = {1};
    vector<int> nums3 = {5, 4, -1, 7, 8};
    int ans1 = solution.maxSubArray(nums1);
    int ans2 = solution.maxSubArray(nums2);
    int ans3 = solution.maxSubArray(nums3);
    std::cout<<"ans1 = "<<ans1<<"\n";
    std::cout<<"ans2 = "<<ans2<<"\n";
    std::cout<<"ans3 = "<<ans3<<"\n";
}
