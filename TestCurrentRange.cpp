#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "getCurrentRangeAndOccurence.h"


TEST_CASE("Infers the Current Ranges and their occurence") {
  int testCurrentInputSamples[] = {4,5,6};
  int result;
  const char* expectedinterpretation = "4-6, 3";
  char* intrepretedRange;
  intrepretedRange = getCurrentRangeAndOccurence(testCurrentInputSamples);
  result = strcmp(intrepretedRange, expectedinterpretation);
  REQUIRE(result == 0);
}
