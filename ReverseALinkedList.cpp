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
    LinkedList():head(NULL) {}

    void AddAtBegining(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void Reverse()
    {
        Node* prevNode = NULL;
        Node* currentNode = head;
        Node* nextNode = NULL;

        while(currentNode != NULL)
        {
            nextNode = currentNode->next;
            currentNode->next = prevNode;

            prevNode = currentNode;
            currentNode = nextNode;
        }

        head = prevNode;
    }

    void display()
    {
        Node* temp = head;

        while(temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList head;
    head.AddAtBegining(10);
    head.AddAtBegining(20);
    head.AddAtBegining(30);
    head.AddAtBegining(40);
    head.AddAtBegining(50);

    head.display();

    head.Reverse();
    head.display();
}