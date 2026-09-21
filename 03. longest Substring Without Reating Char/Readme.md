LeetCode 2. Add Two Numbers
Problem Statement

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each node contains a single digit.

Add the two numbers and return the sum as a linked list.

Example
Plain Text
1
Input:
2
l1 = [2,4,3]
3
l2 = [5,6,4]
4
 
5
Output:
6
[7,0,8]
7
 
8
Explanation:
9
342 + 465 = 807
Show more lines
Approach

We simulate the same process used in elementary addition:

Traverse both linked lists simultaneously.
Add the current digits along with any carry from the previous step.
Create a new node containing sum % 10.
Update carry as sum / 10.
Continue until both lists are exhausted and no carry remains.

A dummy node is used to simplify the construction of the result linked list.
