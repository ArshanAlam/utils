/**
 *  Author: Arshan Alam
 *
 *  Date:   20161011
 *
 *  Description:  This application serves as a simple CLI calculator.
 *  This calculator supports basic arithmetics (+, -, x, /), using double
 *  precision floating point numbers.
 *
 *  Note: The asterisk (*) symbol is 'NOT' used for multiplication because
 *  it conflicts with BASH syntax, where executing *, serves as a wildcard.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Error Codes:
 *
 * 0  : Successfully execution
 * 1  : No Arguments
 * 2  : No operational values (No terms provided)
 *
 */
 enum ErrorCodes {
   SUCCESSFUL = 0,
   NO_ARGS = 1,
   NO_TERMS = 2
 };


int main(int argc, const char ** argv) {
  if (argc <= 0) {
    return NO_ARGS;
  } else if (argc == 1) {
    return NO_TERMS;
  }

  /*
   *  The first string in argv is the name of the program
   *  and the second string is the operational symbol
   */
  int numNonTermArgv = 2;
  int numTerms = argc - numNonTermArgv;
  double terms[numTerms];
  double result;
  const char * op = argv[1];

  for(int i = 0; i < numTerms; i++) {
    terms[i] = strtod(argv[i + numNonTermArgv], NULL);
  }

  // Set result to be the first term (for now)
  result = terms[0];
  for(int i = 1; i < numTerms; i++) {
    if (strcmp(op,"+") == 0) {
      result += terms[i];
    } else if(strcmp(op,"-") == 0) {
        result -= terms[i];
    } else if(strcmp(op,"x") == 0) {
        result *= terms[i];
    } else if(strcmp(op,"/") == 0) {
        result /= terms[i];
    }
  }

  printf("%lf\n", result);

  return SUCCESSFUL;
}
