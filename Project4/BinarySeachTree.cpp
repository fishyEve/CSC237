/*! \file BinarySearchTree.cpp
 *  \brief Binary Tree ADT implemented with TreeNode linked structures
 *  \class BinarySearchTree.cpp
 *  \brief Binary Tree ADT implemented with TreeNode linked structures
 *
 *
 */


#include <iostream>
#include <string>
#include <queue>
#include "BinarySearchTree.h"

using namespace std;

//! BinaryTree()
/*/
 */
template <typename treeEltType> BinaryTree<treeEltType>::BinaryTree(){
  root=NULL;
}

//! insertToTree()
/*!
// \brief Places Element into Tree Returns 1 if inserted, 0 if data already in tree
*/
template <typename treeEltType>
	  int BinaryTree<treeEltType>::insertToTree(const treeEltType &data)
{if (root==NULL) { // Empty Tree
  root=new TreeNode<treeEltType>(data);
  return(1);
 }
 // Search for spot to put data; We only stop when we get to the bottom (NULL)
 TreeNode<treeEltType> *t=root,*parent;
 while(t!=NULL) {
   if (t->info==data){ // data already in Tree
     t-> counter = t->counter+1;   // UPDATE COUNTER INCREMENT
     return(0);
   } 
   parent=t; // Set the trail pointer to the ancestor of where we're going
   if (data<t->info) 
     t=t->left;
   else 
     t=t->right;
 }
 // Found the spot; insert node.
 if (data<parent->info) parent->left=new TreeNode<treeEltType>(data);
 else parent->right=new TreeNode<treeEltType>(data);
 return(1);
}

//! treeSearch()
/*!
// \brief Searches for Element in Tree Assumes == is defined for treeEltType Returns Ptr to Elt if Found, NULL otherwise
 */
template <typename treeEltType>
	treeEltType *BinaryTree<treeEltType>::treeSearch(const treeEltType &key)
{TreeNode<treeEltType> *t=root;
 while (t && t->info != key)
   if (key < t->info) 
     t=t->left;
   else 
     t=t->right;
 if (t)
   return(&t->info);	
 return(NULL);
}

//! retrieveFromTree()
/*!
 */
// Retrieve Element from Tree (leaving Tree Intact)
// Precondition: Item is in Tree
template <typename treeEltType>
   treeEltType &BinaryTree<treeEltType>::retrieveFromTree(const treeEltType &key) 
{TreeNode<treeEltType> *t;
 for (t=root;t->info!=key;)
  if (key<t->info) t=t->left;
  else t=t->right;
 return(t->info);
}

//! deleteFromTree()
/*!
 */
