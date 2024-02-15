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

void printListNode(ListNode *list1){
    while(list1 != NULL){
        cout << list1->val << " ";
        list1 = list1->next;
    }cout << endl;
}


int main(){

    ListNode* List1 = new ListNode(-1);
    ListNode* temp = List1;
    for(int i = 1; i < 10; i++){
        ListNode* newNode = new ListNode(i);
        temp->next = newNode;
        temp = newNode;
    }

    ListNode* REVERSED = reverseSinglyLinkedList(List1->next);
    printListNode(REVERSED); cout << endl;

    return 0;
}