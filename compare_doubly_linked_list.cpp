#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node * prev;
    Node * next;
    Node(int val){
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

bool same_or_not(Node *head, Node *head2)
{
    bool flag = true;
    while (head != NULL && head2 != NULL)
    {

        if (head->val != head2->val)
        {
            flag = false;
            break;
        }
        head = head->next;
        head2 = head2->next;
    }
    if (head == NULL && head2 == NULL)
    {

        return flag;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;
    Node * head2 = NULL;
    Node * tail2 = NULL;
     while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, tail, val);
    }
    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head2, tail2, val);
    }
    bool result = same_or_not(head, head2);
    if (result)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}