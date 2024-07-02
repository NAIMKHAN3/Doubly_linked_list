#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

bool is_palindrome(Node *head, Node *tail)
{
    Node *temp = head;
    Node *temp2 = tail;
    bool flag = true;
    while (true)
    {
        if (temp == temp2)
        {
            break;
        }
        if (temp->next == temp2)
        {
            if (temp->val != temp2->val)
            {
                flag = false;
            }
            break;
        }
        if (temp->val != temp2->val)
        {
            flag = false;
            break;
        }
        temp = temp->next;
        temp2 = temp2->prev;
    }
    return flag;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, tail, val);
    }
    if(is_palindrome(head, tail)){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
    return 0;
}