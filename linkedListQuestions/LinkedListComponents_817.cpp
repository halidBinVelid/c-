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

void printListNode(ListNode *list1)
{
    while (list1 != NULL)
    {
        cout << list1->val << " ";
        list1 = list1->next;
    }
    cout << endl;
}

int numComponents(ListNode *head, vector<int> &nums)
{
    int count = 0;
    ListNode *t1 = head;
    ListNode *temp = head;

    while (head != NULL)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (t1 != NULL)
            {
                if (t1->val == nums[i])
                {
                    t1 = t1->next;
                    i = -1;
                }
            }
        }

        if (head != NULL && head != t1)
        {
            head = t1;
            count += 1;
            continue;
        }
        if (head == t1)
        {
            t1 = t1->next;
        }

        head = head->next;
    }

    return count;
}

int main()
{
    ListNode *List1 = new ListNode(-1);
    ListNode *temp = List1;
    for (int i = 1; i < 10; i++)
    {
        ListNode *newNode = new ListNode(i);
        temp->next = newNode;
        temp = newNode;
    }

    //------------------------------------------------------------------//
    printListNode(List1->next);
    cout << endl;
    //------------------------------------------------------------------//

    vector<int> nums;
    cout << "nums: ";
    for (int i = 1; i < 3; i++)
    {
        nums.push_back(i);
    }
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(6);
    // nums.push_back(8);
    // nums.push_back(9);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    int num = numComponents(List1->next, nums);
    cout << num << endl;

    return 0;
}