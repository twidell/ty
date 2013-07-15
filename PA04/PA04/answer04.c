#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>

void crash()
{
  char* bad = NULL;
  *bad = 0;
}

// Don't forget to use the debugger
// gdb ./pa04
// r inputs/inputX outputs/outputX
// // wait for it to crash =0
// bt 
SparseNode *SparseNode_check(SparseNode* node)
{
#define CHECK(expr, msg) if(expr) { fprintf(stderr, "%s\n", msg); crash(); }

  if(node != NULL) {
    if(node->left)
      CHECK((node->left->value < node->value), "Left->value not < value");
    if(node->right)
      CHECK((node->right->value > node->value), "Right->value not > value");
    CHECK((node == node->right), "node->right refers back to node");
    CHECK((node == node->left), "node->left refers back to node");
    CHECK((node->value != 0), "node->value should never be zero");

    
  }

#undef CHECK

  return 0;
}

/* Create a single instance of a sparse array node with a specific
 * index and value. This is a constructor function that allocates
 * memory, copies the integer values, and sets the subtree pointers to
 * NULL.
 */

SparseNode *SparseNode_create(int index, int value)
{
  SparseNode * one_node = NULL;
  one_node = malloc(sizeof(SparseNode));
  one_node -> left = NULL;
  one_node -> right = NULL;
  one_node -> value = value;
  one_node -> index = index;

  // SparseNode node;
  // SparseNode * one_node;
  // (*one_node).left <==> one_node->left;
  // (&node)->left <==> node.left;

  return one_node;
}

/* Add a particular value into a sparse array on a particular index.
 * The sparse array uses the index as a key in a binary search tree.
 * It returns the new sparse array root
 * as its return value. If the index does not exist, create it. 
 * If the index exists, REPLACE the value to the new one. Use the index to
 * determine whether to go left or right in the tree (smaller index
 * values than the current one go left, larger ones go right).
 */

SparseNode * SparseArray_add ( SparseNode * array, int index, int value )
{
  if(value != 0 )
    {
      if(array == NULL)
	{
	  return SparseNode_create(index, value);
	}
      if(index < (array -> index))
	{
	  array->left = SparseArray_add(array -> left, index, value);
	}
      else if(index > (array -> index))
	{
	  array->right = SparseArray_add(array -> right, index, value);
	}
      else if(index == array -> index)
	{
	  array -> value = value;
	}
    }

  return array ;
}

 SparseNode * SparseArray_build(int * indicies, int * values, int length)
  {
    SparseNode * array = NULL;
    int ct;

    for(ct == 0; ct < length; ct++)
      {
	array = SparseArray_add(array, indicies[ct], values[ct]);
      }

    return array;
  }

/* Retrieve the node associated with a specific index in a sparse
 * array.  It returns the value
 * associated with the index. If the index does not exist in the
 * array, it returns 0. If the given index is smaller than the current
 * node, search left ; if it is larger, search right.
 */

void SparseArray_destroy (SparseNode * array)
{
  if(array == NULL)
    {
      return;
    }

  SparseArray_destroy(array -> left);
  SparseArray_destroy(array -> right);
  free(array);
}
  /* Retrieve the smallest index in the sparse array. 
 */

int SparseArray_getMin ( SparseNode * array )
{

  int compVal = 0;

  if(array == NULL)
    {
      printf("Warning! getMin precondition not met: array NULL!\n");
      return array -> index;
    }

  if(array -> left != NULL)//scrolls left through tree until min found
    {
      compVal = SparseArray_getMin(array -> left);
    }

  return compVal;
}

/* Retrieve the largest index in the sparse array. 
 */
int SparseArray_getMax ( SparseNode * array )
{

  int compVal = 0;

  if(array == NULL)
    {
      printf("Warning! getMax precondition not met: array NULL!\n");
      return array -> index;
    }

  if(array -> right != NULL)//scrolls right through tree until max found
    {
      compVal = SparseArray_getMin(array -> right);
    }  

  return compVal;
}

