#pragma once
#include <stdexcept>
#include <cstddef>

template <typename Type>
class LinkedList
{
    struct Node
    {
        Node *nextNode = nullptr;
        Type value;
    };

    Node *Head = nullptr;
    Node *Last = nullptr;

public:
    LinkedList() = default;
    ~LinkedList(){
        Node *cur = Head;

        while (cur){
            Node *next = cur->nextNode;
            delete cur;
            cur = next;
        }
        Head = Last = nullptr;
    }

    int size()
    {
        Node *cur = Head;
        int accumulator = 0;
        while (cur != nullptr)
        {
            ++accumulator;
            cur = cur->nextNode;
        }
        return accumulator;
    }

    Type front(){
        if (Head == nullptr)
            throw std::out_of_range("index");
        return Head->value;
    }

    Type back() {
        if (Last == nullptr)
            throw std::out_of_range("index");
        return Last->value;
    }

    Type at(unsigned const int index)   {
        if (index < 0)
            throw std::out_of_range("index");
        Node *cur = Head;
        for (int i = 0; i < index; ++i)
        {
            if (!cur)
                throw std::out_of_range("index");
            cur = cur->nextNode;
        }
        if (!cur)
            throw std::out_of_range("index");
        return cur->value;
    }

    Type middle()   {
        if(!Head)
            throw std::out_of_range("index");

        Node *fast = Head;
        Node *slow = Head;

        while (fast && fast->nextNode)  {
            fast = fast->nextNode->nextNode;
            slow = slow->nextNode;
        }

        return slow->value;
    }

    void pushBack(const Type &value)
    {
        Node *node = new Node{nullptr, value};
        if (Head == nullptr)
        {
            Head = node;
            Last = node;
        }
        else
        {
            Last->nextNode = node;
            Last = node;
        }
    }

    void insertAt(const Type &value, unsigned const int index)
    {
        unsigned int sizeOfList = size();

        if (index == 0)
        {
            Node *node = new Node{Head, value};
            Head = node;
            if (!Last)
                Last = node;
            return;
        }

        if (index >= sizeOfList) // treat as append when index is at or past the end
        {
            Node *node = new Node{nullptr, value};
            if (Last)
            {
                Last->nextNode = node;
                Last = node;
            }
            else
            {
                Head = Last = node;
            }
            return;
        }

        Node *prior = Head;
        // move to node at position index-1
        for (unsigned int i = 0; i + 1 < index; ++i)
        {
            if (prior == nullptr)
                throw std::out_of_range("index");
            prior = prior->nextNode;
        }

        Node *node = new Node{prior->nextNode, value};
        prior->nextNode = node;
    }

    void erase(unsigned const int index)
    {
        if (!Head)
            throw std::out_of_range("index");

        if (index == 0)
        {
            Node *toDelete = Head;
            Head = Head->nextNode;
            if (toDelete == Last)
                Last = nullptr;
            delete toDelete;
            return;
        }

        Node *prev = Head;
        for (unsigned i = 0; i < index - 1; ++i)
        {
            if (!prev->nextNode)
                throw std::out_of_range("index");
            prev = prev->nextNode;
        }

        Node *toDelete = prev->nextNode;
        if (!toDelete)
            throw std::out_of_range("index");

        prev->nextNode = toDelete->nextNode;
        if (toDelete == Last)
            Last = prev;
        delete toDelete;
    }

    void erase(unsigned const int index1, unsigned const int index2){
        if (!Head)
            throw std::out_of_range("index");
        if (index1 > index2)
            throw std::out_of_range("index");
        if (index1 == index2)
        {
            erase(index1);
            return;
        }

        Node *prev = nullptr;
        Node *start = Head;
        for (unsigned i = 0; i < index1; ++i)
        {
            if (!start)
                throw std::out_of_range("index");
            prev = start;
            start = start->nextNode;
        }
        if (!start)
            throw std::out_of_range("index");

        Node *end = start;
        for (unsigned i = index1; i < index2; ++i)
        {
            if (!end)
                throw std::out_of_range("index");
            end = end->nextNode;
        }
        if (!end)
            throw std::out_of_range("index");

        Node *after = end->nextNode;

        Node *cur = start;
        while (cur != after)
        {
            Node *next = cur->nextNode;
            delete cur;
            cur = next;
        }

        if (prev)
        {
            prev->nextNode = after;
        }
        else
        {
            Head = after;
        }

        if (!after)
        {
            Last = prev;
        }
        if (!Head)
        {
            Last = nullptr;
        }
    }

