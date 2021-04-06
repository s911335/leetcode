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
