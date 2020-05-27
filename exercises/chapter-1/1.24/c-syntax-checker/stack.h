#include <inttypes.h>

#ifndef STACK_INCLUDED
#define STACK_INCLUDED


typedef struct {
   uint32_t size;
   uint8_t* base;
   uint8_t* head;
} Stack;

Stack stackInit(uint32_t size);
uint32_t stackCount(Stack stack);
void stackPush(Stack* stack, uint8_t elem);
uint8_t stackPop(Stack* stack);


#endif // STACK_INCLUDED
