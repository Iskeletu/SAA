## Exit Code 1:
  The function "vectorGenerator" has failed to fill a vector with integeres.

## Exit Code 2:
  The program has failed to create or open a .dat file, the means the program is unable to save the benchmark data.

## Exit Code 3:
  The main function passed an invalid sorting algorithm UUID (> 8 or < 0) to "benchmak" fuction.

## Exit Code 4:
  The "benchmark" function tried to generate a vector with a invalid UUID (> 3 or < 0).

## Exit Code 100:
  The benchmark result is invalid, beacuse the resulting vector is not sorted in a ascending order, indicates an error in the sorting algorithm.

## Exit Code 404:
  The program has failed to run "benchmark" function for any generic reason, should not happen without another exit error triggering first.
