#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
    Node* head;

    public:
    LinkedList(): head(NULL) {}

    void AddAtBeginning(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void nthFromBack(int pos)
    {
        Node* first = head;
        Node* second = head;

        for(int i = 0; i < pos; i++)
        {
            second = second->next;
        }

        while(second != NULL)
        {
            first = first->next;
            second = second->next;
        }

        cout << "The data of the node at " << pos << " position is : " << first->data << endl;
    }

    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    int num = 3;
    LinkedList head;
    head.AddAtBeginning(50);
    head.AddAtBeginning(40);
    head.AddAtBeginning(30);
    head.AddAtBeginning(20);
    head.AddAtBeginning(10);

    head.display();

    head.nthFromBack(num);
}