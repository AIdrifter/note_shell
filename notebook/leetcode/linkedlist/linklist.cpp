// C++ code
#include <iostream>
using std::cout;
using std::endl;


#define TEST 0

class LinkedList;

class ListNode{
private:
    int data;
    ListNode *next;
public:
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};

    friend class LinkedList;
};

class LinkedList{
private:
    // int size;
    ListNode *first;
public:
    LinkedList():first(0){};
    void PrintList();
    void Push_front(int x);
    void Push_back(int x);
    void Delete(int x);
    void Clear();
    void Sort();
    void FindLen();
    void Reverse();
};

// C++ code
void LinkedList::PrintList()
{
#if TEST
    if (first == 0) {
        cout << "List is empty.\n";
        return;
    }

    ListNode *current = first;
    while (current != 0) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
#else

#endif
}

// C++ code
void LinkedList::Push_front(int x)
{
#if TEST
    ListNode *newNode = new ListNode(x);
    newNode->next = first;
    first = newNode;
#else

#endif
}

// C++ code
void LinkedList::Push_back(int x)
{
#if TEST
    ListNode *newNode = new ListNode(x);

    if (first == 0) {
        first = newNode;
        return;
    }

    ListNode *current = first;
    while (current->next != 0) {
        current = current->next;
    }
    current->next = newNode;
#else

#endif
}


// C++ code
void LinkedList::Delete(int x)
{
#if TEST
    ListNode *current = first,
             *previous = 0;
    while (current != 0 && current->data != x) {
        previous = current;
        current = current->next;
    }

    if (current == 0) {
        std::cout << "There is no " << x << " in list.\n";
        // return;
    }
    else if (current == first) {
        first = current->next;
        delete current;
        current = 0;
        // return;
    }
    else {
        previous->next = current->next;
        delete current;
        current = 0;
        // return;
    }
#else

#endif
}


// C++ code
void LinkedList::Clear()
{
#if TEST
    while (first != 0) {            // Traversal
        ListNode *current = first;
        first = first->next;
        delete current;
        current = 0;
    }
#else

#endif
}

// C++ code
void LinkedList::Reverse()
{
#if TEST
    if (first == 0 || first->next == 0) {
        // list is empty or list has only one node
        return;
    }

    ListNode *previous = 0,
             *current = first,
             *preceding = first->next;

    while (preceding != 0) {
        current->next = previous;
        previous = current;
        current = preceding;
        preceding = preceding->next;
    }

    current->next = previous;
    first = current;
#else

#endif
}


void LinkedList::Sort()
{
}


void LinkedList::FindLen()
{
}


//C++ code
int main()
{

    LinkedList list;
    list.PrintList();
    list.Delete(4);
    list.Push_back(5);
    list.Push_back(3);
    list.Push_front(9);
    list.PrintList();
    list.Push_back(4);
    list.Delete(9);
    list.PrintList();
    list.Push_front(8);
    list.PrintList();
    list.Reverse();
    list.PrintList();
    list.Clear();
    list.PrintList();

    return 0;
}
