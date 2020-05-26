#include "stack.h"

void stackInit(uint32_t total, uint8_t** base, uint8_t** head)
{
    *base = (uint8_t*)malloc(total);
    *head = *base;
}

uint32_t stackCount(uint8_t* base, uint8_t* head)
{
    return head - base;
}

uint8_t stackPush(uint8_t* base, uint8_t** head, uint8_t element, uint32_t size)
{
    if(stackCount(base, *head) == size)
    {
        printf("\nERROR: stack is full");
        return -1;
    }

    *head = *head + 1;
    **head = element;

    return 1;
}

uint8_t stackPop(uint8_t* base, uint8_t** head)
{
    if(stackCount(base, *head) == 0)
    {
        printf("\nERROR: stack is empty!");
        return -1;
    }

    uint8_t elem = **head;
    *head = *head - 1;

    return elem;
}

