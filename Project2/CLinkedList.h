/*!               
 *  \mainpage   🔴 🟠 🟡 Cͨoͦuͧrͬs͛eͤ:        CͨS͛Cͨ237🟢 🔵 🟣                                                 
 *  \section Project  Project 2 ‼️
 *  Welcome to my web area! Here you will find descriptions for two files:
 *  CLinkedList.h and testLL.cpp. One is a header file containing three class
 *  definitions: one for a Node object, another for a CLinkedList (a circular linked list),
 *  and finally, a CListItr object (an iterator for the linked list). As one can see, not 
 *  one of these objects can exist without the other- the nodes make up the list, and the iterator
 *  exists to navigate through the list. The other included file is a cpp file which 
 *  essentially serves its purpose as a test driver through giving the user the ability 
 *  to manipulate their own circular linked list through a menu of different manipulation
 *  options. WARNING: certain lines of code may not be working 100%, read function details within the header file
 *  (CLinkedList.h) for more information. Eve Collier is not to be held liable for any emotional distress this may cause.
 */


/*!       \file CLinkedList.h
*         \brief a header file containing three different class definitions as well as their implementations.
*/
/*******************************************************************/
/*    Author:        Eve Collier                                   */
/*    Course:        CSC237                                        */
/*    Date:          3/10/23 					   */	
/*    Filename:      CLinkedList.h                                 */
/*    Description:   CLinkedList.h is a header file containing     */
/*                   three class definitions our CLinkedList object*/
/*                   			                           */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*******************************************************************/

#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H
#include <assert.h>
#include <iostream>


using namespace std;


// Need to prototype template classes:
template <typename eltType> class Node;
template <typename eltType> class CLinkedList;
template <typename eltType> class CListItr;


/*!
 *    \class Node
 *    \quick definition of a node for the circular linked list
 *
 *    The Node class defines a node that holds information of eltType 
 *    as well as a pointer to the next node in the list. 
 */

/*****************************************************************/
/*                        Node CLASS				 */
/*****************************************************************/
template <typename eltType> class Node
{	private:
                /*!
		 * Constructor
		 * - Requires: info (number) to store in node, pointer to next node
		 * - Values default to eltType, pointer defaults to NULL
                 **************************************************************************/
                Node(eltType info, Node* link = NULL ) :
                                               data(info), next(link)
                {};
                /*!
                 *    The data (number) being stored in the actual node
                 */
                eltType data;

                /*!
                 * A pointer to the next node in the list
                 */
                Node *next;

        /*!
         *  our Node class is to be friends with the CLinkedList class.
         */ 
        friend class CLinkedList<eltType>;

        /*!
         *  our Node class is to be friends with the CListItr class.
         */
        friend class CListItr<eltType>;
};


/*!
 *    \class CLinkedList
 *    \quick definition of a circular linked list.
 *
 *    The CLinkedList class creates a circular linked list object
 *    and provides multiple very useful helper functions to 
 *    manipulate said list.
 */

/*****************************************************************/
/*                        CLinkedList CLASS   	                 */
/*****************************************************************/
template <typename eltType> class CLinkedList{
  public:  
    /*!
     *  Constructor
     * - defaults the last node in the Clist to NULL
     */
    CLinkedList();

    /*!
     *  Copy constructor
     * - copies another existing Clist.
     * - WARNING: this function may not work in the way one would intend it to. That is because
     *   the private copy() function throws seg faults when invoked, and this function just so 
     *   happens to use that function.
     */
    CLinkedList(CLinkedList&);
    
    /*!
     * Destructor
     * - destructs (destroys)  an already constructed Clist object.
     * - WARNING: this function may not work in the way one would intend it to. That is because
     *   the private destroy() function throws seg faults when invoked, and this function just so
     *   happens to use that function.
     */
    ~CLinkedList();

    /*!
     * Assignment (=) operator overload
     * - assigns one CList object to the other.
     * - WARNING: this function may not work in the way one would intend it to. That is because
     *   the private copy() function throws seg faults when invoked, and this function just so
     *   happens to use that function.
     */
    CLinkedList& operator=(const CLinkedList&);
 
    /*! 
     * Insert
     * - adds a specified item (of eltType) into the Clist
     */
    void insert(eltType);

    /*!
     * Remove
     * - removes a specified item (of eltType) from the Clist
     */
    void remove(eltType); 

    /*!
     * Reverse
     * - reverses the order of the elements in the Clist
     */
    void reverse();

  private:
    /*!
     * a pointer to the last node in the Clist
     */
    Node<eltType>* last;

    /*!
     * Copy
     * - a helper function to assist w/ copy constructor and assignment operator through the performance of a deep copy
     * - WARNING: there may be occurances of seg faults when invoked.
     */ 
    void copy(const CLinkedList<eltType>&);
  
    /*!
     * Destroy
     * - recursively destroys all nodes in a Clist
     * - WARNING: there may be occurances of seg faults when invoked.
     */
    void destroy(Node<eltType> *);
   
  /*!
   *  our CLinkedList class is to be friends with the Node class.
   */ 
  friend class Node<eltType>;
  /*!
   *  our CLinkedList class is to be friends with the CListItr class.                                    
   */
  friend class CListItr<eltType>;
};


