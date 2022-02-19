// P51.单链表定义
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

int main()
{
    ListNode* head = new ListNode(5);
}