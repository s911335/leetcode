#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {};
};

void print_linklist(ListNode* head)
{
    cout<<"head ";
    if (head == NULL)
        cout<<"NULL";
    ListNode* pointer = head;
    while (pointer != NULL)
    {
        cout<<pointer->val<<" -> ";
        pointer = pointer->next;
    }
    cout<<"\n";    
}

class Solutions
{
public:
    vector<ListNode*> splitListToPart(ListNode* root, int k)
    {
        int count = 0;
        ListNode* pointer = root;
        vector<ListNode*> answer(k);
        while (pointer) {
            pointer = pointer->next;
            count++;
        }
        pointer = root;
        int num = count / k;
        int remainder = count % k;
        int carry = 0;
        cout<<"count = "<<count<<"\n";
        cout<<"num = "<<num<<"\n";
        cout<<"remainder = "<<remainder<<"\n";
        for (int i = 0; i < answer.size(); i++) {
            if (pointer == NULL)
                answer[i] = NULL;
            else {
                answer[i] = pointer;
                if (remainder > 0) {
                    carry = num + 1;
                    remainder--;
                }
                else
                    carry = num;
                while(carry-1)
                {
                    pointer = pointer->next;
                    carry--;
                }
                ListNode* record = pointer->next;
                pointer->next = NULL;
                pointer = record;
            }
        }
        return answer;
    }
};

struct Question1
{
    ListNode l10;
    ListNode l11;
    ListNode l12;
    Question1 (): l10(1), l11(2), l12(3)
    { 
        l10.next = &l11;
        l11.next = &l12;
    }
};

struct Question2
{
    ListNode l10;
    ListNode l11;
    ListNode l12;
    ListNode l13;
    ListNode l14;
    ListNode l15;
    ListNode l16;
    ListNode l17;
    ListNode l18;
    ListNode l19;
    Question2 (): l10(1), l11(2), l12(3), l13(4), l14(5), l15(6), l16(7),
        l17(8), l18(9), l19(10)
    {
        l10.next = &l11;
        l11.next = &l12;
        l12.next = &l13;
        l13.next = &l14;
        l14.next = &l15;
        l15.next = &l16;
        l16.next = &l17;
        l17.next = &l18;
        l18.next = &l19;
    }
};

int main()
{
    Solutions solution;

    Question1 q1;
    cout<<"Q1 :\n";
    print_linklist(&q1.l10);
    vector<ListNode*> q1_result = solution.splitListToPart(&q1.l10, 5);
    for (int i = 0; i < q1_result.size(); i++) {
        print_linklist(q1_result[i]);
    }
    Question2 q2;
    cout<<"Q2 :\n";
    print_linklist(&q2.l10);
    vector<ListNode*> q2_result = solution.splitListToPart(&q2.l10, 3);
    for (int i = 0; i < q2_result.size(); i++) {
        print_linklist(q2_result[i]);
    }
}
