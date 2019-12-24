#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  if(argc == 0)
  {
    perror("invalid input, executable not specified");
    return EXIT_FAILURE;
  }
  if(argc == 1)
  {
    char ** array = NULL;
    char * line = NULL;
    size_t size = 0;
    size_t i = 0;
    while(getline(&line, &size,stdin) >= 0)
    {
      array = realloc(array, ((i+1)*sizeof(*array)));
      array[i] = line;
      line = NULL;
      ++i;
    }
    for(size_t j = 0; j < i; ++j)
    {
      printf("%s",array[j]);
      free(array[j]);
    }
    free(array);
    return EXIT_SUCCESS;
  }
  if(argc > 1)
  {
    for(int k = 0; k < argc; ++k)
    {
      FILE * file = fopen(argv[k],"r+");
      char * line = NULL;
      char ** array = NULL;
      size_t size = 0;
      if(file == NULL)
      {
        printf("File %s does not exist or can not be opened\n", argv[k]);
        continue;
      }
      if(file != NULL)
      {
        fseek (file, 0, SEEK_END);
        size_t fileSize = ftell(file);
        if (fileSize == 0) {
            printf("File %s is empty\n",argv[k]);
            continue;
        }
        rewind(file);
        size_t i = 0;
        while(getline(&line,&size,file) >= 0)
        {
          array = realloc(array, ((i+1)*sizeof(*array)));
          array[i] = line;
          line = NULL;
          ++i;
        }
        free(line);
        sortData(array,i);
        for(size_t j = 0; j < i; ++j)
        {
          printf("%s",array[j]);
          free(array[j]);
        }
        free(array);
        if(fclose(file) != 0)
        {
          perror("Failed to close file");
          return EXIT_FAILURE;
        }
      }
    }
  }
  return EXIT_SUCCESS;
}

