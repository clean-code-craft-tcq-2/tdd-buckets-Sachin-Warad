#include <stdio.h>
#include <string.h>
#include "getCurrentRangeAndOccurence.h"

void updateIntrepretedData(struct intrepetedData dataInterpreted[], int consecutiveSamples[], int size, int consecutiveSamplesNumber) {
    Details[consecutiveSamplesNumber].Min = consecutiveSamples[0];
    Details[consecutiveSamplesNumber].Max = consecutiveSamples[size];
    Details[consecutiveSamplesNumber].Size = size+1;
    return;
}

int checkForConsecutiveSamples(int currentInputSamples[], size_t sampleSize, struct intrepetedData dataInterpreted[]) {
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

int getCurrentRangeAndOccurence(int currentInputSamples[], size_t sampleSize, struct intrepetedData dataInterpreted[]) {
  sortCurrentRanges(currentInputSamples, sampleSize);
  int consecutiveSamples = checkForConsecutiveSamples(currentInputSamples, sampleSize, dataInterpreted);
  for(int i=0; i<consecutiveSamples; i++) {
        printf("%d-%d, %d\n",dataInterpreted[i].Min,dataInterpreted[i].Max,dataInterpreted[i].Size);
  }
  return consecutiveSamples;
}
