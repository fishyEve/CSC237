#ifndef TREE_H
#define TREE_H

/*!     \file BinarySearchTree.h
 *    \brief Binary Tree ADT defined using Linked Structures
 *    \class BinarySearchTree
 *    \brief Binary Tree of abstract data type defined using linked structures
 */


 template <typename treeEltType> class BinaryTree;

  /*!  \class TreeNode
   *    \brief Definition for a TreeNode object
   */

 template <typename eltType> class TreeNode {
 private:
  int counter = 1;     // to count the num of occurances of info
  eltType info;
  TreeNode<eltType> *left,*right;  
  TreeNode(const eltType &data,
                        TreeNode<eltType> *lChild=NULL,TreeNode *rChild=NULL)
  {info=data;   left=lChild; right=rChild;  }
  
  friend class BinaryTree<eltType>;
 };

  /*!  \class BinaryTree
   *   \brief Definition for a BinaryTree object
   */

template <typename treeEltType> class BinaryTree {

public:

 /*! Constructor
  *  constructs a default binary tree
  */
  BinaryTree();

 /*!  Places Element into Tree  Returns 1 if inserted, 0 if Data already in tree
  */
 int insertToTree(const treeEltType &data);

 /*!  Searchs for Element in Tree Assumes == is defined for treeEltType Returns pointer to data, or NULL, according to success
  */
 treeEltType *treeSearch(const treeEltType &data);

 /*!  Retrieves Element from Tree (leaving Tree Intact) Precondition: Item is in Tree
  */
 treeEltType &retrieveFromTree(const treeEltType &data);

 /*!  Removes an Element from the tree Pre: Element is in the Tree
  */ 
 void deleteFromTree(const treeEltType &data);

 /*! - Displays Tree using InOrder Traversal
  */
 void inorder() const;

 /*! - Displays Tree using PreOrder Traversal
  */
 void preorder() const;

 /*! - Displays Tree using PostOrder Traversal
  */
 void postorder() const;
 
 /*! - Breadth first print
  */
 void treePrint() const;

/*! - UPDATE:  returns a bool indicating whether or not there is more or less than one occurance
 */
bool isCounterMoreThanOne(const treeEltType &data);

/*! - UPDATE: decrements counter
 */
void decrement(const treeEltType &dat) const;
 
private:
 /*! root
  *    - placeholder for the root of the binary tree
  */
 TreeNode<treeEltType> *root;

 /*! - Displays Tree using InOrder Traversal
  */
 void printInorder(TreeNode<treeEltType> *) const;

 /*! - Displays Tree using PreOrder Traversal
  */
 void printPreorder(TreeNode<treeEltType> *) const;

 /*! - Displays Tree using PostOrder Traversal
  */
 void printPostorder(TreeNode<treeEltType> *) const;
 
 /*! - Helper function for printing tree
  */ 
void treePrintHelper(TreeNode<treeEltType> *) const;

};

#endif
