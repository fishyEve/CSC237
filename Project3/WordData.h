/****************************************************************/
/*   Filename:       WordData.h                                 */
/*   Purpose:        The Only Addition i made to this file was  */ 
/*                   an overloading of the << operator.         */
/****************************************************************/

#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

/*!
          \file WordData.h
          \brief a header file containing the definition for a WordData object. 
	  \class WordData
          \brief a header file containing the definition for a WordData object.
 */

using namespace std;

class WordData {

public:

        //! Constructor
        /*!	  
           - constructs a word data object, which contains a string (holding a word)
           and an int (holding the number of occurances the word occurs in the file)
  	 */
        WordData(string wrd = "", int cnt = 1);

        //! Setter
        /*!
          - sets a word of string type
         */
        void setWord(string wrd);

	//! Setter
	/*!
	    - set a counter (of words) of int type
 	*/
        void setCount(int cnt);

        //! Setter  
        /*!
            - sets a whole WordData object
        */
        void setWordData(string,int);


        //! Getter  
        /*!
            - gets a word of string type
        */
        string getWord() const;

        //! Getter  
        /*!
            - gets a count (of word occurances) of int type
        */
        int getCount() const;

  
        //! Incrementer  
        /*!
            - increases a count by one
        */
        void incCount(int inc = 1);



        //! Operator Overload (>)  
        /*!
            - returns a bool determining if the WordData object on the left is greater than the WordData
	      object on the right.
        */
	bool operator>(const WordData &) const;


        //! Operator Overload (<)
        /*!
            - returns a bool determining if the WordData object	on the right is greater than the WordData
              object on	the left. 
        */
        bool operator<(const WordData &) const;


        //! Operator Overload (=)
        /*!
            - returns a bool determining if the WordData object	on the left is equal to the WordData
              object on	the right. 
        */
        bool operator==(const WordData &) const;

private:

        //! Variable
        /*!
           - a string holding a unique word 
         */
        string word;

        //! Variable 
        /*!
           - an int holding a count of occurances of a specific word    
         */
        int count;


};

ostream &operator<<(ostream& output, const WordData &words);

#endif
