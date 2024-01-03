/********************************************************
 *    File:    WordData.cpp                        			*
 *    Prepared by: Dr. Spiegel         		            	*
 *    Description: implementation for WordData.h        *
 ********************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

  /*****************************************************************/
  /*    Function name:   setWordData                               */
  /*                                                               */
  /*    Description:     Will set the object's string.             */
  /*                                                               */
  /*    Parameters:	 string wrd - Word to be placed in object  */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
WordData::WordData(string wrd, int cnt)
{
	setWordData(wrd, cnt);	
}


 /*****************************************************************/
  /*    Function name:   setWord                                   */
  /*                                                               */
  /*    Description:     Will set the object's string.             */
  /*                                                               */
  /*    Parameters:	 string wrd - Word to be placed in object  */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
void WordData::setWord(string wrd)
{
	word = wrd;
}


  /*****************************************************************/
  /*    Function name:   setCount                                  */
  /*                                                               */
  /*    Description:     Will set the occurence counter.           */
  /*                                                               */
  /*    Parameters:	 int cnt - Value to be placed in counter   */
  /*                                                               */
  /*    Member Type:                                               */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
void WordData::setCount(int cnt)
{
	count = cnt;
}


  /*****************************************************************/
  /*    Function name:   setWordData                               */
  /*                                                               */
  /*    Description:     Will set both the object's string and the */
  /*                     object's occurence count.                 */
  /*                                                               */
  /*    Parameters:	 string wrd - Word to be placed in object  */
  /*                     int cnt - Value to be placed in counter   */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
void WordData::setWordData(string wrd, int cnt)
{
	setWord(wrd);
	setCount(cnt);
}


  //GETTERS:
  //
  /*****************************************************************/
  /*    Function name:   getWord                                   */
  /*                                                               */
  /*    Description:     Will retrieve the object's string.        */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*    Member Type:     inspector                                 */
  /*                                                               */
  /*    Return Value:    string                                    */
  /*****************************************************************/
string WordData::getWord() const
{
	return(word);
}


  /*****************************************************************/
  /*    Function name:   getCount                                  */
  /*                                                               */
  /*    Description:     Will retrieve the occurence counter.	   */
  /*                                                               */
  /*    Parameters:	 none                                      */
  /*                                                               */
  /*    Member Type:     inspector                                 */
  /*                                                               */
  /*    Return Value:    int                                       */
  /*****************************************************************/
int WordData::getCount() const
{
	return(count);
}


  /*****************************************************************/
  /*    Function name:   operator ++                               */
  /*                                                               */
  /*    Description:     Will increment the occurrence counter.    */
  /*                                                               */
  /*    Parameters:	 int inc - Value to be incremented by	   */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
WordData& WordData::operator++()	// preincrement
{	setCount(getCount()+1);
	return(*this);
}


  /*****************************************************************/
  /*    Function name:   operator ++                               */
  /*                                                               */
  /*    Description:     Will increment the occurrence counter.    */
  /*                                                               */
  /*    Parameters:	 int inc - Value to be incremented by	   */
  /*                                                               */
  /*    Member Type:     mutator                                   */
  /*                                                               */
  /*    Return Value:    none                                      */
  /*****************************************************************/
WordData WordData::operator++(int)	// postincrement
{	WordData temp;
	setCount(getCount()+1);
	return(temp);
}


/*****************************************************************/
/*    Function name:   operator <<                               */
/*                                                               */
/*    Description:     Associated stream-insertion operator	 */
/*                                                               */
/*    Parameters:      ostream &output - output stream           */
/*                     const WordData &word  - object to print   */
/*                                                               */
/*    Member Type:     facilitator                               */
/*                                                               */
/*    Return Value:    none                                      */
/*****************************************************************/
ostream &operator<< (ostream &output, const WordData &word)
{
        output << setw(20) << left << word.getWord() <<
        setw(5)<< left     << word.getCount()   << endl;
        return output;
}