// Remove an Element from the tree
// Precondition: Element is in the Tree; 
template <typename treeEltType>
      void BinaryTree<treeEltType>::deleteFromTree(const treeEltType &data)
{TreeNode<treeEltType> *nodeWithData,*nodeToDelete,*t=root,*trailT=NULL;
 // Find spot
 while (t->info!=data) {  // safe because of precondition
  trailT=t;
  if (data<t->info) t=t->left;
  else t=t->right;
 }
 nodeWithData=t;  // Hold onto the data Node for later deletion
 // Case 1: Leaf?
 if (!(nodeWithData->left) && !(nodeWithData->right)) {
  // No Subtrees, node is leaf...Wipe it
  // Is it the root?
  if (nodeWithData==root)
    root=NULL;
  else if (trailT->right==nodeWithData) // Parent's right child
    trailT->right=NULL;
  else 
    trailT->left=NULL;
  nodeToDelete=nodeWithData;    // free this at the end
 }
 else if (!(nodeWithData->left)) {  
  // If 1st condition false and this one's true, there's a right subtree
  if (!trailT) { // Node to delete is root and there is no left subtree
    nodeToDelete=root;
    root=root->right;
  }
  else { // Point parent's pointer to this node to this node's right child
    if (trailT->right==nodeWithData) 
      trailT->right=nodeWithData->right;
    else 
      trailT->left=nodeWithData->right;
    nodeToDelete=nodeWithData;
  }
 }
 else if (!(nodeWithData->right)) {  
   // If 1st 2 conditions false and this one's true, there's a left subtree
   if (!trailT) { // Node to delete is root and there is no left subtree
     nodeToDelete=root;
     root=root->left;
   }
   else {// Otherwise, move up the right subtree
     if (trailT->right==nodeWithData) 
        trailT->right=nodeWithData->left;
     else 
        trailT->left=nodeWithData->left;
     nodeToDelete=nodeWithData;
   }
 } 
 else { // If you make it here, node has two children
   // Go to rightmost node in left subtree; we know there's a right child...
  for (trailT=nodeWithData,t=nodeWithData->left;
                                        t->right!=NULL;trailT=t,t=t->right);
  // Want to copy data from node with 0 or 1 child to node with data to delete 
  // Place node data in NodeWithData
  nodeWithData->info=t->info;

  nodeWithData->counter = t->counter;    // CHANGED

   // Set the parent of source node to point at source node's left child 
   //   (We know it hasn't a right child. Also ok if no left child.)
  if (trailT==nodeWithData) 
    // Need to point parent correctly. 
    //   See if after the we went left there was no right child
    //   If there was no right child, this is rightmost node in left subtree
    trailT->left=t->left;
  else // we did go right; after going left, there was a right child
   // rightmost node has no r. child, so point its parent at its l. child 
   trailT->right=t->left;
  nodeToDelete=t;
 }
 delete nodeToDelete;
}


//! printInOrder()
/*!
 // \brief Need Helper to Recursively Print the Tree
 */
template <typename treeEltType>
     void BinaryTree<treeEltType>::printInorder(TreeNode<treeEltType> *t) const
//void printTheTree(TreeNode *T)
{if (t) {
  printInorder(t->left);
  if (t->counter > 1){        // IF there is an occurance thats more than once, we need to display
    cout << t->info << " (" << t->counter << ") " << endl;  // data w/ paranthesis
  }
  else{
    cout << t->info << endl;
  }
  printInorder(t->right);
  
 }

}
//! inorder()
/*!
// \brief Display Tree using InOrder Traversal
 */
template <typename treeEltType> void BinaryTree<treeEltType>::inorder() const
{printInorder(root);}

//! printPreorder
/*!
// \brief Need Helper to Recursively Print the Tree
 */
template <typename treeEltType>
   void BinaryTree<treeEltType>::printPreorder(TreeNode<treeEltType> *t) const
//void printTheTree(TreeNode *t)
{if (t) {
  cout << t->info << endl;
  printPreorder(t->left);
  printPreorder(t->right);
 }
}

//! preorder()
/*!
// \brief Display Tree using InOrder Traversal
 */
template <typename treeEltType> void BinaryTree<treeEltType>::preorder() const
{printInorder(root);}

//! printPostorder()
/*!
// \brief Need Helper to Recursively Print the Tree
 */
template <typename treeEltType>
  void BinaryTree<treeEltType>::printPostorder(TreeNode<treeEltType> *t) const
//void printTheTree(TreeNode *t)
{if (t) {
  printPostorder(t->left);
  printPostorder(t->right);
  cout << t->info << endl;
 }
}

//! postorder()
/*!
// \brief Display Tree using InOrder Traversal
 */
template <typename treeEltType> void BinaryTree<treeEltType>::postorder() const
{printInorder(root);}

//! treePrint()
// \brief calls helper function to print elts in tree
/*!
 */
template <typename treeEltType> void BinaryTree<treeEltType>::treePrint() const
{treePrintHelper(root);}

//! treePrintHelper()
/*!
// \brief A helper function to print the elts in the tree
 */

