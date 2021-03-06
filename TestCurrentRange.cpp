#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "getCurrentRangeAndOccurence.h"

TEST_CASE("Infers the Current Ranges and their occurence for 12 bit Sensor - valid case") {
  double testCurrentInputSamples1[] = {535,1130,700,2000,2566,4094,2999,3333};
  int expectedConsecutiveSamples1 = 3;
  size_t sampleSize1 = sizeof(testCurrentInputSamples1)/sizeof(testCurrentInputSamples1[0]);
  struct intrepetedData dataInterpreted[sampleSize1];
  void (*fn_ptrPrintOutput1)(double, double, int);
  fn_ptrPrintOutput1 = &printOnConsole;
  int intrepetedConsecutiveSamples1 = getCurrentRangeAndOccurence(testCurrentInputSamples1,sampleSize1,dataInterpreted,fn_ptrPrintOutput1,Sensor12Bit);
  REQUIRE(expectedConsecutiveSamples1 == intrepetedConsecutiveSamples1);
  intrepetedData expectedData1[sampleSize1] = {
    {1,3,3},
    {5,8,4},
    {10,10,1}
  };
  for(int i=0; i<(int)expectedConsecutiveSamples1 ; i++) {
    REQUIRE(dataInterpreted[i].Min == expectedData1[i].Min);
    REQUIRE(dataInterpreted[i].Max == expectedData1[i].Max);
    REQUIRE(dataInterpreted[i].Size == expectedData1[i].Size);
  }
}

TEST_CASE("Infers the Current Ranges and their occurence for 12 bit Sensor - Invalid case(Negative sample)") {
  double testCurrentInputSamples2[] = {535,1130,-700,2000,2566,4094,2999,3333};
  int expectedConsecutiveSamples2 = 0;
  size_t sampleSize2 = sizeof(testCurrentInputSamples2)/sizeof(testCurrentInputSamples2[0]);
  struct intrepetedData dataInterpreted[sampleSize2];
  void (*fn_ptrPrintOutput2)(double, double, int);
  fn_ptrPrintOutput2 = &printOnConsole;
  int intrepetedConsecutiveSamples2 = getCurrentRangeAndOccurence(testCurrentInputSamples2,sampleSize2,dataInterpreted,fn_ptrPrintOutput2,Sensor12Bit);
  REQUIRE(expectedConsecutiveSamples2 == intrepetedConsecutiveSamples2);
}

TEST_CASE("Infers the conversion to Amps for 12bit sensor") {
  double adcOutput12bit[] = {4094,1196,1233,3453,0,1111,3210};
  size_t sampleSize3 = sizeof(adcOutput12bit)/sizeof(adcOutput12bit[0]);
  convertToAmps12BitSesnor(adcOutput12bit,sampleSize3);
  double expectedDataADC12bit[] = {10,3,3,8,0,3,8};
  for(int i=0; i<(int)sampleSize3; i++) {
    REQUIRE(adcOutput12bit[i] == expectedDataADC12bit[i]);
  }
}

TEST_CASE("Infers the Current Ranges and their occurence for 12 bit Sensor - Invalid case(max value assigned)") {
  double testCurrentInputSamples3[] = {535,1130,700,4095,2566,4094,2999,3333};
  int expectedConsecutiveSamples3 = 0;
  size_t sampleSize4 = sizeof(testCurrentInputSamples3)/sizeof(testCurrentInputSamples3[0]);
  struct intrepetedData dataInterpreted[sampleSize4];
  void (*fn_ptrPrintOutput3)(double, double, int);
  fn_ptrPrintOutput3 = &printOnConsole;
  int intrepetedConsecutiveSamples3 = getCurrentRangeAndOccurence(testCurrentInputSamples3,sampleSize4,dataInterpreted,fn_ptrPrintOutput3,Sensor12Bit);
  REQUIRE(expectedConsecutiveSamples3 == intrepetedConsecutiveSamples3);
}

TEST_CASE("Infers the conversion to Absolute Amps for 10bit sensor") {
  double adcOutput10bit[] = {0,1022,511,238,68,820,1000};
  size_t sampleSize5 = sizeof(adcOutput10bit)/sizeof(adcOutput10bit[0]);
  convertToAbsAmps10BitSesnor(adcOutput10bit,sampleSize5);
  double expectedDataADC10bit[] = {15,15,0,8,13,9,14};
  for(int i=0; i<(int)sampleSize5; i++) {
    REQUIRE(adcOutput10bit[i] == expectedDataADC10bit[i]);
  }
}

TEST_CASE("Infers the Current Ranges and their occurence for 10 bit Sensor - valid case") {
  double testCurrentInputSamples4[] = {925,380,720,200,900,120,0,400,1022,860,825,680};
  int expectedConsecutiveSamples4 = 3;
  size_t sampleSize6 = sizeof(testCurrentInputSamples4)/sizeof(testCurrentInputSamples4[0]);
  struct intrepetedData dataInterpreted[sampleSize6];
  void (*fn_ptrPrintOutput4)(double, double, int);
  fn_ptrPrintOutput4 = &printOnConsole;
  int intrepetedConsecutiveSamples4 = getCurrentRangeAndOccurence(testCurrentInputSamples4,sampleSize6,dataInterpreted,fn_ptrPrintOutput4,Sensor10Bit);
  REQUIRE(expectedConsecutiveSamples4 == intrepetedConsecutiveSamples4);
  intrepetedData expectedData4[sampleSize6] = {
    {3,6,4},
    {9,12,6},
    {15,15,2}
  };
  for(int i=0; i<(int)expectedConsecutiveSamples4 ; i++) {
    REQUIRE(dataInterpreted[i].Min == expectedData4[i].Min);
    REQUIRE(dataInterpreted[i].Max == expectedData4[i].Max);
    REQUIRE(dataInterpreted[i].Size == expectedData4[i].Size);
  }
}

TEST_CASE("Infers the Current Ranges and their occurence for 12 bit Sensor - Invalid case(Maximum sample)") {
  double testCurrentInputSamples5[] = {925,380,720,200,900,120,1023,400,1022,860,825,680};
  int expectedConsecutiveSamples5 = 0;
  size_t sampleSize7 = sizeof(testCurrentInputSamples5)/sizeof(testCurrentInputSamples5[0]);
  struct intrepetedData dataInterpreted[sampleSize7];
  void (*fn_ptrPrintOutput5)(double, double, int);
  fn_ptrPrintOutput5 = &printOnConsole;
  int intrepetedConsecutiveSamples5 = getCurrentRangeAndOccurence(testCurrentInputSamples5,sampleSize7,dataInterpreted,fn_ptrPrintOutput5,Sensor10Bit);
  REQUIRE(expectedConsecutiveSamples5 == intrepetedConsecutiveSamples5);
}
