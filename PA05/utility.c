#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"

void Huff_postOrderPrint(HuffNode *tree, FILE * fptr_out)
{
    // Base case: empty subtree
    if (tree == NULL) {
		return;
    }

    // Recursive case: post-order traversal

    // Visit left
    fprintf(fptr_out, "Left\n");
    Huff_postOrderPrint(tree->left, fptr_out);
    fprintf(fptr_out, "Back\n");
    // Visit right
    fprintf(fptr_out, "Right\n");
    Huff_postOrderPrint(tree->right, fptr_out);
    fprintf(fptr_out, "Back\n");
    // Visit node itself (only if leaf)
    if (tree->left == NULL && tree->right == NULL) {
      fprintf(fptr_out, "Leaf: %c\n", tree->value);
    }
    

}


//Stack Push(Stack, HuffNode);
//Stack Pop(Stack, HuffNode);
//int Stack_count(Stack);

/*HuffNode * H_create(char);
Stack * create_node(HuffNode *, Stack *);
Stack * Pop(Stack *);
void destroy_tree(HuffNode *);
//HuffNode * read_header(FILE*);
//char get_bits(FILE*, int);
Stack * Push(Stack *, HuffNode *);
HuffNode * create_chartree(FILE *);*/

/*int stack_count(Stack *stack)
{
  if(stack != NULL)
    {
      return 1 + stack_count(stack);
    }
    }*/

//creates huffman node
HuffNode * H_create(char value)
    {
      // HuffNode *node = NULL;
      HuffNode *node = malloc(sizeof(HuffNode));
  
      node -> value = value;
      node -> left  = NULL;
      node -> right = NULL;
      //printf("%d\n", node->value);
      return node;

      if(node == NULL)
	{
	  return NULL;
	}
    }

Stack * create_node(HuffNode * lptr, Stack * node)//creates huffman tree
{
  Stack *leaf_node = malloc(sizeof(Stack));
  leaf_node -> next = node;
  leaf_node -> node = lptr;

  while(leaf_node == NULL)
    {
      return NULL;
    }

  return leaf_node;
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

Stack * Push(Stack *head, HuffNode *node)
{
  Stack *curr = malloc(sizeof(Stack));
  curr -> next = head;
  curr -> node = node;

  return curr;
}

//read in one bit, convert to 1 or 0, read for 8 more bits, read in 1 bit, read in 8 more bits...
/*HuffNode *read_header(FILE *fptr)
{
  char ch = 0;
  fseek(fptr, 0, SEEK_SET);
  Stack *stack = NULL;
  int initial = 1;

  while((ch = get_bits(fptr, 1) == 1 || initial == 1 || stack->next != NULL))
    {
      initial = 0;

      if(ch == 1)
	{
	  ch = get_bits(fptr, 8);
	  stack = Push(NULL, stack);
	  stack->left = H_create(ch);
	}

      if(ch == 0)
	{
	  HuffNode *node = H_create(0);
	  node->right = stack->left;
	  stack = destroy_tree(stack);
	  node->left = stack->right;
	  stack = Pop(stack);
	  stack = Push(node, stack);
	}
    }

    Pop(stack);
    
    }*/

char get_bits(FILE *fptr, int bit_num, int * ct, unsigned char * value)
{
  unsigned char character;

  if(*ct == 0)
    {
      fread(value, 1, 1, fptr);
      *ct = 8;
    }
  if(*ct < bit_num)
    {
      character = *value;
      character = (character << (8 - *ct));
      fread(value, 1, 1, fptr);
      character = (character | (*value >> *ct));

      return character;
    }

  character = *value;
  if(bit_num == 1)
    {
      character = (character >> (*ct - bit_num))&0x01;
      *ct = (*ct - 1);
    }
  else
    {
      character = (character >> (*ct - bit_num));
      *ct = 0;
    }

  return character;

  }

Stack * Pop(Stack *node)
{
  Stack * p = node->next;
  free(node);
  return p;
}

HuffNode * create_chartree(FILE * fptr)
{
  int flag = 0;

  Stack * top = NULL;
  char ch;
  char chardata = 0;

  HuffNode *head = NULL;
  HuffNode *leftc;
  HuffNode *temp;

  while(flag == 0)
    {
      ch = fgetc(fptr);

      if(ch == '1')
	{
	  chardata = fgetc(fptr);
	  top = Push(top, H_create(chardata));
       	}
      else
        {
	  head = top -> node;
	  top = Pop(top);

	  if(top == NULL)
	    {
	      flag = 1;
	    }
	  else
	    {
	      leftc = top -> node;

	      temp = H_create(0);
	      temp -> right = head;
	      temp -> left = leftc;

	      top = Pop(top);
	      top = Push(top, temp);
	    }

	}
    }

      return head;

    }

 HuffNode * create_bittree(FILE * fptr)
{
  int flag = 0;

  Stack * top = NULL;
  char ch;
  char chardata = 0;
  unsigned char build;
  HuffNode *head = NULL;
  HuffNode *leftc;
  HuffNode *temp;
  int ct = 0;

  while(flag == 0)
    {
      ch = get_bits(fptr, 1, &ct, &build);

      if(ch == 1)
	{
	  chardata = get_bits(fptr, 8, &ct, &build);
	  top = Push(top, H_create(chardata));
	}

      else
	{
	  head = top -> node;
	  top = Pop(top);

	  if(top == NULL)
	    {
	      flag = 1;
	    }
	  else
	    {
	      leftc = top -> node;

	      temp = H_create(0);
	      temp -> right = head;
	      temp -> left = leftc;

	      top = Pop(top);
	      top = Push(top, temp);
	    }

	}
    }

      return head;

}

         
