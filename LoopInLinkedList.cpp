#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val):data(val), next(nullptr) {}
};

bool detectTheLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

void removeLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            break;
        }
    }

    Node* temp = head;

    while(temp->next != slow->next)
    {
        temp = temp->next;
        slow = slow->next;
    }

    slow->next = NULL;
}

void display(Node* head)
{
    Node* temp = head;

    while(temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthOfLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            int count = 1;
            slow = slow->next;
            while(slow != fast)
            {
                count++;
                slow = slow->next;
            }
            return count;
        }
    }
    return 0;
}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;

    if(detectTheLoop(head))
    {
        cout << "There is a loop in the Linked List" << endl;
    }
    else
    {
        cout << "There is no loop in the Linked List" << endl;
    }

    cout << "The length of the loop is : " <<lengthOfLoop(head) << endl;

    removeLoop(head);

    cout << "The length of the loop is : " <<lengthOfLoop(head) << endl;

    display(head);
}