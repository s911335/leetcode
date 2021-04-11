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

ListNode* reverseList(ListNode* head)
{
    if (head == NULL)
        return head;
        ListNode new_head(-1);
        ListNode* pointer = head;
        while (pointer != NULL)
        {
            if (new_head.next == NULL)
            {
                new_head.next = pointer;
                pointer = pointer->next;
                new_head.next->next = NULL;
            }
            else
            {
                ListNode* record = new_head.next;
                new_head.next = pointer;
                pointer = pointer->next;
                new_head.next->next = record;
             }
         }
         return new_head.next;  
}  

class Solutions
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* reverse_l1 = reverseList(l1);
        ListNode* reverse_l2 = reverseList(l2);
        int carry = 0;
        int sum = 0;
        ListNode answer(-1);
        ListNode* pointer = NULL;
        while (reverse_l1 != NULL || reverse_l2 != NULL)
        {
            if (reverse_l1 != NULL && reverse_l2 != NULL)
                sum = reverse_l1->val + reverse_l2->val + carry; 
            else if (reverse_l1 == NULL && reverse_l2 != NULL)
                sum = reverse_l2->val + carry;
            else if (reverse_l2 == NULL && reverse_l1 != NULL)
                sum = reverse_l1->val + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;
            ListNode* pointer = new ListNode(sum);
            ListNode* record = answer.next;
            answer.next = pointer;
            answer.next->next = record;
            if (reverse_l1 != NULL)
                reverse_l1 = reverse_l1->next; 
            if (reverse_l2 != NULL)
                reverse_l2 = reverse_l2->next; 
        }
        if (carry == 1)
        {
            ListNode* pointer = new ListNode(1);
            ListNode* record = answer.next;
            answer.next = pointer;
            answer.next->next = record;
        }
        return answer.next;   
    }
};

struct Question1
{
    ListNode l10;
    ListNode l11;
    ListNode l12;
    ListNode l13;
    ListNode l20;
    ListNode l21;
    ListNode l22;
    Question1 (): l10(7), l11(2), l12(4), l13(3), l20(5), l21(6), l22(4)
    { 
        l10.next = &l11;
        l11.next = &l12;
        l12.next = &l13;
        l20.next = &l21;
        l21.next = &l22;
    }
};

struct Question2
{
    ListNode l10;
    ListNode l11;
    ListNode l12;
    ListNode l20;
    ListNode l21;
    ListNode l22;
    Question2 (): l10(2), l11(4), l12(3), l20(5), l21(6), l22(4) 
    {
        l10.next = &l11;
        l11.next = &l12;
        l20.next = &l21;
        l21.next = &l22;
    }
};

int main()
{
    Solutions solution;

    Question1 q1;
    cout<<"Q1 :\n";
    cout<<"l1 = ";
    print_linklist(q1.l10);
    cout<<"l2 = ";
    print_linklist(q1.l20);
    ListNode* q1_result = solution.addTwoNumbers(&q1.l10, &q1.l20);
    cout<<"sum = ";
    print_linklist(*q1_result);

    Question2 q2;
    cout<<"Q2 :\n";
    cout<<"l1 = ";
    print_linklist(q2.l10);
    cout<<"l2 = ";
    print_linklist(q2.l20);
    ListNode* q2_result = solution.addTwoNumbers(&q2.l10, &q2.l20);
    cout<<"sum = ";
    print_linklist(*q2_result);
}
