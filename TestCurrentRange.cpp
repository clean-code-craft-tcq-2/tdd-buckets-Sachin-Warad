#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "getCurrentRangeAndOccurence.h"


TEST_CASE("Infers the Current Ranges and their occurence") {
  int testCurrentInputSamples[] = {7,5,8,6,4,12,10,11,20};
  size_t sampleSize = sizeof(testCurrentInputSamples)/sizeof(testCurrentInputSamples[0]);
  struct intrepetedData dataInterpreted[sampleSize];
  void (*fn_ptrPrintOutput)(int, int, int);
  fn_ptrPrintOutput = &printOnConsole;
  int expectedConsecutiveSamples = 3;
  int intrepretedConsecutiveSamples = getCurrentRangeAndOccurence(testCurrentInputSamples,sampleSize,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(intrepretedConsecutiveSamples == expectedConsecutiveSamples);
  intrepetedData expectedData[sampleSize] = {
    {4,8,5},
    {10,12,3},
    {20,20,1}
  };
  for(int i=0; i<(int)sampleSize; i++) {
    REQUIRE(dataInterpreted[i].Min == expectedData[i].Min);
    REQUIRE(dataInterpreted[i].Max == expectedData[i].Max);
    REQUIRE(dataInterpreted[i].Size == expectedData[i].Size);
  }
  
  int testCurrentInputSamples1[] = {6,-3,7,9,10,12};
  size_t sampleSize1 = sizeof(testCurrentInputSamples1)/sizeof(testCurrentInputSamples1[0]);
  int expectedConsecutiveSamples1 = getCurrentRangeAndOccurence(testCurrentInputSamples1,sampleSize1,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(expectedConsecutiveSamples1 == 0);
}
