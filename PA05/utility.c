#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "pa05.h"


Stack * Push(Stack, HuffNode);
Stack * Pop(Stack, HuffNode);
int Stack_count(Stack);
HuffNode H_create(int);
HuffNode create_tree(HuffNode, HuffNode);
HuffNode destroy(HuffNode);
HuffNode destroy_tree(HuffNode);
HuffNode load_head(HuffNode, HuffNode);
HuffNode load_bithead(HuffNode, HuffNode);

Stack * Push(Stack * stack, HuffNode * node)
{
  Stack *thing = malloc(sizeof(Stack)); //allocates memory for stack
  stack -> node = node; //initializes next node
  stack -> next = stack;//initializes stack
  return thing;
}

Stack * Pop(Stack * stack, HuffNode *node)
{
  if(stack != NULL)
    {
      Stack *next = stack->next:
      free(stack);
      return next;
    }
}

int stack_count(Stack *stack)
{
  if(stack != NULL)
    {
      return 1 + stack_count(stack);
    }
}

HuffNode H_create(int value)//creates huffman node
{
  Huffnode *node = malloc(sizeof(HuffNode));
  node -> value = value;
  node -> left  = NULL;
  node -> right = NULL;
  printf("%d\n", node->value);
  return node;
}

HuffNode create_node(HuffNode *left, Huffnode *right)//creates huffman tree
{
  HuffNode *node = H_create(0);
  node -> left = left;
  node -> right = right;
  return node;
}

//read in one bit, convert to 1 or 0, read for 8 more bits, read in 1 bit, read in 8 more bits...
