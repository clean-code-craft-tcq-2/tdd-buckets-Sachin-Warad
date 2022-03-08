#include <stdio.h>
#include <string.h>
#include "getCurrentRangeAndOccurence.h"

char* formatOutput(int consecutiveSamples[], int size) {
  char result[50];
  char *buffer = result;
  if(size > 1) {
    sprintf(buffer,"%d-%d, %d\n",consecutiveSamples[0],consecutiveSamples[size-1],size);
  }else {
    sprintf(buffer,"%d, %d\n",consecutiveSamples[0],size);
  }
  return buffer;
}

char* checkForConsecutiveSamples(int currentInputSamples[], int sampleSize) {
  int index=0,consecutiveSamples[10];
  char result[50];
  char *buffer = result;
    for(int i=0; i<sampleSize; i++) {
        consecutiveSamples[index] = currentInputSamples[i];
        if(currentInputSamples[i+1] - currentInputSamples[i] <= 1) {
            index++;
        }else {
            strcat(buffer,formatOutput(consecutiveSamples,(index+1)));
            index=0;
        }
    }
    printf("%s",buffer);
    return buffer;
}

void sortCurrentRanges(int currentInputSamples[], int sampleSize) {
  int i, j, temp;
  for(i=0; i<sampleSize-1; i++) {
      for(j=i+1; j<sampleSize; j++) {
          if(currentInputSamples[i] > currentInputSamples[j]) {
              temp = currentInputSamples[i];
              currentInputSamples[i] = currentInputSamples[j];
              currentInputSamples[j] = temp;
          }
      }
  }
}

char* getCurrentRangeAndOccurence(int currentInputSamples[], size_t sampleSize) {
  sortCurrentRanges(currentInputSamples, sampleSize);
  char *buffer = checkForConsecutiveSamples(currentInputSamples, sampleSize);
  return buffer;
}
