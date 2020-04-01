#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void output(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<",";
    }
}

class Solution
{
public:
    bool checkPossibility(vector<int>& nums)
    {
        int error_count = 0;
        int pointer = 1;

        if (nums.size() <= 2)
            return true;

        while (pointer < nums.size())
        {
            if (pointer == nums.size() - 1)
            {
                if (nums[pointer] < nums[pointer-1])
                {
                    nums[pointer] = nums[pointer-1];
                    error_count++;
                }
            }
            if (nums[pointer] < nums[pointer-1])
            {
                if (nums[pointer-1] >= nums[pointer+1])
                {
                    cout<<"pointer = "<<pointer<<"\t";
                    cout<<"make v ";
                    output(nums);
                    cout<<" to ";
                    nums[pointer-1] = nums[pointer];
                    output(nums);
                    cout<<"\n";
                    error_count++;
                    pointer = 0;
                    cout<<"error_count = "<<error_count<<"\n";
                }
                else
                {
                    cout<<"pointer = "<<pointer<<"\t";
                    cout<<"make v ";
                    output(nums);
                    cout<<" to ";
                    nums[pointer] = nums[pointer+1];
                    output(nums);
                    cout<<"\n";
                    error_count++;
                    pointer = 0;
                    cout<<"error_count = "<<error_count<<"\n";
                }
            }
            if (error_count == 2)
                return false;
            pointer++;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {4, 2, 3};
    vector<int> nums2 = {4, 2, 1};
    vector<int> nums3 = {5, 7, 1, 8};
    vector<int> nums4 = {3, 4, 2, 3};
    vector<int> nums5 = {1, 2, 4, 5, 3};
    bool ans1 = solution.checkPossibility(nums1);
    std::cout<<"ans1 = "<<ans1<<"\n\n";
    bool ans2 = solution.checkPossibility(nums2);
    std::cout<<"ans2 = "<<ans2<<"\n\n";
    bool ans3 = solution.checkPossibility(nums3);
    std::cout<<"ans3 = "<<ans3<<"\n\n";
    bool ans4 = solution.checkPossibility(nums4);
    std::cout<<"ans4 = "<<ans4<<"\n\n";
    bool ans5 = solution.checkPossibility(nums5);
    std::cout<<"ans5 = "<<ans5<<"\n\n";
}
