#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "getCurrentRangeAndOccurence.h"


TEST_CASE("Infers the Current Ranges and their occurence") {
  int testCurrentInputSamples[] = {7,5,8,6,4,12,10,11,20,22};
  size_t sampleSize = sizeof(testCurrentInputSamples)/sizeof(testCurrentInputSamples[0]);
  struct intrepetedData dataInterpreted[sampleSize];
  void (*fn_ptrPrintOutput)(int, int, int);
  fn_ptrPrintOutput = &printOnConsole;
  int expectedConsecutiveSamples = getCurrentRangeAndOccurence(testCurrentInputSamples,sampleSize,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(expectedConsecutiveSamples == 4);
  
  int testCurrentInputSamples1[] = {6,-3,7,9,10,12};
  size_t sampleSize1 = sizeof(testCurrentInputSamples1)/sizeof(testCurrentInputSamples1[0]);
  int expectedConsecutiveSamples1 = getCurrentRangeAndOccurence(testCurrentInputSamples1,sampleSize1,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(expectedConsecutiveSamples1 == 0);
}
