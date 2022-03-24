struct intrepetedData
{
    int Min;
    int Max;
    int Size;
};

int getCurrentRangeAndOccurence(int currentInputSamples[], size_t sampleSize, struct intrepetedData dataInterpreted[], void (*fn_ptrPrintOutput)(int min, int max, int count));
int validateInputs(int currentInputSamples[], int sampleSize);
int handleValidSampleCase(int currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[]);
void sortCurrentRanges(int currentInputSamples[], int sampleSize);
int checkForConsecutiveSamples(int currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[]);
void updateIntrepretedData(struct intrepetedData dataInterpreted[], int consecutiveSamples[], int size, int consecutiveSamplesNumber);
void printOnConsole(int min, int max, int count);