SparseNode * SparseArray_getNode(SparseNode * array, int index )
{

  if(index = (array -> index))
    {
      return array;
    }
  else if((array -> index) > index)
    {
      return SparseArray_getNode(array -> left, index);
    }
  else if((array -> index) < index)
    {
      return SparseArray_getNode(array -> right, index);
    }


  return NULL;
}

/* Remove a value associated with a particular index from the sparse
 * array. It returns the new
 * sparse array ( binary tree root ). HINT : You will need to isolate
 * several different cases here :
 * - If the array is empty ( NULL ), return NULL
 * - Go left or right if the current node index is different.

 * - If both subtrees are empty, you can just remove the node.

 * - If one subtree is empty, you can just remove the current and
 * replace it with the non - empty child.

 * - If both children exist, you must find the immediate successor of
 * the current node ( leftmost of right branch ), swap its values with
 * the current node ( BOTH index and value ), and then delete the
 * index in the right subtree.
*/
SparseNode * SparseArray_remove ( SparseNode * array, int index )
{

  if(array == NULL)
    {
      return NULL;
    }
  if(index < array -> index)
    {
     return SparseArray_remove(array -> left, index);
    }
  if(index > array -> index)
    {
     return SparseArray_remove(array -> right, index);
    }
  if(array -> left == NULL && array -> right == NULL)
    {
      free(array);
      return NULL;
    }
  if(array -> left == NULL && array -> right != NULL)
    {
      array -> index == array -> right;
      free(array -> index);
      return SparseArray_remove(array -> right, index);
    }
 if(array -> right == NULL && array -> left != NULL)
    {
      array -> index == array -> left;
      free(array -> index);
      return Sparsearray_remove(array -> left, index);
    }

 SparseNode * scsr = array -> right;

 while((scsr -> left) != NULL)
   {
     scsr = scsr -> left;
   }
 array -> index = scsr -> index;
 scsr -> index = index;

 array -> right = SparseArray_remove(array -> right, index);

  return array ;
}

/* The function makes a copy of the input sparse array 
 * and it returns a new copy. 
 */

SparseNode * SparseArray_copy(SparseNode * array)
{
  SparseNode *copy = NULL;

  copy = SparseArray_add(array, array -> index, array -> value);
  
  if(array -> left == NULL)
    {
      copy = SparseArray_copy(array -> left);
    }
  if(array -> right == NULL)
    {
      copy = SparseArray_copy(array -> right);
    }

  return copy;
}

/* Merge array_1 and array_2, and return the result array. 
 * This function WILL NOT CHANGE the contents in array_1 and array_2.
 * When merging two sparse array:
 * 1. The contents in array_1 and array_2 should not be changed. You should make
 *    a copy of array_1, and do merging in this copy.
 * 2. array_2 will be merged to array_1. This means you need to read nodes in 
 *    array_2 and insert them into array_1.
 * 3. You need to use POST-ORDER to traverse the array_2 tree. 
 * 4. Values of two nodes need to be added only when the indices are the same.
 * 5. A node with value of 0 should be removed.
 * 6. if array_2 has nodes with index different than any nodes in array_1, you
 *    should insert those nodes into array_1.
 * 
 */

SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2)
{

  SparseNode *mergeNode;
  SparseNode *getnode;

  int *arraycop;

  arraycop = SparseArray_copy(array_1);
 
  if(array_1 == NULL || array_2 == NULL)
    {
      printf("Incorrect arrays given!\n");
      return NULL;
    }
  if(array_2 -> index != arraycop)
    {
      arraycop = array_2 -> index;
    }
  if(array_2 -> index < arraycop)
    {




  return NULL;
}

SparseNode *SparseArray_mergehelp(SparseNode *array_1, SparseNode *array_2)
{
  

