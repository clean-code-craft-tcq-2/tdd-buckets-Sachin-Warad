struct intrepetedData
{
    double Min;
    double Max;
    int Size;
};

typedef enum {
  Sensor12Bit,
  Sensor10Bit
} SensorType;

#define SensorMax12Bit 4095
#define SensorMax10Bit 1023

typedef void (*convToAmps_funcptr)(double*,int);

int getCurrentRangeAndOccurence(double currentInputSamples[], size_t sampleSize, struct intrepetedData dataInterpreted[], 
                                void (*fn_ptrPrintOutput)(double min, double max, int count), SensorType sensor);
int validateInputs(double currentInputSamples[], int sampleSize, SensorType sensor, double sensorMaxValueErr[]);
int handleValidSampleCase(double currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[], SensorType sensor, convToAmps_funcptr ampConverter[]);
void sortCurrentRanges(double currentInputSamples[], int sampleSize);
int checkForConsecutiveSamples(double currentInputSamples[], int sampleSize, struct intrepetedData dataInterpreted[]);
void updateIntrepretedData(struct intrepetedData dataInterpreted[], double consecutiveSamples[], int size, int consecutiveSamplesNumber);
void printOnConsole(double min, double max, int count);
void convertToAmps12BitSesnor(double currentInputSamples[],int sampleSize);
void convertToAbsAmps10BitSesnor(double currentInputSamples[],int sampleSize);


