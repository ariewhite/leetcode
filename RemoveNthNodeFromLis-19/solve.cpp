#include <iostream>

struct ListNode
{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * node) : val(x), next(node) {}

};


ListNode* removeNthNode(ListNode * head, int n)
{
    ListNode * ptr = new ListNode(0, head); // create new element w/ .next to head, so ptr is previous element in the list than head
    ListNode * node = ptr; // one more pointer 

    for (size_t i = 0; i < n; ++i) // set distance between 2 pointers (node and head) = n
    {
        head = head->next; // node = *0, head = *(sz - n)
    }

    while (head != nullptr) // end of the list
    {
        head = head->next; // move 1st pointer
        node = node->next; // move 2nd pointer
    }

    node->next = node->next->next; // current node is previous one to the one we want to remove,
    // so we relinked .next to .next element of the next element

    return ptr->next; // return original head.   
}


int main(){
    return 0;
}