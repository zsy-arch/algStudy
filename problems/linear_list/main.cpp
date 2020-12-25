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

int main(int argc, const char *argv[])
{
    LinearList list = new LNode;
    init_list(list);

    insert(list, 0, 100);
    insert(list, 1, 200);
    insert(list, 2, 300);
    insert(list, 1, 400);

    std::cout << index_of(list, 1)->value << '\n';

    std::cout << size(list) << '\n';
    return 0;
}