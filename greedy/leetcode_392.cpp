#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int s_pointer = 0;
        int t_pointer = 0;
        if (s.size() == 0)
            return true;
        while (t_pointer < t.size())
        {
            if (s[s_pointer] == t[t_pointer])
                s_pointer++;
            if (s_pointer == s.size())
               return true; 
            t_pointer++;
        }
        return false;
    }
};

void output(string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<", ";
    }
    cout<<"\n";
}

int main()
{
    Solution solution;
    string s1 = "abc"; string t1 = "ahbgc";
    string s2 = "axc"; string t2 = "ahbgc";

    bool ans1 = solution.isSubsequence(s1, t1);
    bool ans2 = solution.isSubsequence(s2, t2);
    cout<<"ans1 = "<<ans1<<"\n";
    cout<<"ans2 = "<<ans2<<"\n";
}
