/* 
 * CS:APP Data Lab 
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    /*
     *  For arbitrary non-zero integer x, the sign of -x (negative of x)
     *      and the sign of x are different.
     *  Only 0 has the same sign.
     */
    int negx = ~ x + 1;
    //  Check if the two signs are the same
    int sign = (x | negx) >> 31;
    /*
     *  In the previous line, we get:
     *      -1  if the two signs are different
     *      0   if the two signs are the same
     *  To return in the correct form, we need to add it by 1.
     */
    return sign + 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    //  0x55555555: 0101 0101 0101 0101 0101 0101 0101 0101
    int mask1_0 = 0x55;
    int mask1_1 = (mask1_0 << 8) + 0x55;
    int mask1_2 = (mask1_1 << 8) + 0x55;
    int mask1 = (mask1_2 << 8) + 0x55;
    //  0x33333333: 0011 0011 0011 0011 0011 0011 0011 0011
    int mask2_0 = 0x33;
    int mask2_1 = (mask2_0 << 8) + 0x33;
    int mask2_2 = (mask2_1 << 8) + 0x33;
    int mask2 = (mask2_2 << 8) + 0x33;
    //  0x0F0F0F0F: 0000 1111 0000 1111 0000 1111 0000 1111
    int mask3_0 = 0x0F;
    int mask3_1 = (mask3_0 << 8) + 0x0F;
    int mask3_2 = (mask3_1 << 8) + 0x0F;
    int mask3 = (mask3_2 << 8) + 0x0F;  //  18
//  0x00ff00ff: 0000 0000 1111 1111 0000 0000 1111 1111
//    int mask4 = (0xFF << 16) + 0xFF;
//    int mask5 = (0xFF << 8) + 0xFF; //  22

    int count1 = (mask1 & x) + (mask1 & (x >> 1));
    int count2 = (mask2 & count1) + (mask2 & (count1 >> 2));
    int count3 = (mask3 & count2) + (mask3 & (count2 >> 4));    //  30
//    int count4 = (mask4 & count3) + (mask4 & (count3 >> 8));
//    int count = (mask5 & count4) + (mask5 & (count4 >> 16));
    int count4 = count3 + (count3 >> 8);
    int count = count4 + (count4 >> 16);    //  34
    
    return (count & 0x3F); //  35
}

 
/*
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
    /*
     *  Apply basic logic: x or y is logically equivalent to not (not x and not y)
     *      In this case, we can use ~ and & to interpret |
     */
    return ~(~x & ~y);
}
/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */
int bitRepeat(int x, int n) {
    
    /*  Worst case senario: 1 -> 2 -> 4 -> 8 -> 16
     *      Initial stage: get the sequence that should be repeated
     *  Grab the numbers by applying a mask
     *      Assume n, then the mask should be like 000...011..1 with last n bits be 1.
     *      (mask & x) to get the number sequence that we want to repeat
     */
    
    int mask = ~(((-1) << (n - 1)) << 1);
    int x_0 = mask & x;  //  6
    
    //  Parsing
    //  n equals to 32, we actually don't need to repeat any thing.
    //      Otherwise, 16 <= n < 32.
    int isLarger32 = (n - 32) >> 31;
    int x_1 = x_0 + ((x_0 & isLarger32) << (n & isLarger32));   //  6
    
    //  8 <= n < 16?
    int n_2 = n*2;
    int isLarger16 = (n_2 - 32) >> 31;
    int x_2 = x_1 + ((x_1 & isLarger16) << (n_2 & isLarger16)); //  6
    
    //  4 <= n < 8?
    int n_3 = n*4;
    int isLarger8 = (n_3 - 32) >> 31;
    int x_3 = x_2 + ((x_2 & isLarger8) << (n_3 & isLarger8));   //  6
    
    //  2 <= n < 4?
    int n_4 = n*8;
    int isLarger4 = (n_4 - 32) >> 31;
    int x_4 = x_3 + ((x_3 & isLarger4) << (n_4 & isLarger4));   //  6
    
    //  1 <= n < 2?
    int n_5 = n*16;
    int isLarger2 = (n_5 - 32) >> 31;
    int x_5 = x_4 + ((x_4 & isLarger2) << (n_5 & isLarger2));   //  6
    
    return x_5;
}
/*
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    /*
     *  If x cannot be represented as n-bit, two's complement integer, it means:
     *      After appling two's complement, some of the bits in x are changed.
     *  Check if two sets of bits are exactly the same.
     */
    int bit_shift = 32 + (~n + 1);  //  ?
    int x_temp = x << bit_shift;
    int x_mask = x_temp >> bit_shift;
    return !(x ^ x_mask);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    //  find the number of bits that need to be shifted
    int bit_shift = n << 3;
    int mask = 0xFF;    //  1111 1111 to grab numbers
    return (x >> bit_shift) & mask;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    //  First bits <=> the signs of x and y
    int first_x = (x >> 31) & 1;  //  000...0     000...1
    int first_y = (y >> 31) & 1;  //  000...0     000...0
    int isSame = !(x^y);
    int isDiff = first_x ^ first_y;     //  000...0     000...1
    int sign_subtract = ((x + ~y + 1) >> 31) + 1; //  x <= y, 0; x > y, 1
    return isSame | (isDiff & first_x) | (!isDiff & !sign_subtract);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    int mask = 1 << 31;     /*  get 1000 ... 0000 to check if the first bit is 1 or 0   */
    int neg =  mask & x;    /*  If x is negative, neg will be 1000...0000
                             *  If x is nonnegative, neg will be 0000...0000
                             *      Need to exclude the case where x = 0                */
    return !(neg ^ (!x));
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    //  After the arithematic shift, & mask = 00...011...1
    int ari_shift_x = x >> n;
    int mask = ~(((1 << 31) >> n) << 1);
    return ari_shift_x & mask;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    //  0x80000000 = -2147483648
    //  1000 0000 0000 0000 0000 0000 0000 0000
    return 1 << 31;
}
