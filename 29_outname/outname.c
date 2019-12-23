#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) 
{
  char * outputName = malloc((strlen(inputName)+11)*sizeof(*inputName));
  strcpy(outputName, inputName);
  strcat(outputName, ".counts");
  return outputName;
}
