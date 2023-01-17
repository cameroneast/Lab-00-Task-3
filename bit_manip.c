#include <stdbool.h>

// Though the integers in C are typically 32-bit, it is not
// safe to assume as such, so your code should not assume
// that the integers are 32-bits. The driver code is written
// as such. The 'int' data type is an N-bit Two's Complement
// binary number, and the 'unsigned' data type is a regular
// N-bit binary number (no negatives). Again, N is likely 32,
// but you should not assume this in your code.

// The comments after each of these lines show what the
// underlying binary representation of these numbers look
// like. The first (leftmost) digits are given, and the dots
// represent a continuation of the last digit listed. These
// constants might be useful.
const unsigned UNS_MAX = (unsigned)(-1); // 1111...
const unsigned UNS_MIN = 0;              // 0000...
const int INT_MAX = UNS_MAX >> 1;        // 0111...
const int INT_MIN = ~INT_MAX;            // 1000...

// This function shoulud return a boolean value that is true
// if x is negative. You may only use bitwise operations,
// you cannot use any comparison operations. Remember, an int
// is automatically casted to bool using the rule if it's 0,
// it's false, otherwise it's true.
bool is_negative(int x) {
  if (INT_MIN & x)
    return true;
  return false; // remove this line
}

// This function should return a value that when printed out
// in binary (which has been provided to you), is the 32-bit
// two's complement of the input x. You may use any method
// you can come up with to do this, though the code should
// be concise.
int twos_complement(int x) { return UNS_MAX * x; }

// This function should return 10 times the input x. You must
// use both shift operations and addition, and nothing else.
// x+x+x+... will NOT be accepted.
int times_ten(int x) {
  x += (x << 3) + x;
  return x; // remove this line
}

/*************************************************
 *                                               *
 *  DO NOT MODIFY THE CODE BELOW FOR SUBMISSION  *
 *                                               *
 *************************************************/
// If this code is discovered to be maliciously modified
// at grading (e.g. making it always output 'TESTS PASSED'),
// you will recieve a 0 for the assignment.

// You may read this code if you want, but it is not necessary
// for the assignment

#include <stdio.h>

// Print out the integer x in binary
// Note, you will need to implement this function in a later
// lab, however you may not use this implementation (as it
// violates the limitations for how the function must be
// written).
void print_bin(int x) {
  unsigned divisor = INT_MIN;
  while (divisor > 0) {
    if ((x / divisor) > 0)
      printf("1");
    else
      printf("0");
    x -= (x / divisor) * divisor;
    divisor /= 2;
  }
}

void print_bool(int x) {
  if (x == 0)
    printf("false");
  else
    printf("true");
}

// This function is an implementation of the two's complement
// function. It is deliberately hyper-convoluted, and it
// is highly suggested that you ignore it to avoid unnecessary
// confusion. You may not copy this implementation or call
// this function in your solution.
//
// Note: it is much easier to actually implement the function
// than what is programmed here. Again, this is just written
// to check your solution without giving away the expected
// solution.
int a(int b) {
  int d, e, f, g;
  for (int c = 14411; (~c - c) != -1; c >>= 2) {
    d = (b ^ 0) ^ (~b | 0) ^ (b & (-1));
    e = c | 1;
    f = 1;
    while ((1 << f) > 1) {
      e |= (e << f);
      f <<= 1;
    }
    e = ~e;
    g = -~-~(-~-2);
    while (d & g) {
      e |= g;
      g <<= (~-~-3);
    }
    e |= g;
    b = d ^ e;
  }
  return b;
}

// This is the driver for the code
int main(void) {
  int x;
  printf("Input a number (1234 to exit): ");
  scanf("%d", &x);
  while (x != 1234) {
    printf("x Binary: ");
    print_bin(x);
    printf("\n");

    printf("\n");
    if (is_negative(x) != (x < 0))
      printf("FAILED");
    else
      printf("PASSED");
    printf(": IS NEGATIVE\n");
    printf("Expected: ");
    print_bool((x < 0));
    printf("\n");
    printf("     Got: ");
    print_bool(is_negative(x));
    printf("\n");

    printf("\n");
    if (twos_complement(x) != a(x))
      printf("FAILED");
    else
      printf("PASSED");
    printf(": TWO'S COMPLEMENT\n");
    printf("Expected: ");
    print_bin(a(x));
    printf("\n");
    printf("     Got: ");
    print_bin(twos_complement(x));
    printf("\n");

    printf("\n");
    if (times_ten((unsigned)x) != x * 10)
      printf("FAILED");
    else
      printf("PASSED");
    printf(": TIMES TEN\n");
    printf("Expected: ");
    print_bin(x * 10);
    printf(" (%d)\n", x * 10);
    printf("     Got: ");
    print_bin(times_ten(x));
    printf(" (%d)\n", times_ten(x));

    printf("\n");
    printf("Input a number (1234 to exit): ");
    scanf("%d", &x);
  }
}