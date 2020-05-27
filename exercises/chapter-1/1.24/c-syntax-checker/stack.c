#include "stack.h"

Stack stackInit(uint32_t size)
{
    Stack newStack;

    newStack.size = size;
    newStack.base = (uint8_t*)malloc(size);
    newStack.head = newStack.base;

    return newStack;
}

uint32_t stackCount(Stack stack)
{
    uint32_t count = stack.head - stack.base;
    return count;
}

void stackPush(Stack* stack, uint8_t element)
{
    if(stackCount(*stack) == stack->size)
    {
        printf("\nERROR: stack is full");
    }

    stack->head = stack->head + 1;
    *stack->head = element;
}

uint8_t stackPop(Stack* stack)
{
    if(stackCount(*stack) == 0)
    {
        printf("\nERROR: stack is empty!");
    }

    uint8_t popped = *stack->head;
    stack->head = stack->head - 1;

    return popped;
}

