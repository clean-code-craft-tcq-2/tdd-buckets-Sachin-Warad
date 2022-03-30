#include <stdio.h>
#include <string.h>
#include <math.h>
#include "getCurrentRangeAndOccurence.h"

void updateIntrepretedData(struct intrepetedData dataInterpreted[], double consecutiveSamples[], int size, int consecutiveSamplesNumber) {
    dataInterpreted[consecutiveSamplesNumber].Min = consecutiveSamples[0];
    dataInterpreted[consecutiveSamplesNumber].Max = consecutiveSamples[size];
    dataInterpreted[consecutiveSamplesNumber].Size = size+1;
    return;
}

int checkForConsecutiveSamples(double currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[]) {
  int index=0,consecutiveSamplesNumber=0; 
  double consecutiveSamples[sampleSize];
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

void sortCurrentRanges(double currentInputSamples[], int sampleSize) {
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

void printOnConsole(double min, double max, int count) {
        printf("%.0f-%.0f, %d\n",min,max,count);
}

int validateInputs(double currentInputSamples[], int sampleSize) {
    for(int i=0; i<sampleSize-1; i++) {
        if(currentInputSamples[i] < 0 || currentInputSamples[i] == MaxRange12BitSensor) {
            return 0;
        }
    }
    return 1;
}

void convertToAmps(double currentInputSamples[],int sampleSize) {
    for(int i=0; i<sampleSize; i++) {
        float ampValue = (10 * currentInputSamples[i])/4094;
        currentInputSamples[i] = lround(ampValue);
    }
}

int handleValidSampleCase(double currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[]) {
    convertToAmps(currentInputSamples,sampleSize);
    sortCurrentRanges(currentInputSamples, sampleSize);
    int consecutiveSamples = checkForConsecutiveSamples(currentInputSamples, sampleSize, dataInterpreted);
    return consecutiveSamples;
}

int getCurrentRangeAndOccurence(double currentInputSamples[], size_t sampleSize, struct intrepetedData dataInterpreted[], void (*fn_ptrPrintOutput)(double min, double max, int count)) {
  int isInputsValid = validateInputs(currentInputSamples,sampleSize);
  if(isInputsValid == 1) {
    int consecutiveSamples = handleValidSampleCase(currentInputSamples, sampleSize, dataInterpreted);
    for(int i=0; i<consecutiveSamples; i++) {
        fn_ptrPrintOutput(dataInterpreted[i].Min,dataInterpreted[i].Max,dataInterpreted[i].Size);  
    }
    return consecutiveSamples;
  }
  fn_ptrPrintOutput(0,0,0);
  return 0;
  
}
