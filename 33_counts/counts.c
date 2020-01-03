#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * out;
  out = malloc(sizeof(counts_t));
  out->arr = NULL;
  out->arr = malloc(sizeof(*(out->arr)));
  out->size = 0;
  out->unknownCount = 0;
  return out;
}

void allocateNewCount(counts_t * c, const char * name)
{
  c->arr = realloc(c->arr, ((c->size)+1) * sizeof(*(c->arr)));
  c->arr[c->size] = NULL;
  c->arr[c->size] = malloc(sizeof(one_count_t));
  c->arr[c->size]->count = NULL;
  c->arr[c->size]->count = malloc(sizeof(name)+4);
  c->arr[c->size]->num = 1;
  strcpy(c->arr[c->size]->count, name);
  ++c->size;
}

void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name == NULL)
  {
    ++c->unknownCount;
  } else {
    int foundOne = 0;
    for(size_t i = 0; i < c->size; ++i)
    {
      if(strcmp(name, c->arr[i]->count) == 0)
      {
        ++c->arr[i]->num;
        ++foundOne;
      }
    }
    if(foundOne == 0) allocateNewCount(c, name);
  }
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(size_t i = 0; i < c->size; ++i)
  {
    fprintf(outFile, "%s: %lu\n", c->arr[i]->count, c->arr[i]->num);
  }
  if(c->unknownCount != 0) fprintf(outFile, "<unknown>: %lu\n", c->unknownCount);
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(size_t i = 0; i < c->size; ++i)
  {
    free(c->arr[i]->count);
    free(c->arr[i]);
  }
  free(c->arr);
  free(c);
}
