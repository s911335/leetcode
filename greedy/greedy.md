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

## 452. Minimum Number of Arrows to Burst Ballons:

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

## 406. Queue Reconstruction by Height:

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