/*!
 *    \class CListItr 
 *    \quick definition of an iterator for the circular linked list.
 *
 *    The CLinkedItr class creates an iterator object to navigate through
 *    the Clist and also provides various useful helper functions that
 *    makes gathering information about the Clist a lot simpler.
 */

/*****************************************************************/
/*                        CListIterator CLASS                    */
/*****************************************************************/
template <typename eltType> class CListItr{
  public:
    /*!
     *  Constructor
     * - constructs an iterator object with a refrence to the list that it will be iterating
     */
    CListItr(const CLinkedList<eltType> &l);

    /*!
     *  Begin
     * - sets iterator to the beginning of the list
     */
    void begin();

    /*!
     *  isEmpty      
     * - returns a bool that indicates whether or not the list is empty
     */
    bool isEmpty();

    /*!
     *  isFirstNode
     * - returns a bool that indicates whether or not the present node is the first node of the list
     */
    bool isFirstNode();

    /*!
     *  isLastNode
     * - returns a bool that indicates whether or not the present node is the last node of the list
     */
     bool isLastNode();
    
    /*!
     *  Asterisk (*) operator overload 
     * - returns data from the node being pointed at (l-value)
     */
    eltType &operator*();

    /*!
     *  Asterisk (*) operator overload
     * - returns data from the node being pointed at (r-value)          
     */
     const eltType &operator*() const; 

    /*!
     *   Pre-increment (++) operator overload
     * - increments the pointer forwards in the list by one        
     */
    void operator++();

    /*!
     *   Post-increment (++) operator overload
     * - increments the	pointer	forwards in the	list by	one
     */
    //CLinkedList<eltType> operator++(int);
    void operator++(int);

  private:
    /*!
     * a refrence to the list that the iterator will iterate
     */
    const CLinkedList<eltType> &itr;

    /*!
     * a pointer to the current node the iterator is at
     */
    Node<eltType> *curr;


  /*!
   *  our CListItr class is to be friends with the Node class.
   */ 
  friend class Node<eltType>;

  /*!
   *  our CListItr class is to be friends with the CLinkedList class.
   */
  friend class CLinkedList<eltType>;
};

/*****************************************************************/
/*                  CLinkedList IMPLEMENTATIONS  	         */
/*****************************************************************/

/*!
 * Constructor
 * mutator
**************************************************************************/

/*****************************************************************/
  /*    Function name:   constructor                               */
  /*                                                               */
  /*    Description:     constructs a default CLinkedList object   */
  /*                                                               */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
template <typename eltType> CLinkedList<eltType>::CLinkedList() : last(NULL)
{}

/*****************************************************************/
  /*    Function name:   copy constructor                          */
  /*                                                               */
  /*    Description:     performs a deep copy of the CLinkedList   */
  /*                     object                                    */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      const refrence to the CLinkedList we are  */
  /*                     performing the deep copy on  - import     */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
template <typename eltType> CLinkedList<eltType>::CLinkedList(CLinkedList<eltType> &cl){
  last = NULL;
  copy(cl);
 
}

