// File: WordDataList.cpp
// Container of WordData objects 
//   Implementations of member functions including inherited pure virtual fns.
/*!
          \file WordDataList.cpp
          \brief a cpp containing the implementation for WordDataList.h
          \class WordDataList.cpp
	  \brief a cpp containing the implementation for WordDataList.h

 */
#include <sstream>
#include <iostream>
#include "WordDataList.h"

#include <chrono>
#include <cmath>

using namespace std;

   //! WordDataList()
   /*/
    */
  WordDataList::WordDataList()
  { numWords=0; }


   //! incMatch()
   /*!
      \brief This function merely increments a word occurence if a word is found to be matching with
       the string that is passed in.
    */
  bool WordDataList::incMatch(string temp)
  { for(int i=0; i<numWords; i++) {
      if (temp==TheWords[i].getWord()) {
        TheWords[i].incCount();
        return true;
      }
    }  
    return false;
  }


   //! parseIntoList()
   /*! \brief Parses information from a file into an array      
    */
  void WordDataList::parseIntoList(ifstream &inf)
  { string temp;

    using namespace std::chrono;
    cout << " " << endl;
    std::cout << "Calculating time to parse words into object array...\n";

    auto begin = high_resolution_clock::now();

    while (inf >> temp) 
      if (!incMatch(temp) && numWords < 10) {
          TheWords[numWords].setWord(temp);
          TheWords[numWords++].setCount(1);
      }

    auto end = high_resolution_clock::now();
    auto ticks = duration_cast<microseconds>(end-begin);
   
    std::cout << "It took me " << ticks.count() << " microseconds to parse words into list.\n";

  }

  
   //! printIteratively() 
   /*!             
      \brief Print the data iteratively
    */
  void WordDataList::printIteratively()
  //  void printObjectArrayIterator(WordData TheWords[], int numWords)
  {
    using namespace std::chrono;
    cout << " "	<< endl;
    std::cout << "Calculating time to print the object array iteratively...\n";

    auto begin = high_resolution_clock::now();

    cout<<"--------------------------"<<endl;
    cout<<"|Object  Array  Iterative|"<<endl;
    cout<<"|Word         Occurences |"<<endl;  
    cout<<"--------------------------"<<endl;

    for(int i=0; i<numWords; i++){
    cout<<" "<<TheWords[i]<<endl;
    }

    auto end = high_resolution_clock::now();
    auto ticks = duration_cast<microseconds>(end-begin);

    std::cout << "It took me " << ticks.count() << " microseconds to print the object array iteratively.\n";  
    cout << " "	<< endl;

  }

   //! printRecursivelyWorker
   /*!               
      \brief Worker function that prints the data recursively
    */  
  // Print the data recursively
  void WordDataList::printRecursivelyWorker(int numWords)
  //void printObjectArrayRecursive(WordData TheWords[], int numWords)
  {
      if (numWords==1) {
      cout<<"--------------------------"<<endl;
      cout<<"|Object  Array  Recursive|"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      cout<<" "<<TheWords[numWords-1]<<endl;
      return;
    }
    printRecursivelyWorker(numWords-1);
    cout<<" "<<TheWords[numWords-1]<<endl;

  }

 
   //! printRecursively()
   /*!
      \brief Calls worker function to print the data recursively
    */
  void WordDataList::printRecursively()
  {  
    using namespace std::chrono;
    cout << " "	<< endl;
    std::cout << "Calculating time to print the object array recursively...\n";

    auto begin = high_resolution_clock::now();

    printRecursivelyWorker(numWords); 

    auto end = high_resolution_clock::now();
    auto ticks = duration_cast<microseconds>(end-begin);

    std::cout << "It took me " << ticks.count() << " microseconds to print the object array recursively.\n";
    cout << " "	<< endl;

}
   //! printPtrWorker()
   /*!
      \brief Print the data recursively with a pointer
    */

  void WordDataList::printPtrWorker(int numWords)
  //void printObjectArrayPointerRecursive(WordData* TheWords, int numWords)
  {

    if (!numWords)
    { cout<<"--------------------------"<<endl;
      cout<<"|Object  Array  Pointer  |"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      return;
    }
 
    printPtrWorker(numWords-1);
    cout<<" "<<*(TheWords+(numWords-1))<<endl;

  }

   //! printPtr()
   /*!
      \brief Calls worker function to print the data recursively
    */
  void WordDataList::printPtr(){
 
  using namespace std::chrono;
  cout << " "	<< endl;
  std::cout << "Calculating time to print the object array with a pointer...\n";

  auto begin = high_resolution_clock::now();

  printPtrWorker(numWords); 

  auto end = high_resolution_clock::now();
  auto ticks = duration_cast<microseconds>(end-begin);

  std::cout << "It took me " << ticks.count() << " microseconds to print the object array with a pointer.\n";
  cout << " "	<< endl;
}
