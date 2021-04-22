#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int s = letters.size() - 1;
        if (target >= letters[s] || target < letters[0])
            return letters[0];
        int l = 0;
        int r = s;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if (target >= letters[mid] && target < letters[mid+1])
                return letters[mid+1];
            if (target >= letters[mid])
                l = mid + 1;
            else 
                r = mid - 1;
            mid = (l + r) / 2;
        }
        return '*';
    }
};

int main()
{
    Solution solution;
    vector<char> v1 = {'c', 'f', 'j'};
    char ans1 = solution.nextGreatestLetter(v1, 'a');
    std::cout<<"ans1 = "<<ans1<<"\n";
}
