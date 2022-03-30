struct intrepetedData
{
    double Min;
    double Max;
    int Size;
};

#define MaxRange12BitSensor  4095

int getCurrentRangeAndOccurence(double currentInputSamples[], size_t sampleSize, struct intrepetedData dataInterpreted[], void (*fn_ptrPrintOutput)(double min, double max, int count));
int validateInputs(double currentInputSamples[], int sampleSize);
int handleValidSampleCase(double currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[]);
void sortCurrentRanges(double currentInputSamples[], int sampleSize);
int checkForConsecutiveSamples(double currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[]);
void updateIntrepretedData(struct intrepetedData dataInterpreted[], double consecutiveSamples[], int size, int consecutiveSamplesNumber);
void printOnConsole(double min, double max, int count);
void convertToAmps(double currentInputSamples[],int sampleSize);