/*****************************************************************/
  /*    Function name:   destructor                                */
  /*                                                               */
  /*    Description:     frees all nodes in CLinkedList object     */
  /*                                                               */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
template <typename eltType> CLinkedList<eltType>::~CLinkedList(){
  destroy(last -> next);
  //delete(last);
}

/*****************************************************************/
  /*    Function name:   = (assignment operator overload)          */
  /*                                                               */
  /*    Description:     assigns one CLinkedList to the other and  */
  /*                     destroys the old one                      */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      const refrence to the CLinkedList we are  */
  /*                     performing the copy of  - import          */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    a pointer to the CLinkedList              */
  /*****************************************************************/
template <typename eltType> CLinkedList<eltType> &CLinkedList<eltType>::operator =(const CLinkedList<eltType> &cl){
  if (this != &cl){
    destroy(last);
    copy(cl);
  }
  return *this;
}

/*****************************************************************/
  /*    Function name:   insert()                                  */
  /*                                                               */
  /*    Description:     inserts eltType into CLinkedList in       */
  /*                     ASCENDING order                           */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
template <typename eltType> void CLinkedList<eltType>::insert(eltType newItem){

  // firstly we want to see if the list is empty. If it is, all we need to do is simply
  // insert the data
  if (last == NULL){
     //newItem -> next = newItem;
     Node<eltType>* nitem = new Node<eltType>(newItem, last);
     last = nitem;
     nitem -> next = nitem;
     cout << "insertion of " << newItem << " was successful." << endl;
  }
  
  else if ( last == last -> next){
    // meaning we only have one elt in the list
    if (newItem > last -> data){
      Node<eltType>* nitem = new Node<eltType>(newItem, last);
      last->next = nitem;
      last = nitem;
      cout << "insertion of " << newItem << " was successful." << endl;
    }
    else if (newItem < last -> data){
      Node<eltType>* nitem = new Node<eltType>(newItem, last);
      last -> next = nitem;
      cout << "insertion of " << newItem << " was successful." << endl;
    }
  }
  
  else if(newItem < last -> next -> data){
      Node<eltType>* nitem = new Node<eltType>(newItem, last->next);
      
      last -> next = nitem;
      cout << "insertion of " << newItem << " was successful." << endl;
  }


  // and finally, if tbe new item is larger than last, it must become
  // last
  else if (newItem > last -> data){
    Node<eltType>* nitem = new Node<eltType>(newItem, last->next); 
    last -> next = nitem;
    last = nitem;
    cout << "insertion of " << newItem << " was successful." << endl;
  }

  // Next we can check, if the new item is smaller than last, it must be
  // inserted  before it in ascending order compared to the other nodes
  else if (newItem < last-> data){
    Node<eltType>* p = last->next->next;
    Node<eltType>* trail = last->next;
    while (newItem > p->data){ //&& trail -> data < newItem){
      trail = p;  // this increments us thru the list
      p = p -> next;  // this increments us thru the list
    }
    Node<eltType>* nitem = new Node<eltType>(newItem, p);
    trail -> next = nitem;
    // newItem -> next = p;
    cout << "insertion of " << newItem << " was successful." << endl;
  }

}

/*****************************************************************/
  /*    Function name:   remove()                                  */
  /*                                                               */
  /*    Description:     removes a specific elt from the           */
  /*                     CLinkedList object                        */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
