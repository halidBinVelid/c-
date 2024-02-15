#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode* copyHead = new ListNode(-1);
    ListNode* temp = copyHead;
    ListNode* t1 = head; //help me to solve last condition that stack size is less than k condition.

    stack<int>* stackListvalues = new stack<int>();

    while(head != NULL){
        stackListvalues->push(head->val);

        if(stackListvalues->size() == k){
            while(stackListvalues->size() != 0){
                ListNode* sth = new ListNode(stackListvalues->top());
                stackListvalues->pop();
                temp->next = sth;
                temp = sth;
            }

            if(head->next == NULL) return copyHead->next;
            t1 = head; // moving t1 after head; so that i will work on the last boundary.
        }

        if(head->next == NULL && stackListvalues->size() < k){ //ListNode* t1 = head; over here :)
            temp->next = t1->next;
        }

        head = head->next;
    }

    return copyHead->next;
}


void printListNode(ListNode *list1){
    while(list1 != NULL){
        cout << list1->val << " ";
        list1 = list1->next;
    }cout << endl;
}

ListNode* reverseSinglyLinkedList(ListNode* List){
    stack<int>* ListValues = new stack<int>();
    while(List != NULL){
        ListValues->push(List->val);
        List = List->next;
    }

    ListNode* reversedListNode = new ListNode(-1);
    ListNode* temp = reversedListNode;
    for(int i = ListValues->size() - 1; i >= 0; i-- ){
        int stackVal = ListValues->top();
        ListValues->pop();
        ListNode* sth = new ListNode(stackVal);
        temp->next = sth;
        temp = temp->next;
    }

    return reversedListNode->next;
}


int main()
{
    ListNode* List1 = new ListNode(-1);
    ListNode* temp = List1;
    for(int i = 1; i < 10; i++){
        ListNode* newNode = new ListNode(i);
        temp->next = newNode;
        temp = newNode;
    }
//------------------------------------------------------------------//
    printListNode(List1->next); cout << endl;
//------------------------------------------------------------------//
//reversing all
    ListNode* REVERSED = reverseSinglyLinkedList(List1->next);
    printListNode(REVERSED); cout << endl;
//------------------------------------------------------------------//
//reversing k group
    ListNode* REVERSEDKGROUP = reverseKGroup(List1->next, 4);
    printListNode(REVERSEDKGROUP);

    return 0;
}

