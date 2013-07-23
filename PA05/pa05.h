#ifndef PA05_H
#define PA05_H

typedef struct huffnode {
  int value;
  struct huffnode *left;
  struct huffnode *right;
} HuffNode;

typedef struct stack {
  struct stack * next;
  HuffNode * node;
} Stack;

HuffNode * H_create(char);
Stack * create_node(HuffNode *, Stack *);
Stack * Pop(Stack *);
void destroy_tree(HuffNode *);
HuffNode * create_bittree(FILE *);
char get_bits(FILE*, int, int *, unsigned char *);
Stack * Push(Stack *, HuffNode *);
HuffNode * create_chartree(FILE *);
void Huff_postOrderPrint(HuffNode *, FILE *);

#endif
