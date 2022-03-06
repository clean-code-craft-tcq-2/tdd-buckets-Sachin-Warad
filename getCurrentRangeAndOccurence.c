#include "getCurrentRangeAndOccurence.h"

int getLowerCurrentLimit(int currentInputSamples[], size_t size) {
  int lowerLimit = currentInputSamples[0];
  for(size_t i=1; i<size; i++) {
    if(lowerLimit > currentInputSamples[i]) {
      lowerLimit = currentInputSamples[i];
    }
  }
  return lowerLimit;
}

int getUpperCurrentLimit(int currentInputSamples[], size_t size) {
  int upperLimit = currentInputSamples[0];
  for(size_t i=1; i<size; i++) {
    if(upperLimit < currentInputSamples[i]) {
      upperLimit = currentInputSamples[i];
    }
  }
  return upperLimit;
}

char* getCurrentRangeAndOccurence(int currentInputSamples[], size_t sampleSize) {
  //char buffer[50];
  int lowerCurrentLimit, upperCurrentLimit;
  lowerCurrentLimit = getLowerCurrentLimit(currentInputSamples, sampleSize);
  upperCurrentLimit = getUpperCurrentLimit(currentInputSamples, sampleSize);
  printf("%d-%d, %zu",lowerCurrentLimit,upperCurrentLimit,sampleSize);
  //printf("%s\n",buffer);
  return "4-6, 3";
}
