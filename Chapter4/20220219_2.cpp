// P53.204.�Ƴ�����Ԫ��
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

    //ͷ���ͷǻ�ͷ���ֿ�ɾ��
    ListNode *removeElements1(ListNode *head, int val)
    {
        //ɾ��ͷ���
        while (head != NULL && head->val == val)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        //ɾ����ͷ���
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

    //ʹ������ͷ�����һ��ɾ�����е�
    ListNode *removeElements2(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        //ɾ�����н��
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
