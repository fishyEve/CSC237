#include <iostream>

using namespace std;

int main(int argc,char **argv)
{ printf("There are %d command-line arguments:\n",argc);
  for (int idx=0;idx<argc;idx++)
    printf("%d: %s\n",idx, argv[idx]);
}
