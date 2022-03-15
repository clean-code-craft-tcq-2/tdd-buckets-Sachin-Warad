#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "getCurrentRangeAndOccurence.h"


TEST_CASE("Infers the Current Ranges and their occurence") {
  int testCurrentInputSamples[] = {7,5,8,6,4,12,10,11,20};
  size_t sampleSize = sizeof(testCurrentInputSamples)/sizeof(testCurrentInputSamples[0]);
  struct intrepetedData dataInterpreted[sampleSize];
  int expectedConsecutiveSamples = getCurrentRangeAndOccurence(testCurrentInputSamples,sampleSize,dataInterpreted);
  REQUIRE(expectedConsecutiveSamples == 3);
}
