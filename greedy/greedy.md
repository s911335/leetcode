# Greedy Algorithm

## 455. Assign Cookie

Assume you are an awesome parent and want to give your children some cookies.
But, you sould give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie
that the child will be content with; and each cookie j has a size s[j].
If s[j] >= g[i], we can assign the cookie j to the child i, and the child i
will be content. Your goal is to maximize the number of your content children
and output the maximum number.

1. g = [1, 2, 3], s = [1, 1]  Output: 1
2. g = [1, 2], s = [1, 2, 3]  Output: 2

Solution:
1. Sort vector g and vector s.
2. Set pointer of g and pointer of s to size() - 1.
3. If s[pointer of s] >= g[pointer of g], make result count plus one and move
   pointer of s and pointer of g to left.
4. If g[pointer of g] > s[pointer of s], move pointer of g to left.
5. If pointer of g or s can't move, return result count.

## 435. Non-overlapping Intervals

Given a collection of intervals, find the mininmum number of intervals you need
to remove to make the rest of the intervals non-overlapping.

1. Input[[1, 2], [2, 3], [3, 4], [1, 3]]  Output: 1
2. Input[[1, 2], [1, 2], [1, 2]]  Output: 2
3. Input[[1, 2], [2, 3]] Output: 0

Note:
1. You may assume the interval's end point is always bigger than its start point.
2. Intervals like [1, 2] and [2, 3] have borders "touching" but they don't
   overlap each other.

Solutions:
1. Intervals shall be sorted by following last element of vector of vector.
2. set result = 0 and pointer = intervals[0][0].
3. To do forloop for intervals sizes.
4. If vector[0] > pointer, let pointer = vector[1].
5. if vector[0] > pointer is not true, let result plus one.
6. Finally, return result.

## 452. Minimum Number of Arrows to Burst Ballons

There are some spherical balloons spread in two-dimensional space. For each
balloon, provided input is the start and end coordinates of the horizontal
diameter. Since it's horizontal, y-coordinates don't matter, and hence the
x-coordinates of start and end of the diameter suffice. The start is always
smaller than end. An arrow can be shot up exactly vertically from different
points along the x-axis. A ballon with x_start and x_end bursts by an arrow
shot at x if x_end >= x >= x_start. There is no limit to the number of arrows
that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array points where point[i] = [x_start, x_end], return the minimum
number of arrows that must be shot to burst all ballons

Ex1: Input: [[10, 16], [2, 8], [1, 6], [7, 12]], Output = 2
Ex2: Input: [[1, 2], [3, 4], [5, 6], [7, 8]], Output = 4
Ex3: Input: [[1, 2], [2, 3], [3, 4], [4, 5]], Output = 2
Ex4: Input: [[1, 2]], Output = 1
Ex5: Input: [[2, 3], [2, 3]], Output = 1

Solution:
1. points shall be sorted by following last element of vector of vector.
2. set arrows = 0 and pointer = points[0][1]
3. To do forloop for intervals sizes.
4. if points[i][0] > pointer, let pointer = point[i][1] and arrows plus one.
5. Finally, return arrows.

## 406. Queue Reconstruction by Height

You are given an array of people, people, which are the attributes of some
people in a queue (not necessarily in order). Each people[i] = [hi, ki]
represents the i th person of height hi with exactly ki other people in
front who have a height greater than or equal to hi.
Reconstruct and return the queue that is represeted by input array people.
The returned queue should be formatted as an array queue, where
queue[j] = [hj, kj] is the attributes of the j th person in the queue (
queue[0] is the person at front of the queue).

Ex1: people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]],
     output = [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]].
Ex2: people = [[6, 0], [5, 0], [4, 0], [3, 2], [1, 4], [6, 0]].
     output = [[4, 0], [5, 0], [2, 2], [3, 2], [1, 4], [6, 0]].

Solution:
1. sort people by following h descending and k ascending. For example:
   [[7, 0], [7, 1], [6, 1], [5, 0], [5, 2], [4, 4]].
2. set result as vector and size is same as people. Let all element in
   result vector are the same as people[0]. For example:
   [[7, 0], [7, 0], [7, 0], [7, 0], [7, 0], [7, 0]]
