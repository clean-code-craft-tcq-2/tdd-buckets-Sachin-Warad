#include <stdio.h>
#include <string.h>
#include "getCurrentRangeAndOccurence.h"

void updateIntrepretedData(struct intrepetedData dataInterpreted[], int consecutiveSamples[], int size, int consecutiveSamplesNumber) {
    dataInterpreted[consecutiveSamplesNumber].Min = consecutiveSamples[0];
    dataInterpreted[consecutiveSamplesNumber].Max = consecutiveSamples[size];
    dataInterpreted[consecutiveSamplesNumber].Size = size+1;
    return;
}

int checkForConsecutiveSamples(int currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[]) {
  int index=0,consecutiveSamplesNumber=0, consecutiveSamples[sampleSize];
  for(int i=0; i<sampleSize; i++) {
      consecutiveSamples[index] = currentInputSamples[i];
      if((currentInputSamples[i+1] - currentInputSamples[i] <= 1) && (i<sampleSize-1)) {
          index++;
      }else {
         updateIntrepretedData(dataInterpreted, consecutiveSamples, index, consecutiveSamplesNumber);
         consecutiveSamplesNumber++;
         index=0;
      }
  }
  return consecutiveSamplesNumber;
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

void printOnConsole(int min, int max, int count) {
        printf("%d-%d, %d\n",min,max,count);
}

int validateInputs(int currentInputSamples[], int sampleSize) {
    for(int i=0; i<sampleSize-1; i++) {
        if(currentInputSamples[i] < 0) {
            return 0;
        }
    }
    return 1;
}

int handleValidSampleCase(int currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[]) {
    sortCurrentRanges(currentInputSamples, sampleSize);
    int consecutiveSamples = checkForConsecutiveSamples(currentInputSamples, sampleSize, dataInterpreted);
    return consecutiveSamples;
}

int getCurrentRangeAndOccurence(int currentInputSamples[], size_t sampleSize, struct intrepetedData dataInterpreted[], void (*fn_ptrPrintOutput)(int min, int max, int count)) {
  int isInputsValid = validateInputs(currentInputSamples,sampleSize);
  if(isInputsValid == 1) {
    int consecutiveSamples = handleValidSampleCase(currentInputSamples, sampleSize, dataInterpreted);
    for(int i=0; i<consecutiveSamples; i++) {
        fn_ptrPrintOutput(dataInterpreted[i].Min,dataInterpreted[i].Max,dataInterpreted[i].Size);  
    }
    return consecutiveSamples;
  }
  return 0;
  
}
