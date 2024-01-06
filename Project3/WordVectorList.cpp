/*******************************************************************/
/*    Author:        Eve Collier                                   */
/*    Course:        CSC237                                        */
/*    Date:          3/26/23                                       */
/*    Filename:      WordVectorList.cpp                            */
/*    Description:   WordVectorList.cpp is a cpp file containing   */
/*                   the implementation from our WordVectorList.h  */
/*                   file                                          */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*                                                                 */
/*******************************************************************/

#include <iostream>
#include <sstream>
#include <assert.h>
#include "WordVectorList.h"
#include <bits/stdc++.h>  // for sorting our vector ascendingly

#include <chrono>
#include <cmath>

/*!
          \file WordVectorList.cpp
          \brief a cpp containing the implementation for WordVectorList.h
          \class WordVectorList.cpp
          \brief a cpp containing the implementation for WordVectorList.h

 */

using namespace std;

   //! WordVectorList()
   /*/
    */
WordVectorList::WordVectorList(){
   // VList = vector<WordData>();
}

   //! parseIntoList()
   /*!
      \brief Parses information from a file into a vector
    */
void WordVectorList::parseIntoList(ifstream &inf){
    using namespace std::chrono;
    cout << " " << endl;
    std::cout << "Calculating time to parse words into the vector...\n";

    auto begin = high_resolution_clock::now();

  bool flag = false;   // helper for later
  string temp;
  while (inf >> temp){
    flag = false;
    for (int i = 0; i < VList.size(); i++){
      if (temp ==VList.at(i).getWord()){
        flag = true;  // we found a duplicate word. Huzzah
        VList[i].incCount(1);
      }
     }

    if (flag == false && temp != ""){ // there are no duplicate words. Can make new object
      WordData data;
      data.setWordData(temp, 1);
      VList.push_back(data);
    }
   

  }
  sort(VList.begin(), VList.end());

    auto end = high_resolution_clock::now();
    auto ticks = duration_cast<microseconds>(end-begin);

    std::cout << "It took me " << ticks.count() << " microseconds to parse words into the vector.\n";
}

   //! printIteratively()
   /*!
      \brief Print the data iteratively
    */
void WordVectorList::printIteratively(){
  using namespace std::chrono;
  cout << " " << endl;
  std::cout << "Calculating time to print the vector iteratively...\n";

  auto begin = high_resolution_clock::now();

  cout<<"--------------------------"<<endl;
  cout<<"|STL    Vector  Iterative|"<<endl;
  cout<<"|Word         Occurences |"<<endl;
  cout<<"--------------------------"<<endl;

  for (auto i = VList.begin(); i != VList.end(); i++){
    cout << *i << " " << endl;
  }

  auto end = high_resolution_clock::now();
  auto ticks = duration_cast<microseconds>(end-begin);

  std::cout << "It took me " << ticks.count() << " microseconds to print the vector iteratively.\n";
  cout << " " << endl;

}

   //! printRecursively()
   /*!
      \brief Calls helper function to print the data recursively
    */
void WordVectorList:: printRecursively(){
  using namespace std::chrono;
  cout << " " << endl;
  std::cout << "Calculating time to print the vector recursively...\n";

  auto begin = high_resolution_clock::now();
  cout<<"--------------------------"<<endl;
  cout<<"|STL    Vector  Recursive|"<<endl;
  cout<<"|Word         Occurences |"<<endl;
  cout<<"--------------------------"<<endl;

  reverse(VList.begin(), VList.end());
  printRecursivelyHelper(VList);
  
  auto end = high_resolution_clock::now();
  auto ticks = duration_cast<microseconds>(end-begin);

  std::cout << "It took me " << ticks.count() << " microseconds to print the vector recursively.\n";
  cout << " " << endl;


}

   //! printRecursivelyHelper()
   /*!
      \brief Helper function that prints the data recursively
    */
void WordVectorList::printRecursivelyHelper(vector<WordData> &VList){
 
   if(VList.size()==0){
    return;
   }
   else{
    cout << VList.back() << endl;
    VList.pop_back();
    printRecursivelyHelper(VList);
   }

  //if (VItr == VList.end()){
  //  return;
  //}
  //else{
   // cout << VList.at(VItr.data()) << endl;
   // VItr = VItr+1;
   // printRecursivelyHelper(VList, VItr);
  //}
}

