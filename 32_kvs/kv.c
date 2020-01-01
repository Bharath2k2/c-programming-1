#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * findKVs(char * line)
{
  char * pointer = strchr(line, '=');
  *pointer = '\0';
  ++pointer;
  kvpair_t * kv_out = malloc(sizeof(kvarray_t));
  kv_out->key = line;
  kv_out->value = pointer;
  return kv_out;
}

kvarray_t * readKVs(const char * fname) 
{
  //WRITE ME
  FILE * file = fopen(fname, "r");
  if(file == 0)
  {
    printf("Can't open file");
    return NULL;
  }
  kvarray_t * p = malloc((size_t)sizeof(kvarray_t));
  p->num = 0;
  char * line = NULL;
  size_t sz = 0;
  while(getline(&line, &sz, file) >= 0)
  {
    p->arr = realloc(p->arr, ((p->num) + 1)*sizeof(line));
    p->arr[p->num] = findKVs(line);
    p->num++;
    line = NULL;
  }
  free(line);
  if(fclose(file) == EOF) 
  {
    printf("Failed to close file");
    return NULL;
  } 
  return p;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(size_t i = 0; i < pairs->num; ++i)
  {
    free(pairs->arr[i]->key);
    free(pairs->arr[i]);
  }
  free(pairs->arr);
  free(pairs);
}

void printKVs(kvarray_t * pairs) 
{
  //WRITE ME
  for(size_t i = 0; i < pairs->num; ++i)
  {
    printf("key = '%s' value = '%s'\n", pairs->arr[i]->key, pairs->arr[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) 
{
  //WRITE ME
  char * out;
  for(size_t i = 0; i < pairs->num; ++i)
  {
    out = pairs->arr[i]->key;
    if(strcmp(out, key) == 0) return out;
  }
  return NULL;
}
