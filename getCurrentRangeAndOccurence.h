struct IntrepetedData
{
    int Min;
    int Max;
    int Size;
};

char* getCurrentRangeAndOccurence(int currentInputSamples[], size_t sampleSize);
void sortCurrentRanges(int currentInputSamples[], int sampleSize);
char* checkForConsecutiveSamples(int currentInputSamples[], int sampleSize);
char* formatOutput(int consecutiveSamples[], int size);
