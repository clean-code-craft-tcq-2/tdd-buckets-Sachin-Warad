#include "getCurrentRangeAndOccurence.h"

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
  for(int i=1; i<size; i++) {
    if(upperLimit < currentInputSamples[i]) {
      upperLimit = currentInputSamples[i];
    }
  }
  return upperLimit;
}

char* getCurrentRangeAndOccurence(int currentInputSamples[], int sampleSize) {
  char* buffer;
  int size = sizeof(currentInputSamples)/sizeof(currentInputSamples[0]);
  printf("%d\n",size);
  int lowerCurrentLimit, upperCurrentLimit;
  lowerCurrentLimit = getLowerCurrentLimit(currentInputSamples, sampleSize);
  upperCurrentLimit = getUpperCurrentLimit(currentInputSamples, sampleSize);
  sprintf(buffer,"%d-%d, %d",lowerCurrentLimit,upperCurrentLimit,sampleSize);
  printf("%s\n",buffer);
  return buffer;
}
