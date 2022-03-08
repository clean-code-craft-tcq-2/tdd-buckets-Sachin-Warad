#include "getCurrentRangeAndOccurence.h"

char* formatOutput(int consecutiveSamples[], int size) {
  char result[50];
  char *buffer = result;
  sprintf(buffer,"%d-%d, %d\n",consecutiveSamples[0],consecutiveSamples[size-1],size);
  //printf("%s",buffer);
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
            //buffer = formatOutput(consecutiveSamples,(index+1));
            strcat(buffer,formatOutput(consecutiveSamples,(index+1)));
            //printf("%s",buffer);
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
//   char result[50];
//   char *buffer = result;
  sortCurrentRanges(currentInputSamples, sampleSize);
  char *buffer = checkForConsecutiveSamples(currentInputSamples, sampleSize);
  return buffer;
}
