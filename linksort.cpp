#include"bankaccount.h"
bankaccount* addTwo(bankaccount* l1, bankaccount* l2);
bankaccount* sortList(bankaccount* head) 
{
    if (NULL == head || NULL == head->next) return head;

    bankaccount* pre = head, * low = head, * fast = head;
    while (fast && fast->next)
    {
        pre = low;
        low = low->next;
        fast = fast->next->next;
    }
    pre->next = nullptr;

    return addTwo(sortList(head), sortList(low));
}
bankaccount* addTwo(bankaccount* l1, bankaccount* l2)
{
    if (NULL == l1) return l2;
    if (NULL == l2) return l1;
    if (l1->getremain() < l2->getremain())
    {
        l1->next = addTwo(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = addTwo(l1, l2->next);
        return l2;
    }
}