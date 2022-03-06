#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"


TEST_CASE("Infers the Current Ranges and their occurence") {
  int testCurrentInputSamples[] = {4,5};
  const char* expectedinterpretation = "4-5, 2";
  char* intrepretedRange;
  intrepretedRange = getCurrentRangeAndOccurence(currentInputSamples);
  REQUIRE(intrepretedRange == expectedinterpretation);
}
