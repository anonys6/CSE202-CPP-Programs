#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

int main()
{
    Node *one = Node(1);
    Node *two = Node(2);
    Node *three = Node(3);

    return 0;
}

