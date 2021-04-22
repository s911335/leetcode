#include<iostream>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        int l = 1;
        int r = x;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int q = x / mid;
            if ((mid-q) < 1)
                return mid;
            else {
               l = q;
               r = mid;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    int ans1 = solution.mySqrt(4);
    std::cout<<"ans1 = "<<ans1<<"\n";
    int ans2 = solution.mySqrt(8);
    std::cout<<"ans2 = "<<ans2<<"\n";
    int ans3 = solution.mySqrt(500);
    std::cout<<"ans3 = "<<ans3<<"\n";
    int ans4 = solution.mySqrt(2147395599);
    std::cout<<"ans4 = "<<ans4<<"\n";
}
