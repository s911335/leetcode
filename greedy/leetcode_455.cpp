#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int result = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_pointer = g.size() - 1;
        int s_pointer = s.size() - 1;
        while(g_pointer >= 0 && s_pointer >= 0)
        {
            if (g[g_pointer] <= s[s_pointer])
            {
                ++result;
                --g_pointer;
                --s_pointer;
            }
            else
            {
                --g_pointer;
            };
        };
        return result;
    }
};

int main()
{
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    Solution solution;
    int answer1 = solution.findContentChildren(g1, s1);
    int answer2 = solution.findContentChildren(g2, s2);
    cout<<"answer1 = "<< answer1 <<"\n";
    cout<<"answer2 = "<< answer2 <<"\n";
}
