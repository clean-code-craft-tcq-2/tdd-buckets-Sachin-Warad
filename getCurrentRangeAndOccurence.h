#include <stdio.h>
#include <string.h>

char* getCurrentRangeAndOccurence(int currentInputSamples[], size_t sampleSize);
void sortCurrentRanges(int currentInputSamples[], int sampleSize);
char* checkForConsecutiveSamples(int currentInputSamples[], int sampleSize);
char* formatOutput(int consecutiveSamples[], int size);
