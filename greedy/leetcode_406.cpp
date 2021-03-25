#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        auto cmp = [] (vector<int>& a, vector<int>& b)
        {
            return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
        };
        if (people.size() < 1)
        {
            vector<vector<int>> v = {{}};
            return v;
        }
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> result = people;
        for(int i = 0; i < result.size(); ++i)
        {
            result[i] = result[0];
        }

        for(int i = 0; i < people.size(); ++i)
        {
            int k_value = people[people.size()-1-i][1];
            int h_value = people[people.size()-1-i][0];
            int count = 0;
            while(k_value >= 0)
            {
                if (result[count][0] >= h_value)
                {
                    --k_value;
                }
                if (k_value < 0)
                {
                    result[count] = people[people.size()-1-i];
                }
                ++count;
            }
        }
        return result;
    }
};

void output(vector<vector<int>>& v)
{
    cout<<"[";   
    for(int i = 0; i < v.size(); ++i)
    {
        cout<<"[";   
        for(int j = 0; j < v[i].size(); ++j)
        {
            cout<<v[i][j]<<", ";
        }
        cout<<"], ";
    }
    cout<<"]"<<"\n";
}

int main()
{
    Solution solution;
    vector<vector<int>> v1 = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> v2 = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
    vector<vector<int>> ans1 = solution.reconstructQueue(v1);
    vector<vector<int>> ans2 = solution.reconstructQueue(v2);
    output(ans1);
    output(ans2);
}