template <typename eltType> void CLinkedList<eltType>::remove(eltType oldItem){
  
  if (last == NULL){
    // the list is empty
    cout << "There is nothing to remove, as the list is currently empty." << endl;
    return;
  }

  bool flag = false;  // this'll help us later


  if ( last == last -> next && last->data == oldItem){
     // meaning we only have one elt in the list
     delete last;
     last = NULL;
     cout << "removed only node in list." << endl;
     flag = true;

     return;
  }

  else if (last -> data == oldItem){
    // the user is trying to delete the last item. Meaning last must be updated
    // to the node before it
    Node<eltType> *ptr = last -> next;

    while (ptr -> next != last){
      ptr  = ptr -> next;
    }

    ptr -> next = last -> next;
    delete last;

    last = ptr; //last -> next = last; delete ptr;
    cout << oldItem << " removed from list." << endl;
    flag = true;
    return;
  }

  else if ( last->next->data == oldItem){
    // the user is trying to delete the first item.
    Node<eltType> *ptr = last -> next;
    Node<eltType> *temp = ptr -> next -> next;
    delete ptr -> next; ptr -> next = temp;
    cout << oldItem << " removed from list." << endl;
    flag = true;

   // while (ptr -> next -> next != last){
   //   ptr = ptr ->next;
   // } 
   // last -> next = ptr -> next; last -> next -> next = last -> next; delete ptr;

   // cout << oldItem << " removed from list." << endl;
   // flag = true;
    return;
  }

//  else if ( last == last -> next && last->data == oldItem){
//     // meaning we only have one elt in the list
//     delete last;
//     last = NULL;
//     cout << "removed only node in list." << endl;
//     flag = true;
  
//     return; 
//  }

//  else if (last -> data == oldItem){
    // the user is trying to delete the last item. Meaning last must be updated
    // to the node before it
//    Node<eltType> *ptr = last -> next;

//    while (ptr -> next -> next != last){
//      ptr  = ptr -> next;
//    }

//    last = ptr -> next; last -> next = last; delete ptr;
    
//    cout << oldItem << " removed from list." << endl;
//    flag = true;
//    return; 
//  }
  
  else{
    // at this point we can go through the entire list and search for oldItem. If its found,
    // we'll delete it. If nothing is found, we will shoot the user an error message.
    Node<eltType> *ptr = last -> next;

    while (ptr -> next != last -> next){
      if (oldItem == ptr -> next -> data){
        Node<eltType> *temp = ptr -> next -> next;
        delete ptr -> next; ptr -> next = temp;
        cout << oldItem << " removed from list." << endl;
        flag = true;
      }
      ptr = ptr -> next;
    }
    // if we've gotten to this point and the flag is false
    // we know the item wasn't in the list
    if (flag == false){
      cout << oldItem << " is not in the list, and thus, cannot be removed from it. That's tough, buddy." << endl;  
    }
     return; 
  }

}

/*****************************************************************/
  /*    Function name:   reverse()                                 */
  /*                                                               */
  /*    Description:     reverses the order of items in our        */
  /*                     CLinkedList object                        */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/

template <typename eltType> void CLinkedList<eltType>::reverse(){
  Node<eltType> *ptr = last -> next;
  Node<eltType>*backwards = NULL;
  Node<eltType> *temp = NULL;

  while (ptr != NULL){
    temp = ptr -> next;       // placeholder for next val 
    ptr -> next = backwards;  // current pointer points to node behind it
    backwards = ptr;          // move backwards forward one
    ptr = temp;               // move ptr forward one
  }
  last = backwards;

}

/*****************************************************************/
  /*    Function name:   copy()                                    */
  /*                                                               */
  /*    Description:     private helper function that performs     */
  /*                     a deep copy of each node from l           */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 l - the node to be copied, imported       */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    Node - each copied node                   */
  /*****************************************************************/
template <typename eltType> void CLinkedList<eltType>::copy(const CLinkedList<eltType>& list){

CListItr<eltType> clt(list);

  if (clt.isEmpty() == false){

    for (clt.begin(); clt.isLastNode() == false; clt++){
      insert(*clt);
    }
    insert(*clt);
 }

}



/*****************************************************************/
  /*    Function name:   destroy()                                 */
  /*                                                               */
  /*    Description:     private helper function that frees        */
  /*                     nodes in the circular linked list         */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/

template <typename eltType> void CLinkedList<eltType>::destroy(Node<eltType> *l){

  if (l == NULL){
    return;
  }

  if (l != last){
    Node<eltType> *doomed = l;
    l = l -> next;
 //   delete doomed;
    destroy(l);
    delete doomed;
  }


  if (l == last){
    Node<eltType> *doomed = l;
    delete doomed;
  }
 
}

/*****************************************************************/
/*                   CListIterator IMPLEMENTATIONS      	 */
/*****************************************************************/

/*****************************************************************/
  /*    Function name:   constructor                               */
  /*                                                               */
  /*    Description:     constructs a default CLinkedList iterator */
  /*                                                               */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 const refrence to our CLinkedList object  */
  /*                           - which is exported                 */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
