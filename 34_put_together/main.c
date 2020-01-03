#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t * out = createCounts();
  FILE * f = fopen(filename, "r");
  if(f == 0) return NULL;
  char * line = NULL;
  size_t size = 0;
  char * newline = NULL;
  while(getline(&line, &size, f) >= 0)
  {
    if((newline = strchr(line, '\n')) != NULL) *newline = '\0';
    newline = lookupValue(kvPairs, line);
    addCount(out, newline);
  }
  free(line);
  if(fclose(f) != 0) return NULL;
  return out;
}
int checkInputFormat(char * a)
{
    char * suffix = ".txt";
    size_t slen = strlen(a);
    size_t suffix_len = strlen(suffix);
    return suffix_len <= slen && !strcmp(a + slen - suffix_len, suffix);
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc < 2)
  {
    perror("not enough arguments");
    return EXIT_FAILURE;
  }
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = NULL;
  kv = readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)
  for(int i = 2; i < argc; ++i)
  {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c = countFile(argv[i], kv);
    if(c == NULL)
    {
      perror("invalid contents");
      return EXIT_FAILURE;
    }
    //compute the output file name from argv[i] (call this outName)
    char * outname = computeOutputFileName(argv[i]);
    //open the file named by outName (call that f)
    FILE * f = fopen(outname, "w");
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    if(fclose(f) != 0)
    {
      perror("could not clsoe file");
      return EXIT_FAILURE;
    }
    //free the memory for outName and c
    free(outname);
    freeCounts(c);
  }
 //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
