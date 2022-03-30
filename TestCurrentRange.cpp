#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "getCurrentRangeAndOccurence.h"


TEST_CASE("Infers the Current Ranges and their occurence - valid case") {
  double testCurrentInputSamples1[] = {535,1130,700,2000,2566,4094,2999,3333};
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

TEST_CASE("Infers the Current Ranges and their occurence - Invalid case(Negative sample)") {
  double testCurrentInputSamples2[] = {535,1130,-700,2000,2566,4094,2999,3333};
  int expectedConsecutiveSamples2 = 0;
  size_t sampleSize2 = sizeof(testCurrentInputSamples2)/sizeof(testCurrentInputSamples2[0]);
  struct intrepetedData dataInterpreted[sampleSize2];
  void (*fn_ptrPrintOutput)(double, double, int);
  fn_ptrPrintOutput = &printOnConsole;
  int intrepetedConsecutiveSamples2 = getCurrentRangeAndOccurence(testCurrentInputSamples2,sampleSize2,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(expectedConsecutiveSamples2 == intrepetedConsecutiveSamples2);
}

TEST_CASE("Infers the conversion to Amps for 12bit sensor") {
  double adcOutput12bit[] = {4094,1196,1233,3453,0,1111,3210};
  size_t sampleSize3 = sizeof(adcOutput12bit)/sizeof(adcOutput12bit[0]);
  convertToAmps(adcOutput12bit,sampleSize3);
  double expectedDataADC[] = {10,3,3,8,0,3,8};
  for(int i=0; i<(int)sampleSize3; i++) {
    REQUIRE(adcOutput12bit[i] == expectedDataADC[i]);
  }
}

TEST_CASE("Infers the Current Ranges and their occurence - Invalid case(max value assigned)") {
  double testCurrentInputSamples3[] = {535,1130,700,4095,2566,4094,2999,3333};
  int expectedConsecutiveSamples3 = 0;
  size_t sampleSize3 = sizeof(testCurrentInputSamples3)/sizeof(testCurrentInputSamples3[0]);
  struct intrepetedData dataInterpreted[sampleSize3];
  void (*fn_ptrPrintOutput)(double, double, int);
  fn_ptrPrintOutput = &printOnConsole;
  int intrepetedConsecutiveSamples3 = getCurrentRangeAndOccurence(testCurrentInputSamples3,sampleSize3,dataInterpreted,fn_ptrPrintOutput);
  REQUIRE(expectedConsecutiveSamples3 == intrepetedConsecutiveSamples3);
}

TEST_CASE("Infers the conversion to Amps for 10bit sensor") {
  double adcOutput10bit[] = {0,1022,511,238,68,792,957};
  size_t sampleSize3 = sizeof(adcOutput10bit)/sizeof(adcOutput10bit[0]);
  convertToAmps(adcOutput10bit,sampleSize3);
  double expectedDataADC[] = {-15,15,0,-8,-13,9,14};
  for(int i=0; i<(int)sampleSize3; i++) {
    REQUIRE(adcOutput10bit[i] == expectedDataADC[i]);
  }
}