3. Move last element in people to kth place in result vector. If kth
   place is not right place. Move to (k+1)th place in result vector.
   You will understand it when you follow by leetcode_406.cpp. 
4. Move next last element in people and Repeat step 3. 

## 121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock
on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell the stock.
Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.

Ex1: prices = [7, 1, 5, 3, 6, 4], Output = 5.
Ex2: prices = [7, 6, 4, 3, 1], Output = 0.
Ex3: prices = [2, 4, 1], Output = 2.

Solution:
1. Set max = 0, min = prices[0]
2. To do forloop of size of prices.
3. If min > prices[i], let min = prices[i].
4. If (prices[i] - min) > max, let max = prices[i] - min.
5. Return max.

## 122. Best Time to Buy and Sell Stock II

You are given an array prices where prices[i] is the price of a given stock
on the ith day.
Find the maximum profit you can achueve. You may complete as many transaction
as you like. (i.e, buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions simultaneously (i.e, you
must sell the stock before you buy again).

Ex1: prices = [7, 1, 5, 3, 6, 4]. Output = 7 = (5 - 1) + (6 - 3)
Ex2: prices = [1, 2, 3, 4, 5]. Output = 4 = 5 - 1.
Ex3: prices = [7, 6, 4, 3, 1]. Output = 0

Solution:
1. This problem is different from leetcode 121 due to lots of transactions.
2. Therefore, Need to set pointer is last element and max = 0.
3. To do foorloop of prices of size, if (i-1) element is smaller than i element,
   we need to add difference between i element to i-1 element to max value..
4. Finally, Return max.

## 605. Can Place Flowers

You can a long flowerbed in which some of plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty
and 1 means not empty, and an integer n, return if n new flowers can be
planted in the flowerbed without violating the no-adjacent-flowers rule.

Ex1: flowerbed = [1, 0, 0, 0, 1], n = 1, Output: True.
Ex2: flowerbed = [1, 0, 0, 0, 1], n = 2, Output: False.

Solution:
1. To check flowerbed size is whether equal to one. If equal to one, make a
   conditions.
2. To check first element and last one element can be insert to a flower.
3. If element in the intervals can be inserted, let element[i] = 1 and
   n minus one.
4. To forloop in intervals, to check element in the intervals and inserted
   a flower to intervals.
5. If element in the intervals can be inserted, let element[i] = 1 and
   n minus one.
6. Finally, if n <= 0, return true. if not, return false.

## 392. Is Subsequence

Given two string s and t, check if s is a subsequence of t.

A subsequence of a string is a new string that is formed from the original
string by seleting some (can be none) of characters without disturbing the
relative positions of the remaining characters. (i.e., "ace" is a subsequence
of "abcde" while "aec" is not)

Ex1. Input: s = "abc", t = "ahbgdc", Output: true.
Ex2. Input: s = "axc", t = "ahbgdc", Output: false.

Solution:
1. Set conditions, if s.size() == 0, return true. Due to no element in s array.
2. Set s_pointer = 0 and t_pointer = 0. To do while loop with the conditions
   t.size() > t_pointer and t_pointer++ in each loop.
3. if s[s_pointer] == t[t_pointer], s_pointer++.
4. if s_pointer == s.size(), return true.
5. if while loop is end and not to return true, return false.

## 665. Non-decreasing Array

Given an array nums with n integers, your task is to check if it could become
non-decreasing by modifying ar most one element.

We define an array is non-decreasing if nums[i + 1] >= nums[i] holds for every
i (0-based) such that (n - 2 >= i >= 0).

Ex1: Input: nums = [4, 2, 3], Output: true.
Ex2: Input: nums = [4, 2, 1], Output: false.

Solution:
1. Set condition: if nums.size() is smaller than 3, return true.
2. Set error_count = 0, pointer = 1.
3. To do while loop with the condition pointer is smaller than nums.size()
   and pointer plus on in each loop.
4. If find that nums[i] and nums[i-1] is not non-decreasing. To check
   nums[i-1] and nums[i+1].
5. If nums[i-1] is larger than and equal to nums[i+1]. Let
   nums[i-1] = nums[i+1]. else nums[i] = nums[i-1].
6. And make error_count plus one, pointer set zero and reset while loop.
7. If error_count is equal to 2. return false.
8. If while loop is done, return true.
