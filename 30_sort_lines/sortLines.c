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

int main(int argc, char ** argv)
{
  if (argc == 0) 
  {
    fprintf(stderr,"not enough arguments \n");
    return EXIT_FAILURE;
  }
  else if (argc == 1) {
    //read from stdio
    char** array = NULL;
    char* line = NULL;
    size_t size = 0;
    size_t i = 0; 
    while(getline(&line , &size, stdin)>=0)
    {
      array = realloc(array, (i+1)*sizeof(*array));
      array[i]=line;
      line=NULL;
      ++i;
    }
    free(line);
    sortData(array, i);
    for(size_t j = 0; j < i; ++j)
    {
      printf("%s", array[j]);
      free(array[j]);
    }
    free(array);
  } else {
    for(size_t k=1; k<argc; ++k)
    {
      char** array=NULL;
      char* line=NULL;
      size_t size=0;
      size_t i =0; 
      FILE * f=fopen(argv[k],"r");
      if (f == NULL)
      {
        perror("Could not open file");
        return EXIT_FAILURE;
      }
      while(getline(&line, &size, f) >= 0)
      {
        array=realloc(array,(i+1)*sizeof(*array));
        array[i]=line;
        line=NULL;
        ++i;
      }
      free(line);
      sortData(array, i);
      for(size_t j = 0; j < i; ++j)
      {
        printf("%s", array[j]);
        free(array[j]);
      }
      free(array);
      if (fclose(f) != 0) 
      {
	      perror("Failed to close the input file!");
	      return EXIT_FAILURE;
      } 
    } 
  }
  return EXIT_SUCCESS;
}
