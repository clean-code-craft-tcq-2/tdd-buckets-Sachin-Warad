# Test Driven Ranges

The charging current varies during the process of charging.
We need to capture the range of current measurements -
what range of currents are most often encountered while charging.

> **DO NOT** jump into implementation! Read the example and the starting task below.

## Example

### Input

Consider a set of periodic current samples from a charging session to be:
`3, 3, 5, 4, 10, 11, 12`

### Functionality

The continuous ranges in there are: `3,4,5` and `10,11,12`.

The task is to detect the ranges and
output the number of readings in each range.

In this example,

- the `3-5` range has `4` readings
- the `10-12` range has `3` readings.

### Output

The expected output would be in comma-separated (csv format):

```
Range, Readings
3-5, 4
10-12, 3
```

## Tasks

Establish quality parameters: 

- What is the maximum complexity (CCN) per function? CCN = 4
- How many lines of duplicate code will you tolerate? Duplicate Lines = 3
- Ensure 100% line and branch coverage at every step. Include the coverage yml in the workflows.

Adapt/adopt/extend the `yml` files from one of your previous workflow folders.

Start Test-driven approach

1. Write the smallest possible failing test: give input `4,5`. assert output to be `4-5, 2`.
1. Write the minimum amount of code that'll make it pass.
1. Refactor any assumptions, continue to pass this test. Do not add any code without a corresponding test.

## Assumptions

1. For 12 bit sensor if the sample contains negative number or max i.e., 4095 then it is considered as invalid sample case and 0-0, 0 is printed
2. For 10 bit sensor if the sample contains maximmum value i.e., 1023 then it is considered as invalid sample case and 0-0, 0 is printed 
3. Input Samples can be either sorted or not

# Actions

1. Validate the Inputs
2. If inputs are valid then convert the ADC output to Amps, sort the smaples and intrepret the Ranges
3. Then display the intrepreted data in CSV format
4. If the inputs are not valid then return 0
