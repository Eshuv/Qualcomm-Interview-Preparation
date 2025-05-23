#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void PreOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " -> " ;
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);    
    cout << root->data << " -> " ;
}

void InOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " -> " ;
    InOrder(root->right);
}

vector<vector<int>> LevelOrderTraversal(Node* root)
{
    vector<vector<int>> ans;
    if(root == NULL)
    {
        return ans;
    }

    queue<Node*> q;
    q.push(root);
    while(q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++)
        {
            Node* node = q.front();
            q.pop();
            if(node->left != NULL)
            {
                q.push(node->left);
            }
            if(node->right != NULL)
            {
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "PreOrder: ";
    PreOrder(root);
    cout << endl;

    cout << "PostOrder: ";
    PostOrder(root);
    cout << endl;

    cout << "InOrder: ";
    InOrder(root);
    cout << endl;
}