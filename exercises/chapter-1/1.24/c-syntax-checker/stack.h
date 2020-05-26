#include <inttypes.h>

#ifndef STACK_INCLUDED
#define STACK_INCLUDED

void stackInit(uint32_t total, uint8_t** base, uint8_t** head);
uint32_t stackCount(uint8_t* base, uint8_t* head);
uint8_t stackPush(uint8_t* base, uint8_t** head, uint8_t element, uint32_t size);
uint8_t stackPop(uint8_t* base, uint8_t** head);

#endif // STACK_INCLUDED
