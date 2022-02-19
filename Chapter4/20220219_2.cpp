// P53.204.ÒÆ³ýÁ´±íÔªËØ
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string listNodeToString(ListNode *node)
    {
        if (node == nullptr)
        {
            return "[]";
        }

        string result;
        while (node)
        {
            result += to_string(node->val) + ", ";
            node = node->next;
        }
        return "[" + result.substr(0, result.length() - 2) + "]";
    }

    ListNode *stringToListNode(string input)
    {
        // Generate list from the input
        vector<int> list = this->stringToInteger(input);

        // Now convert that list into linked list
        ListNode *dummyRoot = new ListNode(0);
        ListNode *ptr = dummyRoot;
        for (int item : list)
        {
            ptr->next = new ListNode(item);
            ptr = ptr->next;
        }
        ptr = dummyRoot->next;
        delete dummyRoot;
        return ptr;
    }

    int stringToInteger(string input)
    {
        return stoi(input);
    }

    ListNode *removeElements(ListNode *head, int val)
    {
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main()
{

    Solution solution;
    ListNode *head = [ 7, 7, 7, 7 ];
    int val = 7;
    ListNode *nums = solution.removeElements(head, val);

    string out = solution.listNodeToString(ret);
    cout << out << endl;
}