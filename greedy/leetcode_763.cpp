#include<iostream>
#include<vector>
#include<string>

using namespace std;

void output(vector<int>& v)
{
    cout<<"[";
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<",";
    }
    cout<<"]";
    cout<<"\n";
}

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> alphabet(26);
        int partition = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int i_alphabet = (int) s[i] - 97; 
            alphabet[i_alphabet] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            int i_alphabet = (int) s[i] - 97;
            int last = alphabet[i_alphabet];
            int pointer = i;
            while (pointer < last)
            {
                int i_alphabet = (int) s[pointer] - 97;
                if (alphabet[i_alphabet] > last)
                    last = alphabet[i_alphabet];
                pointer++;
            }
            partition++;
            i = last;
        }

        vector<int> result(partition);
        int result_pointer = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int i_alphabet = (int) s[i] - 97;
            int last = alphabet[i_alphabet];
            int pointer = i;
            int result_count = 0;
            while (pointer < last)
            {
                int i_alphabet = (int) s[pointer] - 97;
                if (alphabet[i_alphabet] > last)
                    last = alphabet[i_alphabet];
                pointer++;
                result_count++;
            }
            i = last;
            result[result_pointer] = result_count + 1;
            result_pointer++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s1 = "ababcbacadefegdehijhklij";
    vector<int> ans1 = solution.partitionLabels(s1);
    std::cout<<"ans1 = ";
    output(ans1);
}
