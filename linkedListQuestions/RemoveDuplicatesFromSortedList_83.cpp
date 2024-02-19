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
};

ListNode* deleteDuplicates(ListNode* head){
    ListNode* t1 = head;
    ListNode* copyHead = head;
    while(head){
        if(head->val == t1->val && t1 != NULL){
            t1 = t1->next;
        }

        if(t1 == NULL){ 
            head->next = t1;
            break;
        }

        if(t1->val != head->val && t1 != NULL){
            head->next = t1;
            head = head->next;
        }

    }

    return copyHead;
};


int main(){

    ListNode *List1 = new ListNode(-1);
    ListNode *temp = List1;
    for (int i = 1; i < 10; i++)
    {
        ListNode *newNode = new ListNode(i);
        temp->next = newNode;
        temp = newNode;
    }

    ListNode* node1 = new ListNode(1);
    node1->next = List1->next;
    ListNode* node2 = new ListNode(1);
    node2->next = node1;
    ListNode* node3 = new ListNode(9);
    ListNode* node4 = new ListNode(9);

    node3->next = node4;
    node1->next = node3;
    node2->next = node1;


    printListNode(node2);
    cout << endl;

    ListNode* newList = deleteDuplicates(node2);

    printListNode(newList);
    cout << endl;

    return 0;
}