template <typename treeEltType> void BinaryTree<treeEltType>::
                        treePrintHelper(TreeNode<treeEltType> *root) const
{queue<TreeNode<treeEltType> *> Q;
 // A dummy node to mark end of level
 TreeNode<treeEltType> *dummy=new  TreeNode<treeEltType>(-1);
 if (root) {
    if (root -> counter > 1){	// IF the root is in more than once, its count must be displayed
          cout << root->info << " (" << root->counter << ") " << "  " << endl;  // data w/ paranthesis
    }
   else{
   cout << root->info << "   " << endl;
  }
   Q.push(root->left);
   Q.push(root->right);
   Q.push(dummy);
 }
 TreeNode<treeEltType> *t=root;
 while (!Q.empty()) {
  t=Q.front();
  Q.pop();
  if (t==dummy) {
   if (!Q.empty()) 
    Q.push(dummy);
   cout << endl;
  }
  else if (t) {
  if (t->counter > 1){        // IF there is an occurance thats more than once, we need to display
    cout << t->info << " (" << t->counter << ") " << "  " << endl;  // data w/ paranthesis
  }
   else{
   cout << t->info << "   ";
   }
   Q.push(t->left);
   Q.push(t->right);
  } 
 }
}

//! isCounterMoreThanOne()
/*!
// \brief UPDATED: returns a bool indicating if a counter has a value greater than one
 */
template <typename treeEltType> bool BinaryTree<treeEltType>::isCounterMoreThanOne(const treeEltType &data){
    TreeNode<treeEltType> *t;
     for (t=root;t->info!=data;){
       if (data<t->info) t=t->left;
       else t= t->right;
    }
    if (t->counter > 1){
      return true;
    }
    else{
      return false;
    }
   return false;
}

//! decrement()
/*!
// \brief Simply decrements a counter
 */
template <typename treeEltType> void BinaryTree<treeEltType>:: decrement(const treeEltType &data) const{
      TreeNode<treeEltType> *t = root;
      TreeNode<treeEltType> *trailT=NULL;
   
      while(t->info!=data){
        trailT=t;
        if (data<t->info)  t=t->left;
         else t=t->right;
      }

      t->counter = t->counter-1;
}


template class BinaryTree<int>;
/*! \file BinarySearchTree.cpp
 *  \brief Binary Tree ADT implemented with TreeNode linked structures
 *  \class BinarySearchTree.cpp
 *  \brief Binary Tree ADT implemented with TreeNode linked structures
 *
 *
 */


#include <iostream>
#include <string>
#include <queue>
#include "BinarySearchTree.h"

using namespace std;

//! BinaryTree()
/*/
 */
template <typename treeEltType> BinaryTree<treeEltType>::BinaryTree(){
  root=NULL;
}

//! insertToTree()
/*!
// \brief Places Element into Tree Returns 1 if inserted, 0 if data already in tree
*/
template <typename treeEltType>
	  int BinaryTree<treeEltType>::insertToTree(const treeEltType &data)
{if (root==NULL) { // Empty Tree
  root=new TreeNode<treeEltType>(data);
  return(1);
 }
 // Search for spot to put data; We only stop when we get to the bottom (NULL)
 TreeNode<treeEltType> *t=root,*parent;
 while(t!=NULL) {
   if (t->info==data){ // data already in Tree
     t-> counter = t->counter+1;   // UPDATE COUNTER INCREMENT
     return(0);
   } 
   parent=t; // Set the trail pointer to the ancestor of where we're going
   if (data<t->info) 
     t=t->left;
   else 
     t=t->right;
 }
 // Found the spot; insert node.
 if (data<parent->info) parent->left=new TreeNode<treeEltType>(data);
 else parent->right=new TreeNode<treeEltType>(data);
 return(1);
}

//! treeSearch()
/*!
// \brief Searches for Element in Tree Assumes == is defined for treeEltType Returns Ptr to Elt if Found, NULL otherwise
 */
template <typename treeEltType>
	treeEltType *BinaryTree<treeEltType>::treeSearch(const treeEltType &key)
{TreeNode<treeEltType> *t=root;
 while (t && t->info != key)
   if (key < t->info) 
     t=t->left;
   else 
     t=t->right;
 if (t)
   return(&t->info);	
 return(NULL);
}

