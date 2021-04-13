# LinkList

## 160. Intersection of Two Linked Lists

Given the heads of two singly linked-lists headA and headB, return the node
at which the list interset. If the two linked lists have no intersection
at all, return null.

### Ex:

1. intersecVal = 8, list A = [4, 1, 8, 4, 5], list B = [5, 6, 1, 8, 4, 5],
   skipA = 2. skipB = 3. Output: intersected at '8'.
2. intersecVal = 2, list A = [1, 9, 1, 2, 4], list B = [3, 2, 4],
     skipA = 3, skipB = 1. Output: intersected at '2'.
3. intersecVal = 0, list A = [2, 6, 4], list B = [1, 5].
     skipA = 3. skipB = 2. Output: No intersection.

### Solution:

1. Due to list A = a + c and list B = b + c, c is overlapping area. Therefore,
   we need to loop the interval with a + b + c and can get a intersection.
2. Set a_pointer = headA pointer, b_pointer = headB pointer. And to do whileloop
   with the condition that a_pointer is not equal to b_pointer.
3. If a_pointer is not NULL, a_pointer = pointer of next a_pointer. 
   If a_pointer = NULL, let a_pointer = headB pointer for each loop.
4. If b_pointer is not NULL, b_pointer = pointer of next a_pointer. 
   If b_pointer = NULL, let b_pointer = headA pointer for each loop.
5. After whileloop, return a_pointer or b_pointer.

## 206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the
reversed list.

### Ex:

1. Input: head = [1, 2, 3, 4, 5]; Output: [5, 4, 3, 2, 1];
2. Input: head = [1, 2]; Output: [2, 1];
3. Input: head = []; Output: []

### Solution:

1. If the lenght of linklist is 5, there are 5 pointers in linklis. Therefore,
   we need to set the new head to connect this 5 pointers.
2. First, new head connect the pointer of head of linklist.
3. Second, to break the next of new head and inserted next pointer to new head.
4. Third, connect the last pointer to new head.next->next.
5. For example, the linklist is 1 -> 2 -> 3 -> 4 -> 5, new head -> NULL. Next,
   new head -> 1, new head -> 2, new head -> 2 -> 1, new head -> 3,
   new head -> 3 -> 2 -> 1 ... and so on.

## 21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a sorted list. The list should be
made by splicing together the nodes of first two lists.

### Ex:

1. Input: l1 = [1, 2, 4], l2 = [1, 3, 4]. Output: [1, 1, 2, 3, 4, 4].
2. Input: l1 = [], l2 = []. Output: [].
3. Input: l1 = [], l2 = [0]. Outout: [0].

### Solution:
1. check the condition, if l1 == NULL, return l2, if l2 == NULL, return l1.
2. By recursive function, if l1.val is smaller than l2.val, let l1.next = 
   mergeTwoLists(l1.next, l2) and return l2.
3. Else, l2.next = mergeTwoLists(l1, l2.next) and return l2.

## 83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each
element appears only once. Return the linklist sorted as well.

### Ex:

1. Input = [1, 1, 2]. Output = [1, 2].
2. Input = [1, 1, 2, 3, 3]. Output = [1, 2, 3].

### Solution:
1. Set the condition, if head is NULL or next of the head is NULL, return head.
2. If find the repeat element, do whileloop to find the end of the repeat.
3. If pointer of the next is NULL when doing whileloop, return pointer.
4. Next, do recursive function, deleteDuplicates.

## 19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list
and return its head.

### Ex:
1. Input: head = [1, 2, 3, 4, 5], n = 2. Output: [1, 2, 3, 5].
2. Input: head = [1], n = 1. Output: [].
3. Input: head = [1, 2], n = 1. Output: [1].

### Solution:
1. Set two pointer about pointer0 is head and pointer1 which is difference of 
   n element as head.
2. If pointer1 is NULL, return pointer of next head.
3. Do whileloop to find pointer1 is NULL and pointer0 is next pointer0, pointer1
   is next pointer1 in each loop.
4. If find the pointer1 is NULL, let pointer0 of next is pointer0 of next of 
   next.
5. Return head.

## 24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

### Ex:

1. Input: head = [1, 2, 3, 4]. Output: [2, 1, 4, 3].
2. Input: head = []. Output: [].
3. Input: head = [1]. Output: [].

### Solution:

1. Set the condition, if head is NULL or pointer of the next is NULL, return
   head.
2. Set ListNode n1 is head, n3 is pointer of next of next.
3. To swap n1 and n2, like this 1 -> 2 to 2 -> 1.
4. Next 1 to connect the recursive function, like this 2 -> 1, head->next->next
   is equal to swapPairs(n3).
5. Finally, return head.

## 445. Add Two Number II

You are given two non-empty linked lists representing two non-negative
integers. The most significant digit comes first and each of their nodes
contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Follow up:
What if you cannot modify the input lists? In order words, reversing the
lists is not allowed.

### Ex:

1. Input: l1 = [7,2,4,3], l2 = [5,6,4], Output: [7,8,0,7]
2. Input: l1 = [2,4,3], l2 = [5,6,4], Output: [8,0,7]
3. Input: l1 = [2,4,3], l2 = [5,6,4], Output: [8,0,7]

### Solution:

1. Create reverseList function to get reverse_l1 and reverse_l2, leecode206.
2. Set sum = 0, carry = 0, answer = ListNode(-1).
2. while loop for reverse_l1 and reverse_l2.
3. if rev_l1_pointer->val + rev_l2_pointer->val + carry is larger than
   equal to 10. Let carry = 1 and sum -= 10.
4. Next, create pointer of ListNode(sum).
5. Connect ListNode(-1) by head insertion.
6. Finally, return answer.next after whileloop.

## 234. Palindrome Linked List

Given the head of a singly linked list, true if it is a palindrome.

### Ex:

1. Input: head = [1, 2, 2, 1]. Output: true.
2. Input: head = [1, 2]. Outout: false.

### Solutions:

1. Get the length of LinkList.
2. Cut the LinkList to two part which the length is same as each other.
3. Next, reverse second part.
4. Each element of first part is compared to element of second part.
5. If all element of first part is same as all element of second part, return
   true, else return false.

## 725. Split Linked List in Parts

Given a (singly) linked list with head node root, write a function to split
the linked list into k consecutive linked list "parts".

The lenght of each part should be as equal as possible: no two parts should
have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts
occurring earlier should always have a size greater than or equal parts
occurring later.

Return a list of ListNode's representing tje linked list part that are formed.

### Ex:

1. root = [1, 2, 3, 4], k = 5, Output = [[1], [2], [3], [4], null].
2. root = [1, 2, 3], k = 5, Output = [[1], [2], [3], null, null].
3. root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3,
   Output = [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]].

### Solution:

1. Get the lenght of the root, count.
2. Create vector<ListNode*> answer[k].
3. Get num = count / k, remainder = count % k.
3. To do forloop of answer.size(), if pointer is NULL, answer[i] is NULL.
4. Else, if remainder is lager than zero, let carry is num + 1, else carry is
   num. And answer[i] is the pointer which points bewteen now pointer to
   carry-1 steps pointers.
5. Record the pointer->next for answer[i+1].

