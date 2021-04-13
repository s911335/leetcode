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
    ListNode* oddEvenList(ListNode* head)
    {
        int count = 0;
        ListNode* odd = new ListNode(-1);
        ListNode* odd_head = odd;
        ListNode* even = new ListNode(-2);
        ListNode* even_head = even;
        while (head) {
            count++;
            if (count % 2 == 1) {
                odd->next = head;
                odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
        }
        even->next = NULL;
        odd->next = even_head->next;
        return odd_head->next;
    }
};

struct Question1
{
    ListNode l10;
    ListNode l11;
    ListNode l12;
    ListNode l13;
    ListNode l14;
    Question1 (): l10(1), l11(2), l12(3), l13(4), l14(5)
    { 
        l10.next = &l11;
        l11.next = &l12;
        l12.next = &l13;
        l13.next = &l14;
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
    Question2 (): l10(2), l11(1), l12(3), l13(5), l14(6), l15(4), l16(7)
    {
        l10.next = &l11;
        l11.next = &l12;
        l12.next = &l13;
        l13.next = &l14;
        l14.next = &l15;
        l15.next = &l16;
    }
};

int main()
{
    Solutions solution;

    Question1 q1;
    cout<<"Q1 :\n";
    print_linklist(&q1.l10);
    ListNode* q1_result = solution.oddEvenList(&q1.l10);
    cout<<"result = ";
    print_linklist(q1_result);

    Question2 q2;
    cout<<"Q2 :\n";
    print_linklist(&q2.l10);
    ListNode* q2_result = solution.oddEvenList(&q2.l10);
    cout<<"result = ";
    print_linklist(q2_result);
}
