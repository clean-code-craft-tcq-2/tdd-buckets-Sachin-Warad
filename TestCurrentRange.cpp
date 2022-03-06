#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "getCurrentRangeAndOccurence.h"


TEST_CASE("Infers the Current Ranges and their occurence") {
  int testCurrentInputSamples[] = {7,4,6,5};
  int sampleSize,result;
  sampleSize = sizeof(testCurrentInputSamples)/sizeof(testCurrentInputSamples[0]);
  const char* expectedinterpretation = "4-7, 4";
  char* intrepretedRange;
  intrepretedRange = getCurrentRangeAndOccurence(testCurrentInputSamples,sampleSize);
  result = strcmp(intrepretedRange, expectedinterpretation);
  REQUIRE(result == 0);
}