//! retrieveFromTree()
/*!
 */
// Retrieve Element from Tree (leaving Tree Intact)
// Precondition: Item is in Tree
template <typename treeEltType>
   treeEltType &BinaryTree<treeEltType>::retrieveFromTree(const treeEltType &key) 
{TreeNode<treeEltType> *t;
 for (t=root;t->info!=key;)
  if (key<t->info) t=t->left;
  else t=t->right;
 return(t->info);
}

//! deleteFromTree()
/*!
 */
// Remove an Element from the tree
// Precondition: Element is in the Tree; 
template <typename treeEltType>
      void BinaryTree<treeEltType>::deleteFromTree(const treeEltType &data)
{TreeNode<treeEltType> *nodeWithData,*nodeToDelete,*t=root,*trailT=NULL;
 // Find spot
 while (t->info!=data) {  // safe because of precondition
  trailT=t;
  if (data<t->info) t=t->left;
  else t=t->right;
 }
 nodeWithData=t;  // Hold onto the data Node for later deletion
 // Case 1: Leaf?
 if (!(nodeWithData->left) && !(nodeWithData->right)) {
  // No Subtrees, node is leaf...Wipe it
  // Is it the root?
  if (nodeWithData==root)
    root=NULL;
  else if (trailT->right==nodeWithData) // Parent's right child
    trailT->right=NULL;
  else 
    trailT->left=NULL;
  nodeToDelete=nodeWithData;    // free this at the end
 }
 else if (!(nodeWithData->left)) {  
  // If 1st condition false and this one's true, there's a right subtree
  if (!trailT) { // Node to delete is root and there is no left subtree
    nodeToDelete=root;
    root=root->right;
  }
  else { // Point parent's pointer to this node to this node's right child
    if (trailT->right==nodeWithData) 
      trailT->right=nodeWithData->right;
    else 
      trailT->left=nodeWithData->right;
    nodeToDelete=nodeWithData;
  }
 }
 else if (!(nodeWithData->right)) {  
   // If 1st 2 conditions false and this one's true, there's a left subtree
   if (!trailT) { // Node to delete is root and there is no left subtree
     nodeToDelete=root;
     root=root->left;
   }
   else {// Otherwise, move up the right subtree
     if (trailT->right==nodeWithData) 
        trailT->right=nodeWithData->left;
     else 
        trailT->left=nodeWithData->left;
     nodeToDelete=nodeWithData;
   }
 } 
 else { // If you make it here, node has two children
   // Go to rightmost node in left subtree; we know there's a right child...
  for (trailT=nodeWithData,t=nodeWithData->left;
                                        t->right!=NULL;trailT=t,t=t->right);
  // Want to copy data from node with 0 or 1 child to node with data to delete 
  // Place node data in NodeWithData
  nodeWithData->info=t->info;

  nodeWithData->counter = t->counter;    // CHANGED

   // Set the parent of source node to point at source node's left child 
   //   (We know it hasn't a right child. Also ok if no left child.)
  if (trailT==nodeWithData) 
    // Need to point parent correctly. 
    //   See if after the we went left there was no right child
    //   If there was no right child, this is rightmost node in left subtree
    trailT->left=t->left;
  else // we did go right; after going left, there was a right child
   // rightmost node has no r. child, so point its parent at its l. child 
   trailT->right=t->left;
  nodeToDelete=t;
 }
 delete nodeToDelete;
}


//! printInOrder()
/*!
 // \brief Need Helper to Recursively Print the Tree
 */
template <typename treeEltType>
     void BinaryTree<treeEltType>::printInorder(TreeNode<treeEltType> *t) const
//void printTheTree(TreeNode *T)
{if (t) {
  printInorder(t->left);
  if (t->counter > 1){        // IF there is an occurance thats more than once, we need to display
    cout << t->info << " (" << t->counter << ") " << endl;  // data w/ paranthesis
  }
  else{
    cout << t->info << endl;
  }
  printInorder(t->right);
  
 }

}
//! inorder()
/*!
// \brief Display Tree using InOrder Traversal
 */
