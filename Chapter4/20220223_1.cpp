// P61.206.��ת����
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

    //˫ָ�뷨
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

    //�ݹ鷨
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