    void popBack()  {
        if (!Head)  {
            throw std::out_of_range("pop from empty list");
        }

        if (Head == Last)  {
            delete Head;
            Head = Last = nullptr;
            return;
        }

        Node *cur = Head;
        while (cur->nextNode != Last)   {
            cur = cur->nextNode;
        }

        delete Last;
        Last = cur;
        Last->nextNode = nullptr;
    }

    int countOccurrences(const Type &value)    {
        Node *current = Head;
        int accumulator = 0;

        while (current != nullptr) {
            if  (current->value == value)
                ++accumulator;
            current = current->nextNode;
        }

        return accumulator;
    }

    LinkedList &reverse()   {
        Node *prev = nullptr;
        Node *cur = Head;
        Last = Head;

        while (cur)
        {
            Node *next = cur->nextNode;
            cur->nextNode = prev;
            prev = cur;
            cur = next;
        }

        Head = prev;
        return *this;
    }

    LinkedList &split() {
        if (Head == nullptr)
        throw std::out_of_range("split empty list");
        
        Node *fast = Head;
        Node *slow = Head;
        Node *prev = nullptr;

        while (fast && fast->nextNode){
            fast = fast->nextNode->nextNode;
            prev = slow;
            slow = slow->nextNode;
        }
        
        LinkedList<Type> *newList = new LinkedList<Type>;

        if (prev)   {
            prev->nextNode = nullptr;
            Last = prev;
        }
        else    {
            Head = Last = nullptr;
        }


        newList->Head = slow;

        Node *cur = slow;
        Node *lastNode = nullptr;
        while (cur) {
            lastNode = cur;
            cur = cur->nextNode;
        }
        newList->Last = lastNode;

        return *newList;
    }

    LinkedList &split(unsigned const int index) {
        if (Head == nullptr)
            throw std::out_of_range("split empty list");

        if (index > size()) 
            throw std::out_of_range("index");
        
        Node * prev = nullptr;
        Node *current = Head;

        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->nextNode;
        }

        LinkedList<Type> *newList = new LinkedList<Type>;

        if (prev)   {
            prev->nextNode = nullptr;
            Last = prev;
        }
        else    {
            Head = Last = nullptr;
        }

        newList->Head = current;

        Node *cur = current;
        Node *lastNode = nullptr;
        while (cur){
            lastNode = cur;
            cur = cur->nextNode;
        }
        newList->Last = lastNode;

        return *newList;
    }

    LinkedList &splitAfterIndex(unsigned const int index) {
        return split(index + 1);
    }

    //nie wiem jak mam zwrócić nową posortowaną listę bez tworzenia nowych węzłów :(
    LinkedList &mergeSortedLists(const LinkedList &l1, const LinkedList &l2)    {
        LinkedList<Type> *newList = new LinkedList<Type>;

        Node *n1 = l1.Head;
        Node *n2 = l2.Head;

        while(n1 && n2) {
            if  (n1->value <= n2->value)    {
                newList->pushBack(n1->value);
                n1 = n1->nextNode;
            }   else    {
                newList->pushBack(n2->value);
                n2 = n2->nextNode;
            }
        }

        while (n1){
            newList->pushBack(n1->value);
            n1 = n1->nextNode;
        }

        while (n2){
            newList->pushBack(n2->value);
            n2 = n2->nextNode;
        }

        return *newList;
    }

    void mergeSort()
    {
        if (!Head || Head == Last)
            return;

        LinkedList<Type> &right = split();

        this->mergeSort();
        right.mergeSort();

        LinkedList<Type> &merged = mergeSortedLists(*this, right);

        Node *cur = Head;
        while (cur){
            Node *next = cur->nextNode;
            delete cur;
            cur = next;
        }

        LinkedList<Type> *rightPtr = &right;

        Head = merged.Head;
        Last = merged.Last;

        merged.Head = merged.Last = nullptr;
        delete &merged;

        delete rightPtr;
    }

    void createCycle() {
        if (!Head)
            return;

        Last->nextNode = Head;
    }
    
    bool hasCycle() {
        Node *slow = Head;
        Node *fast = Head;

        while (fast && fast->nextNode) {
            slow = slow->nextNode;
            fast = fast->nextNode->nextNode;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