template <typename treeEltType> void BinaryTree<treeEltType>::inorder() const
{printInorder(root);}

//! printPreorder
/*!
// \brief Need Helper to Recursively Print the Tree
 */
template <typename treeEltType>
   void BinaryTree<treeEltType>::printPreorder(TreeNode<treeEltType> *t) const
//void printTheTree(TreeNode *t)
{if (t) {
  cout << t->info << endl;
  printPreorder(t->left);
  printPreorder(t->right);
 }
}

//! preorder()
/*!
// \brief Display Tree using InOrder Traversal
 */
template <typename treeEltType> void BinaryTree<treeEltType>::preorder() const
{printInorder(root);}

//! printPostorder()
/*!
// \brief Need Helper to Recursively Print the Tree
 */
template <typename treeEltType>
  void BinaryTree<treeEltType>::printPostorder(TreeNode<treeEltType> *t) const
//void printTheTree(TreeNode *t)
{if (t) {
  printPostorder(t->left);
  printPostorder(t->right);
  cout << t->info << endl;
 }
}

//! postorder()
/*!
// \brief Display Tree using InOrder Traversal
 */
template <typename treeEltType> void BinaryTree<treeEltType>::postorder() const
{printInorder(root);}

//! treePrint()
// \brief calls helper function to print elts in tree
/*!
 */
template <typename treeEltType> void BinaryTree<treeEltType>::treePrint() const
{treePrintHelper(root);}

//! treePrintHelper()
/*!
// \brief A helper function to print the elts in the tree
 */

template <typename treeEltType> void BinaryTree<treeEltType>::
                        treePrintHelper(TreeNode<treeEltType> *root) const
{queue<TreeNode<treeEltType> *> Q;
 // A dummy node to mark end of level
 TreeNode<treeEltType> *dummy=new  TreeNode<treeEltType>(-1);
 if (root) {
    if (root -> counter > 1){	// IF the root is in more than once, its count must be displayed
          cout << root->info << " (" << root->counter << ") " << "  " << endl;  // data w/ paranthesis
    }
   else{
   cout << root->info << "   " << endl;
  }
   Q.push(root->left);
   Q.push(root->right);
   Q.push(dummy);
 }
 TreeNode<treeEltType> *t=root;
 while (!Q.empty()) {
  t=Q.front();
  Q.pop();
  if (t==dummy) {
   if (!Q.empty()) 
    Q.push(dummy);
   cout << endl;
  }
  else if (t) {
  if (t->counter > 1){        // IF there is an occurance thats more than once, we need to display
    cout << t->info << " (" << t->counter << ") " << "  " << endl;  // data w/ paranthesis
  }
   else{
   cout << t->info << "   ";
   }
   Q.push(t->left);
   Q.push(t->right);
  } 
 }
}

//! isCounterMoreThanOne()
/*!
// \brief UPDATED: returns a bool indicating if a counter has a value greater than one
 */
template <typename treeEltType> bool BinaryTree<treeEltType>::isCounterMoreThanOne(const treeEltType &data){
    TreeNode<treeEltType> *t;
     for (t=root;t->info!=data;){
       if (data<t->info) t=t->left;
       else t= t->right;
    }
    if (t->counter > 1){
      return true;
    }
    else{
      return false;
    }
   return false;
}

//! decrement()
/*!
// \brief Simply decrements a counter
 */
template <typename treeEltType> void BinaryTree<treeEltType>:: decrement(const treeEltType &data) const{
      TreeNode<treeEltType> *t = root;
      TreeNode<treeEltType> *trailT=NULL;
   
      while(t->info!=data){
        trailT=t;
        if (data<t->info)  t=t->left;
         else t=t->right;
      }

      t->counter = t->counter-1;
}


template class BinaryTree<int>;
