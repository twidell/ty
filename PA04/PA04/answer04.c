#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Don't forget to use the debugger
// gdb ./pa04
// r inputs/inputX outputs/outputX
// // wait for it to crash =0
// bt 
SparseNode *SparseNode_check(SparseNode* node)
{
#define CHECK(expr, msg) if(expr) { fprintf(stderr, "%s\n", msg); assert(0); }

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
  if(array == NULL)
    {
      return SparseNode_create(index, value);
    }
  if(value < (array -> value))
    {
      array->left = SparseArray_add(array -> left, index, value);
    }
    else
      {
	array->right = SparseArray_add(array -> right, index, value);
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

  int compVal;

  if(array == NULL)
    {
      printf("Warning! getMin precondition not met: array NULL!\n");
      return;
    }

  if(array -> left != NULL)
    {
      compVal = SparseArray_getMin(array -> left);
    }

  if(compVal < array -> index)
    {
      array -> index = compVal; 
    }  

  return array -> index;
}

/* Retrieve the largest index in the sparse array. 
 */
int SparseArray_getMax ( SparseNode * array )
{

  int compVal;

  if(array == NULL)
    {
      printf("Warning! getMax precondition not met: array NULL!\n");
      return;
    }

  if(array -> right != NULL)
    {
      compVal = SparseArray_getMin(array -> right);
    }

  if(compVal > array -> index)
    {
      array -> index = compVal; 
    }

  

  return array -> index;
}

SparseNode * SparseArray_getNode(SparseNode * array, int index )
{

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
  return array ;
}

/* The function makes a copy of the input sparse array 
 * and it returns a new copy. 
 */

SparseNode * SparseArray_copy(SparseNode * array)
{
  return NULL;
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
  return NULL;
}

