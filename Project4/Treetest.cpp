/*!
 *  \mainpage off topic but look its you --> 🧍‍♂️
 *  \section Enough Enough of the sillies, here's what you're looking for ⬇️ 
 *  This doxygen holds the documentation for a total of 3 files: BinarySearchTree.h , BinarySearchTree.cpp , Treetest.cpp . 
 *  BinarySearchTree.h is a header file that contains the definition for two classes: TreeNode and BinaryTree. TreeNode is 
 *  the definition for a node object to be used in the tree. BinaryTree is the definition for the binary tree object that
 *  holds all of the tree nodes. BinarySearchTree.cpp is the application file of BinarySearchTree.h , holding all of the code
 *  for the multiple function definitions. Finally, Treetest.cpp is the application for the BinarySearchTree itself, operating
 *  through a user-driven menu with different options to manipulate the binary tree. These options include adding, removing, 
 *  printing, printing the tree hiearchy, and quitting.
 */

// File: TreeTest.cpp
// Driver for Binary Tree ADT

/*! \file Treetest.cpp
 *  \brief the application file for BinarySearchTree
 *  \class Treetest.cpp
 *  \brief the application file for BinarySearchTree
 */ 

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include <climits>
using namespace std;

typedef BinaryTree<int> IntTree;

char getChoice(string ok);
// Insert Value to Search Tree
void addToTree(IntTree &TheTree);
// Remove Value from Search Tree
void removeFromTree(IntTree &TheTree);

int main()
{IntTree Tree;
 int entry,*result;
 char Choice;
 do {
  cout << "Select: A)dd    R)emove     P)rint     T)ree Print     Q)uit\n";
  Choice=getChoice("ARPTQ");
  switch (Choice) {
   case 'A':
    addToTree(Tree);
    break;
   case 'P':
    cout << "The Tree:" << endl;
    Tree.inorder();
    break;
   case 'R':
    removeFromTree(Tree);
    break;
   case 'T':
    cout << "The tree, as it appears (sort of)..\n";
    Tree.treePrint(); 
  }
 } while (Choice!='Q');
}

//! getChoice()
/*!
 // \brief simply reads input in order to navigate through the menu
 */
char getChoice(string ok)
{char ch=' ';
 do ch=toupper(cin.get()); while (ok.find(ch)==string::npos);
 cin.get(); // eat CR
 return(toupper(ch));
}

//! addToTree()
/*!
// \brief Inserts Value to Search Tree
 */
void addToTree(IntTree &TheTree)
{  int entry;
   cout << " Enter an Integer >";
   cin >> entry;
   TheTree.insertToTree(entry);
}

//! removeFromTree()
/*!
// \brief Remove Value from Search Tree
 */
void removeFromTree(IntTree &TheTree)
{  int entry,*result;
   string selection;    // UPDATE
   bool flag = false;   // UPDATE 
   cout << "Value to Delete? >";
   cin >> entry;
   result=TheTree.treeSearch(entry);
   if (!result) 
     cout << entry << " Not Found\n";
   else{
     TheTree.retrieveFromTree(entry);    // UPDATE
     if (TheTree.isCounterMoreThanOne(entry) == true){ // UPDATE if more than one, gotta ask user if to delete all or one
     cout << "Do you want to remove all " << "copies or only one (A or O)" << endl; // UPDATE
    //  std::cin.ignore(INT_MAX); // UPDATE
    cin >> selection;   // AN ERROR W CIN MAYBE???
      if (selection != "a" || selection != "A" || selection != "o" || selection != "O"){
        while (selection != "a" || selection != "A" || selection != "o" || selection != "O"){  // update

          if (selection == "a" || selection == "A" || selection == "o" || selection == "O"){  //update
            break;	//update
          }

          cout << "Not a valid choice. Try again." << endl;  // update
          cin >> selection;    //update
          if (selection == "a" || selection == "A" || selection == "o" || selection == "O"){  //update
            break;	//update
          }

	}
      }

    }
    // IF there is more than one of the node and the user only wants to delete one...no need to delete

    if (selection == "o" || selection == "O"){   // update
      // nodeToDelete->counter = nodeToDelete->counter-1;
      TheTree.decrement(entry);
      // cout << nodeToDelete->counter << endl;
      return;
  }

    if (selection == "a" || selection == "A" && selection != "o" || selection != "O"){  // update
      // delete nodeToDelete;         // update
      TheTree.deleteFromTree(entry);
    }

     }


     // TheTree.deleteFromTree(entry);
  
  }

