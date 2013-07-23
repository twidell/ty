#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "tree.h"
#include "pa05.h"


//Stack Push(Stack, HuffNode);
//Stack Pop(Stack, HuffNode);
//int Stack_count(Stack);

HuffNode * H_create(int);
Stack * create_node(HuffNode *, Stack *);
Stack * Pop(Stack *);
void destroy_tree(HuffNode *);
HuffNode * read_header(FILE*);
char get_bits(FILE*, int);
void Push(Stack *);
Huffnode create_chartree(File *);

int stack_count(Stack *stack)
{
  if(stack != NULL)
    {
      return 1 + stack_count(stack);
    }
    }*/

HuffNode *H_create(int value)//creates huffman node
{
  HuffNode *node = malloc(sizeof(HuffNode));
  if(node != NULL)
    {
      node -> value = value;
      node -> left  = NULL;
      node -> right = NULL;
      //printf("%d\n", node->value);
      return node;
    }
}

Stack * create_node(HuffNode * left, Stack * node)//creates huffman tree
{
  Stack *node = malloc(sizeof(Stack));
  node -> left = left;
  node -> right = right;

  while(node == NULL)
    {
      return NULL;
    }

  return node;
}

void destroy_tree(HuffNode * tree)
{
  if(tree != NULL)
    {
      destroy_tree(tree->left);
      destroy_tree(tree->right);
      free(tree);
    }
}

void Push(Stack *leaf)
{
  Stack *curr = leaf->next;
  Stack *prev = curr->next;
  free(curr);
  curr = prev;
  leaf->next = NULL;
}

//read in one bit, convert to 1 or 0, read for 8 more bits, read in 1 bit, read in 8 more bits...
HuffNode *read_header(FILE *fptr)
{
  char ch = 0;
  fseek(fptr, 0, SEEK_SET);
  Stack *stack = NULL;
  int initial = 1;

  while((ch = get_bits(fptr, 1) != 0 || stack->next != NULL))
    {
      initial = 0;

      if(ch == 1)
	{
	  ch = get_bits(fptr, 8);
	  stack = create_node(NULL, stack);
	  stack->left = H_create(ch);
	}

      if(ch == 0)
	{
	  HuffNode *base = H_create(0);
	  base->right = stack->left;
	  stack = destroy_tree(stack);
	  base->left = stack->right;
	  stack = node_destroy(stack);
	  stack = create_node(base, stack);
	}
    }

  Stack * temp = stack;
  free(stack);
  return temp -> left;
    
}

char get_bits(FILE *fptr, int bit_num)
{
  static unsigned char ch;
  static int ct;//ct is the amount of bits left over from reading the file
  unsigned char character;

  if(ct == 0)
    {
      fread(&ch, 1, 1, fptr);
      ct = 8;
    }
  if(ct < bit_num)
    {
      character = ch;
      character = (character << (8 - ct));
      fread(&ch, 1, 1, fptr);
      character = (character | (ch >> ct));

      return character;
    }

  character = ch;
  if(bit_num == 1)
    {
      character = (character >> (ct - bit_num)) & 0x01;
      ct--;
    }
  else
    {
      character = (character >> (ct - bit_num));
      ct = 0;
    }

  return character;

}

Stack Pop(Stack *node)
{
  Stack *p = node->next;

  free(node);
  return p;
}

HuffNode * create_chartree(File * fptr)
{
  int flag = 0;

  Stack * top = NULL;
  char ch;
  char chardata;

  HuffNode *rightc;
  Huffnode *leftc;
  HuffNode *temp;

  while(flag == 0)
    {
      ch = fgetc(fptr);

      top = Push(top, create_node(chardata));
    }

  if(ch == '0')
    {
      rightc = top -> node;
      top = Pop(top);

      if(top == NULL)
	{
	  flag = 1;
	}
      else
	{
	  leftc = top -> node;

	  temp = create_node(0);
	  temp -> right = rightc;
	  temp -> ledt = leftc;

	  top = Pop(top);
	  top = Push(top, temp);
	}

    }

  return rightc;

}

     
