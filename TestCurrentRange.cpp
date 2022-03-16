#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "getCurrentRangeAndOccurence.h"


TEST_CASE("Infers the Current Ranges and their occurence") {
  int testCurrentInputSamples1[] = {7,5,8,6,4,12,10,11,20,22};
  int expectedConsecutiveSamples1 = 4;
  size_t sampleSize1 = sizeof(testCurrentInputSamples1)/sizeof(testCurrentInputSamples1[0]);
  struct intrepetedData dataInterpreted[sampleSize1];
  void (*fn_ptrPrintOutput)(int, int, int);
  fn_ptrPrintOutput = &printOnConsole;
  int intrepetedConsecutiveSamples1 = getCurrentRangeAndOccurence(testCurrentInputSamples1,sampleSize1,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(expectedConsecutiveSamples1 == intrepetedConsecutiveSamples1);
  intrepetedData expectedData[sampleSize1] = {
    {4,8,5},
    {10,12,3},
    {20,20,1},
    {22,22,1}
  };
  for(int i=0; i<(int)sampleSize1; i++) {
    assert(dataInterpreted[i].Min == expectedData[i].Min);
    assert(dataInterpreted[i].Max == expectedData[i].Max);
    assert(dataInterpreted[i].Size == expectedData[i].Size);
  }
  
  int testCurrentInputSamples2[] = {6,-3,7,9,10,12};
  int expectedConsecutiveSamples2 = 0;
  size_t sampleSize2 = sizeof(testCurrentInputSamples2)/sizeof(testCurrentInputSamples2[0]);
  int intrepetedConsecutiveSamples2 = getCurrentRangeAndOccurence(testCurrentInputSamples2,sampleSize2,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(expectedConsecutiveSamples2 == intrepetedConsecutiveSamples2);
}
