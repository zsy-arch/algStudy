#include <iostream>

struct LNode
{
    int value;
    LNode *next;
};

typedef struct LNode LNode, *LinearList;

void init_list(LinearList &L)
{
    L->next = nullptr;
    L->value = 0;
}

bool is_empty(LinearList &L)
{
    return L->next == nullptr;
}

LNode *index_of(LinearList &L, int i)
{
    if (i < 0)
        return 0;
    int j = -1;
    LNode *p = L;
    while (j < i)
    {
        j++;
        p = p->next;
    }
    return p;
}

void insert(LinearList &L, int i, int value)
{
    if (i < 0)
        return;

    int j = -1;
    LNode *p = L;
    while (p != nullptr && j < i - 1)
    {
        p = p->next;
        j++;
    }

    LNode *tmp = new LNode;
    tmp->value = value;
    tmp->next = p->next;
    p->next = tmp;
}

void insert_before(LinearList &L, LNode *origin, LNode *newNode)
{
    newNode->next = origin->next;
    origin->next = newNode;
    int v = origin->value;
    origin->value = newNode->value;
    newNode->value = v;
}

void insert_after(LinearList &L, LNode *origin, LNode *newNode)
{
    newNode->next = origin->next;
    origin->next = newNode;
}

void erase(LinearList &L, int index, int *retVal = nullptr)
{
    int j = -1;
    LNode *p = L;
    while (j < index - 1)
    {
        j++;
        p = p->next;
    }
    if (retVal != nullptr)
    {
        *retVal = p->next->value;
    }
    p->next = p->next->next;
}

int size(LinearList &L)
{
    LNode *p = L;
    int n = -1;
    while (p != nullptr)
    {
        p = p->next;
        n++;
    }
    return n;
}

void print(LinearList &L)
{
    LNode *p = L->next;
    for (int i = 0; i < size(L); i++)
    {
        std::cout << p->value << std::endl;
        p = p->next;
    }
}

int main(int argc, const char *argv[])
{
    LinearList list = new LNode;
    init_list(list);

    insert(list, 0, 100);
    insert(list, 1, 200);
    insert(list, 2, 300);
    insert(list, 1, 400);

    LNode *node0 = index_of(list, 0);
    LNode *newNode0 = new LNode;
    newNode0->value = 1000;
    insert_before(list, node0, newNode0);
    erase(list, 1);
    print(list);
    return 0;
}