#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// modify the remove functions: for when the linkedlist has only 1 element. Do this in other versions of linked list as well

class Node
{
public:
    int value;
    Node *next;
    Node(int value, Node *next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};

class LinkedList
{ // circular
private:
    Node *head;
    int size;

public:
    LinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    bool isEmpty()
    {
        return this->head == NULL;
    }

    void insertFront(int value)
    {
        Node *temp = new Node(value, this->head);
        if (isEmpty())
        {
            this->head = temp;
            temp->next = this->head;
            this->size++;
            return;
        }

        Node *current = this->head;
        while (current->next != this->head)
        {
            current = current->next;
        }
        current->next = temp;
        this->head = temp;
        this->size++;
    }

    void insertMiddle(int value, int position)
    {
        Node *temp = new Node(value);
        if (position > this->size)
        {
            cout << "Out of bound\n";
            return;
        }
        if(position==this->size){
            insertLast(value);
            return;
        }
        if (position == 0)
        {
            Node *current = this->head;
            while (current->next != this->head)
            {
                current = current->next;
            }
            current->next = temp;
            temp->next = this->head;
            this->head = temp;
            this->size++;
            return;
        }

        Node *current = this->head;
        int idx = 0;
        while (position - idx > 1)
        {
            current = current->next;
            idx++;
        }
        Node *latter = current->next;
        current->next = temp;
        temp->next = latter;
        this->size++;
    }

    void insertLast(int value)
    {
        Node *temp = new Node(value);
        if (isEmpty())
        {
            insertFront(value);
            return;
        }

        Node *current = this->head;
        while (current->next != this->head)
        {
            current = current->next;
        }
        current->next = temp;
        temp->next = this->head;
        this->size++;
    }

    void removeFront()
    {
        if (isEmpty())
            return;

        Node *current = this->head;
        while (current->next != this->head)
        {
            current = current->next;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        current->next = this->head;
        delete temp;
        this->size--;
    }

    void removeLast()
    {
        if (isEmpty())
            return;

        Node *current = this->head;

        while (current->next->next != this->head)
        {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = this->head;
        this->size--;
        delete temp;
    }

    void removeMiddle(int position){
        if(position==0){
            removeFront();
        }

        if(isEmpty()||position>this->size)return;

        Node* current=this->head;
        int idx=0;
        while(position-idx>1){
            current=current->next;
            idx++;
        }
        Node* temp=current->next;
        current->next=temp->next;
        delete temp;
        this->size--;
    }

    int getSize(){
        return this->size;
    }

    void print()
    {
        Node *current = this->head;
        while (current != NULL)
        {
            cout << current->value << " -> ";
            current = current->next;
            if (current->next == this->head)
                break;
        }
        if (current != this->head)
            cout << current->value << endl;
        cout << endl;
    }
};

int main()
{
    fastio;

    LinkedList ll = LinkedList();
    ll.insertFront(2);
    ll.insertLast(3);
    ll.insertFront(5);
    ll.insertMiddle(1,0);
    ll.removeMiddle(2);
    ll.print();

    return 0;
}