#include "beadando.h"
void reverse_file(FILE *file, int vanline, int sorhossz)
{
  // Open each file in turn

  // Read each line from the file and reverse it
  int line_num = 0;
  int size = 2;
  char **lines = malloc(2 * sizeof(char *));
  if (NULL == lines)
  {
    printf("Memory allocation failed!");
    exit(1);
  }

  char *buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
  if (NULL == buffer)
  {
    printf("Memory allocation failed!");
    free(lines);
    exit(1);
  }
  // Read each line again and output it in reverse order

  int x = 0;
  while (fgets(buffer, BUFFER_SIZE, file) != NULL)
  {
    lines[x] = malloc(sorhossz * sizeof(char) + 1);
    if (NULL == lines[x])
      {
        printf("Memory allocation failed!");
        for (int i = 0; i < x; i++)
        {
          free(lines[i]);
        }

        free(lines);
        free(buffer);
        exit(1);
      }
    strncpy(lines[x], buffer, sorhossz);
    // Remove the newline character from the line
    int len = strlen(lines[x]);

    if (lines[x][len - 1] == '\n')
    {
      lines[x][len - 1] = '\0';
    }

    // Reverse the line in place
    for (int i = 0, j = len - 2; i < j; i++, j--)
    {
      char tmp = lines[x][i];
      lines[x][i] = lines[x][j];
      lines[x][j] = tmp;
    }
    x++;
    if (size == x)
    {
      char **ptr = realloc(lines, size * 2 * sizeof(char *));
      if (NULL == ptr)
      {
        printf("Memory allocation failed!");
        for (int i = 0; i < x; i++)
        {
          free(lines[i]);
        }

        free(lines);
        free(buffer);
        exit(1);
      }
      lines = ptr;
      size *= 2;
    }
  }

  for (int i = x - 1; i >= 0; i--)
  {
    if (vanline == 1)
    {
      printf("%d %s\n", x - i, lines[i]);
      free(lines[i]);
    }
    else
    {
      printf("%s\n", lines[i]);
      free(lines[i]);
    }
  }

  fclose(file);
  free(lines);
  free(buffer);
}
