#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {};
};

void print_linklist(ListNode& head)
{
    cout<<"head ";
    ListNode* pointer = &head;
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
        return l1;
    }
};

struct Question1
{
    ListNode headA;
    ListNode a1;
    ListNode a2;
    ListNode headB;
    ListNode b1;
    ListNode b2;
    Question1 (): headA(1), a1(2), a2(4), headB(1), b1(3), b2(4)
    { 
        headA.next = &a1;
        a1.next = &a2;
        headB.next = &b1;
        b1.next = &b2;
    }
};

int main()
{
    Question1 q1;
    Solutions solution;
    cout<<"Q1 :\n";
    cout<<"A list = ";
    print_linklist(q1.headA);
    cout<<"B list = ";
    print_linklist(q1.headB);
    ListNode* q1_result = solution.mergeTwoLists(&q1.headA, &q1.headB);
    cout<<"merge two lists = ";
    print_linklist(*q1_result);
}
