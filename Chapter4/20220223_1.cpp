// P61.206.反转链表
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    //双指针法
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    //递归法
    ListNode* reverseList2(ListNode* head) {
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if(cur == NULL){
            return pre;
        }
        ListNode* temp = cur->next;
        cur->next = pre;
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);
    }

};
