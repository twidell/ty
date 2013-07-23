#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "pa05.h"


Stack Push(Stack, HuffNode);
Stack Pop(Stack, HuffNode);
int Stack_count(Stack);
HuffNode H_create(int);
HuffNode create_node(HuffNode, HuffNode);
HuffNode destroy(HuffNode);
HuffNode destroy_tree(HuffNode);
HuffNode read_header(FILE*);
char load_bits(FILE*, int);

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

HuffNode destroy(HuffNode *tree)
{
  if(tree != NULL)
    {
      free(tree);
    }
}

HuffNode destroy_tree(HuffNode *tree)
{
  if(tree != NULL)
    {
      destroy_tree(tree->left);
      destroy_tree(tree->right);
      free(tree);
    }
}


//read in one bit, convert to 1 or 0, read for 8 more bits, read in 1 bit, read in 8 more bits...
HuffNode *read_header(FILE *fptr)
{
  char ch = 0;
  fseek(fptr, 0, SEEK_SET);
  Stack *stack = NULL;
  int initial = 1;

  while((ch = load_bits(fptr, 1) != 0 || stack->next != NULL)
    {
      intial = 0;

      if(ch ==1)
	{
	  ch = load_bits(fptr, 8);
	  stack = create_node(NULL, stack);
	  stack->left = H_create(ch);
	}

      if(ch == 0)
	{
	  HuffNode *base = H_create(0);
	  base->right = stack->left;
	  stack = destroy_tree(stack);
	  base->left = stack->right;
	  stack = destory_tree(stack);
	  stack = create_node(base, stack);
	}
    }
    Stack * temp = stack;
    free(stack);
    return temp -> left;

    
    }
}


 

char load_bits(FILE *fptr, int number)
{
  static unsigned char ch;
  static int ct;//ct is the amount of bits left over from reading the file
  unsigned char character;

  if(ct == 0)
    {
      fread(&ch, 1, 1, fptr);
      ct = 8;
    }
  if(ct < number)
    {
      character = ch;
      character = (character << (8 - ct));
      fread(&ch, 1, 1, fptr);
      charachter = (character | (ch >> ct));

      return character;
    }

  character = ch;
  if(number == 1)
    {
      character = (character >> (ct - number)) & 0x01;
      ct--;
    }
  else
    {
      character = (character >> (ct - number));
      ct = 0;
    }

  return character;

}




     
