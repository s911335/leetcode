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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* pointer0 = head;
        ListNode* pointer1 = head;
        while (n != 0)
        {
            pointer1 = pointer1->next;
            n--;
        }
        if (pointer1 == NULL)
            return head->next;
        while (pointer1->next != NULL)
        {  
            pointer0 = pointer0->next;
            pointer1 = pointer1->next;
        }
        pointer0->next = pointer0->next->next;
        return head;   
    }
};

struct Question1
{
    ListNode head;
    ListNode a1;
    ListNode a2;
    ListNode a3;
    ListNode a4;
    Question1 (): head(1), a1(2), a2(3), a3(4), a4(5)
    { 
        head.next = &a1;
        a1.next = &a2;
        a2.next = &a3;
        a3.next = &a4;
    }
};

struct Question2
{
    ListNode head;
    Question2 (): head(1) {}
};

struct Question3
{
    ListNode head;
    ListNode a1;
    Question3 (): head(1), a1(2)
    { 
        head.next = &a1;
    }
};

int main()
{
    Question1 q1;
    Solutions solution;
    cout<<"Q1 :\n";
    cout<<"head list = ";
    print_linklist(q1.head);
    ListNode* q1_result = solution.removeNthFromEnd(&q1.head, 5);
    cout<<"lists = ";
    print_linklist(*q1_result);

    Question2 q2;
    cout<<"Q2 :\n";
    cout<<"head list = ";
    print_linklist(q2.head);
    ListNode* q2_result = solution.removeNthFromEnd(&q2.head, 1);
    cout<<"lists = ";
    print_linklist(*q2_result);

    Question3 q3;
    cout<<"Q3 :\n";
    cout<<"head list = ";
    print_linklist(q3.head);
    ListNode* q3_result = solution.removeNthFromEnd(&q3.head, 1);
    cout<<"ists = ";
    print_linklist(*q3_result);
}
