#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "beadando.h"




int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    fprintf(stderr, "Usage:\n\trev [SHOW LINE NUMBERS] [MAX LINE LENGTH] files...)\n");
    return 1;
  }

  info a;
  a.maxnum = atoi(argv[2]);

  if (strcmp(argv[1], "linenums") == 0)
  {
    a.lin = 1;
  }
  else if (strcmp(argv[1], "nolinenums") == 0)
  {
    a.lin = 0;
  }
  else
  {
    fprintf(stderr, "Rossz argumentum: Csak linenums/nolinenums lehetséges\n");
    return 1;
  }

  if (argc == 3)
  {
    reverse_file(stdin,a.lin,a.maxnum);
  }
  else
  {
    for (int i = 3; i < argc; i++)
    {
      FILE* file = fopen(argv[i],"r");
      if (file == NULL)
    {
      fprintf(stderr, "File opening unsuccessful: <%s>\n", argv[i]);
      continue;
    }
    reverse_file(file, a.lin,a.maxnum);
    }
    
  }

  return 0;
}

