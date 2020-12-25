#include <iostream>

struct LNode {
    int value;
    LNode *next;
};

typedef struct LNode LNode, *LinearList;

void init_list(LinearList &L) {
    L->next = nullptr;
    L->value = 0;
}

bool is_empty(LinearList &L) {
    return L->next == nullptr;
}

void insert(LinearList &L, int i, int value) {
    if (i < 0) return;

    int j = -1;
    LNode *p = L;
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }

    LNode *tmp = new LNode;
    tmp->value = value;
    tmp->next = p->next;
    p->next = tmp;
}

int main(int argc, const char *argv[]) {
    LinearList list = new LNode;
    init_list(list);

    insert(list, 0, 100);
    insert(list, 0, 300);
    insert(list, 1, 200);
    insert(list, 3, 400);

    std::cout << list->next->value;
    std::cout << std::endl;

    std::cout << list->next->next->value;
    std::cout << std::endl;
    
    std::cout << list->next->next->next->value;
    std::cout << std::endl;
    std::cout << list->next->next->next->next->value;
    return 0;
}