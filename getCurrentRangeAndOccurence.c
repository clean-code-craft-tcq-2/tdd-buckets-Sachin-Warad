#include "getCurrentRangeAndOccurence.h"

int getLowerCurrentLimit(int currentInputSamples[]);
int getUpperCurrentLimit(int currentInputSamples[]);

int getLowerCurrentLimit(int currentInputSamples[], int size) {
  int lowerLimit = currentInputSamples[0];
  for(int i=1; i<size; i++) {
    if(lowerLimit < currentInputSamples[i]) {
      lowerLimit = currentInputSamples[i];
    }
  }
  return lowerLimit;
}

int getUpperCurrentLimit(int currentInputSamples[], int size) {
  int upperLimit = currentInputSamples[0];
  for(int i=1; i<size; i++) {
    if(upperLimit > currentInputSamples[i]) {
      upperLimit = currentInputSamples[i];
    }
  }
  return upperLimit;
}

char* getCurrentRangeAndOccurence(int currentInputSamples[]) {
  char* buffer;
  int lowerCurrentLimit, upperCurrentLimit;
  int size = sizeof(currentInputSamples)/sizeof(currentInputSamples[0]);
  lowerCurrentLimit = getLowerCurrentLimit(currentInputSamples, size);
  upperCurrentLimit = getUpperCurrentLimit(currentInputSamples, size);
  sprintf(buffer,"%d-%d, %d",lowerCurrentLimit,upperCurrentLimit,size);
  return buffer;
}
