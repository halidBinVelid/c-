#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head)
{

    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
        if (count > pow(10, 4))
            return true;
    }
    return false;
}

int main()
{

    ListNode *List1 = new ListNode(-1);
    ListNode *temp = List1;
    for (int i = 1; i < 101; i++)
    {
        ListNode *newNode = new ListNode(i);
        temp->next = newNode;
        temp = newNode;
    }

    bool cycle = hasCycle(List1);
    cout << cycle << endl;
    
    return 0;
}