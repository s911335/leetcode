#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if (flowerbed.size() == 1)
        {
            if (n == 0)
                return true;
            else if (flowerbed[0] == 0 && n == 1)
                return true;
            else
                return false;
        }
        if (flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            n -= 1;
            flowerbed[0] = 1;
        }
        if (flowerbed[flowerbed.size()-1] == 0 && 
                flowerbed[flowerbed.size()-2] == 0)
        {
            n -= 1;
            flowerbed[flowerbed.size()-1] = 1;
        }
        for (int i = 1; i < flowerbed.size()-2; i++)
        {
            if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
            {
                n -= 1;
                flowerbed[i] = 1;
            }
        }
        if (n <= 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution solution;
    vector<int> f1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    vector<int> f2 = {1, 0, 0, 0, 1};
    int n2 = 2;
    int ans1 = solution.canPlaceFlowers(f1, n1);
    int ans2 = solution.canPlaceFlowers(f2, n2);
    std::cout<<"ans1 = "<<ans1<<"\n";
    std::cout<<"ans2 = "<<ans2<<"\n";
}
