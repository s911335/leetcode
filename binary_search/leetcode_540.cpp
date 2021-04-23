#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        int m = 0;
        while(l < r) {
            m = l + (r - l) / 2;
            if (nums[m] != nums[m-1] && nums[m] != nums[m+1])
                return nums[m];
            int iseven = m % 2;
            if (iseven == 0) {
                if (nums[m] == nums[m-1] && nums[m] != nums[m+1])
                    r = m;
                else
                    l = m;
            }
            else {
                if (nums[m] == nums[m-1] && nums[m] != nums[m+1])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return nums[l];
    }
};

int main()
{
    Solution solution;
    vector<int> v1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int ans1 = solution.singleNonDuplicate(v1);
    std::cout<<"ans1 = "<<ans1<<"\n";
    vector<int> v2 = {1, 1, 2, 2, 3, 3, 4, 8, 8};
    int ans2 = solution.singleNonDuplicate(v2);
    std::cout<<"ans2 = "<<ans2<<"\n";
    vector<int> v3 = {3, 3, 7, 7, 10, 11, 11};
    int ans3 = solution.singleNonDuplicate(v3);
    std::cout<<"ans3 = "<<ans3<<"\n";
    vector<int> v4 = {0, 1, 1, 2, 2, 5, 5};
    int ans4 = solution.singleNonDuplicate(v4);
    std::cout<<"ans4 = "<<ans4<<"\n";
    vector<int> v5 = {3, 1, 1};
    int ans5 = solution.singleNonDuplicate(v5);
    std::cout<<"ans5 = "<<ans5<<"\n";
    vector<int> v6 = {1};
    int ans6 = solution.singleNonDuplicate(v6);
    std::cout<<"ans6 = "<<ans6<<"\n";
}
