#include "getCurrentRangeAndOccurence.h"

int getLowerCurrentLimit(int currentInputSamples[]);
int getUpperCurrentLimit(int currentInputSamples[]);

int getLowerCurrentLimit(int currentInputSamples[], int size) {
  int lowerLimit = currentInputSamples[0];
  for(int i=1; i<size; i++) {
    if(lowerLimit > currentInputSamples[i]) {
      lowerLimit = currentInputSamples[i];
    }
  }
  return lowerLimit;
}

int getUpperCurrentLimit(int currentInputSamples[], int size) {
  int upperLimit = currentInputSamples[0];
  printf("UpperLimitBefore for %d,%d\n",upperLimit, size);
  for(int i=1; i<size; i++) {
    if(upperLimit < currentInputSamples[i]) {
      upperLimit = currentInputSamples[i];
      printf("UpperLimit In for %d\n",upperLimit);
    }
  }
  printf("UpperLimit after for %d\n",upperLimit);
  return upperLimit;
}

char* getCurrentRangeAndOccurence(int currentInputSamples[]) {
  int temp[] = {4,5,6};
  char* buffer;
  int lowerCurrentLimit, upperCurrentLimit;
  int totalSize = sizeof(temp);
  int indiSize = sizeof(temp[0]);
  int size = sizeof(temp)/sizeof(temp[0]);
  for(int i=0; i<3; i++) {
    printf("%d\n", currentInputSamples[i]);
  }
  printf("%d,%d,%d\n",totalSize, indiSize, size);
  lowerCurrentLimit = getLowerCurrentLimit(currentInputSamples, size);
  upperCurrentLimit = getUpperCurrentLimit(currentInputSamples, size);
  sprintf(buffer,"%d-%d, %d",lowerCurrentLimit,upperCurrentLimit,size);
  printf("%s",buffer);
  return buffer;
}
