// cExec.cpp
// Batch Processor for Running Project 3 Multiple Times
// The input file name is passed in.

// #include <process.h>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <wait.h>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc,char **argv)
{int termstat,pid,count;
  // Command line arguments are:
  // cexec app  <file name> <Variable value>

  char **CommandArgs;
  int numTimes=10;  // atoi(argv[2]);

  for (count=0;count<numTimes;count++) {
    cerr << "\n\nTrial: " << count+1 << endl;   
    if ((pid=_spawnv(_P_WAIT,argv[1],argv+1))<0) {
    // if ((pid=fork())<0) {
      perror("Spawn of fork");
      exit(-1);
    }
    else {// parent just waits; collects child
      _cwait( &termstat, pid, _WAIT_CHILD );
      // wait(&termstat);
    }
  } // for loop
  return(0);
} // main
