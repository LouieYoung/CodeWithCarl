// 24.两两交换链表中的节点
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

    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next !=nullptr){
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = cur->next->next->next;

            cur->next=cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp2;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};
