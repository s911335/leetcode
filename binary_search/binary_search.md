# Binary Search

## 69. Sqrt(x)

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only
the integer part of the result is returned.

### Ex:

1. Input: x = 4, Output: 2
2. Input: x = 8, Output: 2.

### Solution:

1. It is understood that sqrt = x / sqrt, therefore, we need to get mid of x.
2. mid = (1+x)/2, but it may be integer overflow. So, mid = l + (r-l)/2 is 
   better.
3. To do whileloop with condition that l is smaller than r, let q = x / mid,
   if (mid-q) is smaller than 1, return q.
4. Its question is about binary search algorithm.

## 744. Find Smallest Letter Greater Than Target.

Given a list of sorted characters letters containing only lowercase letters,
and given a target letter target, find the smallest element in the list that
is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and
letters = ['a', 'b'], the answer is 'a'.

### Ex:

1. Input: letters = ['c', 'f', 'j'], target = 'a'. Output: 'c'.
2. Input: letters = ['c', 'f', 'j'], target = 'c'. Output: 'f'.
3. Input: letters = ['c', 'f', 'j'], target = 'd'. Output: 'f'.
4. Input: letters = ['c', 'f', 'j'], target = 'g'. Output: 'j'.
5. Input: letters = ['c', 'f', 'j'], target = 'j'. Output: 'c'.
6. Input: letters = ['c', 'f', 'j'], target = 'k'. Output: 'c'.

### Solution:

1. Letters is a sorted vector. Therefore, it is not sorted.
2. If target is larger or equal than letters[end] or target is smaller than
   letter[0], return letter[0].
3. Do whileloop to find the smallest element in the list by using
   binary search.