template <typename eltType> CListItr<eltType>::CListItr(const CLinkedList<eltType> &l):
itr(l),curr(l.last){}


/*****************************************************************/
  /*    Function name:   begin()                                   */
  /*                                                               */
  /*    Description:     sets iterator to the first node of the    */
  /*                     CLinkedList (NULL if empty)               */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none				           */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
template <typename eltType> void CListItr<eltType>::begin(void){
  if (isEmpty() == true){
    curr = NULL;
  }
  else{
    curr = itr.last -> next;
  }

}


/*****************************************************************/
  /*    Function name:   isEmpty()                                 */
  /*                                                               */
  /*    Description:     checks the CLinkedList object to determine*/
  /*                     whether or not its empty, then returns a  */
  /*                     bool entailing that information           */
  /*                                                               */
  /*    Parameters:	 none					   */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     inspector                                 */
  /*                                                               */
  /*    Return Value:    bool                                      */
  /*****************************************************************/
template <typename eltType> bool CListItr<eltType>::isEmpty(){
  // if current is NULL, we know the list must be empty
  if (curr == NULL){
    return true;
  }
  else{
    return false;
  }
}


/*****************************************************************/
  /*    Function name:   isFirstNode()                             */
  /*                                                               */
  /*    Description:     checks if the current node is the first   */
  /*                     node in our CLinkedList. Returns true     */
  /*                     if it is and false otherwise              */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     inspector                                 */
  /*                                                               */
  /*    Return Value:    bool                                      */
  /*****************************************************************/
template <typename eltType> bool CListItr<eltType>::isFirstNode(void){
  // if the current is equal to the head...we know we're at the first node
  if (curr == itr.last){
    return true;
  }
  else{
    return false;
  }

}

/*****************************************************************/
  /*    Function name:   isLastNode()                              */
  /*                                                               */
  /*    Description:     checks if the current node is the last    */
  /*                     node in our CLinkedList. Returns true     */
  /*                     if it is and false otherwise              */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     inspector                                 */
  /*                                                               */
  /*    Return Value:    bool                                      */
  /*****************************************************************/
template <typename eltType> bool CListItr<eltType>::isLastNode(void){
  // this is actually cake. If current is NULL, then we're at the end. So...
  return curr == itr.last;
}

/*****************************************************************/
  /*    Function name:   * (operator overload for l-value)         */
  /*                                                               */
  /*    Description:     returns the data of the node being pointed*/
  /*                     at (FROM THE LEFT HAND SIDE)              */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none					   */
  /*                     			                   */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    eltType - the data from the node          */
  /*****************************************************************/
template <typename eltType> eltType &CListItr<eltType>::operator*(){
  return curr->data;
}

/*****************************************************************/
  /*    Function name:   * (operator overload for r-value)         */
  /*                                                               */
  /*    Description:     returns the data of the node being pointed*/
  /*                     at (FROM THE RIGHT HAND SIDE)             */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    eltType - the data from the node          */
  /*****************************************************************/
template <typename eltType> const eltType &CListItr<eltType>::operator*() const{
  return curr -> data;
}


/*****************************************************************/
  /*    Function name:   ++ (operator overload for pre-increment)  */
  /*                                                               */
  /*    Description:     pushes pointer to next node in list       */
  /*                     IF there is one	                   */
  /*                                                               */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    eltType - the data from the node          */
  /*****************************************************************/
template <typename eltType> void CListItr<eltType>::operator++(){
  if (!isLastNode()){
    curr = curr ->next;
  }
  //return *this;

}

/*****************************************************************/
  /*    Function name:   ++ (operator overload for post-increment) */
  /*                                                               */
  /*    Description:     pushes pointer to next node in list	   */
  /*                     IF there is one                           */
  /*                                                               */
  /*                                                               */
  /*    Parameters:      int   - import                            */
  /*                                                               */
  /*                                                               */
  /*    Member Type:     facilitator                               */
  /*                                                               */
  /*    Return Value:    none				           */
  /*****************************************************************/
template <typename eltType> void CListItr<eltType>::operator++(int){
  if(!isLastNode()){
    curr = curr -> next;
  }
  //return *this;

}


#endif

