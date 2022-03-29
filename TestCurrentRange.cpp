#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "getCurrentRangeAndOccurence.h"


TEST_CASE("Infers the Current Ranges and their occurence - valid case") {
  double testCurrentInputSamples1[] = {535,700,1130,2000,2566,2999,3333,4094};
  int expectedConsecutiveSamples1 = 3;
  size_t sampleSize1 = sizeof(testCurrentInputSamples1)/sizeof(testCurrentInputSamples1[0]);
  struct intrepetedData dataInterpreted[sampleSize1];
  void (*fn_ptrPrintOutput)(double, double, int);
  fn_ptrPrintOutput = &printOnConsole;
  int intrepetedConsecutiveSamples1 = getCurrentRangeAndOccurence(testCurrentInputSamples1,sampleSize1,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(expectedConsecutiveSamples1 == intrepetedConsecutiveSamples1);
  intrepetedData expectedData[sampleSize1] = {
    {1,3,3},
    {5,8,4},
    {10,10,1}
  };
  for(int i=0; i<(int)expectedConsecutiveSamples1 ; i++) {
    REQUIRE(dataInterpreted[i].Min == expectedData[i].Min);
    REQUIRE(dataInterpreted[i].Max == expectedData[i].Max);
    REQUIRE(dataInterpreted[i].Size == expectedData[i].Size);
  }
}

TEST_CASE("Infers the Current Ranges and their occurence - Invalid case") {
  double testCurrentInputSamples2[] = {6,-3,7,9,10,12};
  int expectedConsecutiveSamples2 = 0;
  size_t sampleSize2 = sizeof(testCurrentInputSamples2)/sizeof(testCurrentInputSamples2[0]);
  struct intrepetedData dataInterpreted[sampleSize2];
  void (*fn_ptrPrintOutput)(double, double, int);
  fn_ptrPrintOutput = &printOnConsole;
  int intrepetedConsecutiveSamples2 = getCurrentRangeAndOccurence(testCurrentInputSamples2,sampleSize2,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(expectedConsecutiveSamples2 == intrepetedConsecutiveSamples2);
}

TEST_CASE("Infers the decryption of ADC") {
  double adcOutput[] = {4094,1196,1233,3453,0,1111,3210};
  size_t sampleSize3 = sizeof(adcOutput)/sizeof(adcOutput[0]);
  convertToAmps(adcOutput,sampleSize3);
  double expectedDataADC[] = {10,3,3,8,0,3,8};
  for(int i=0; i<(int)sampleSize3; i++) {
    REQUIRE(adcOutput[i] == expectedDataADC[i]);
  }
}
