// P53.204.移除链表元素
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    //头结点和非机头结点分开删除
    ListNode *removeElements1(ListNode *head, int val)
    {
        //删除头结点
        while (head != NULL && head->val == val)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        //删除非头结点
        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }

    //使用虚拟头结点来一次删除所有的
    ListNode *removeElements2(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        //删除所有结点
        ListNode *cur = dummyHead;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
