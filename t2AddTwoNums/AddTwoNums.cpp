#include <bits/stdc++.h>

using namespace std;
//
// Created by Steve on 2021/11/1.
//

/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in
 * reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked
 * list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Example:
 * 题⽬⼤意
 * 2 个逆序的链表，要求从低位开始相加，得出结果也逆序输出，返回值是逆序结果链表的头结点。
 * <p>
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class AddTwoNums {
public:
    ListNode *addTwoNums(ListNode *first, ListNode *second) {
        //1.初始化一个临时虚拟节点(0)
        auto dummy = new ListNode(0);
        //2.定义临时变量
        auto current = dummy;
        int carry = 0;
        while (first || second) {
            int x = first->val;
            int y = second->val;
            //补上一轮进位的余数
            int sum = carry + x + y;
            carry = sum / 10;
            //下一节点指向本轮各节点和的商值
            current->next = new ListNode(sum % 10);
            //开启下一轮循环(节点位置向下移动)
            first = first->next;
            second = second->next;
        }
        //余数超过0进位末位节点
        if (carry > 0) {
            current->next = new ListNode(carry);
        }
        return dummy->next;
    }
};

