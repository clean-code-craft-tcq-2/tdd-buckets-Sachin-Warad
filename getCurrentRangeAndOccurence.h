struct intrepetedData
{
    int Min;
    int Max;
    int Size;
};

int getCurrentRangeAndOccurence(int currentInputSamples[], size_t sampleSize, struct intrepetedData dataInterpreted[]);
void sortCurrentRanges(int currentInputSamples[], int sampleSize);
int checkForConsecutiveSamples(int currentInputSamples[], size_t sampleSize, struct intrepetedData dataInterpreted[]);
void updateIntrepretedData(struct intrepetedData dataInterpreted[], int consecutiveSamples[], int size, int consecutiveSamplesNumber);
