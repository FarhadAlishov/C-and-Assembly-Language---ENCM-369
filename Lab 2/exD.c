// exD.c
// ENCM 369 Winter 2019 Lab 2 Exercise D
//
// INSTRUCTIONS
//   Your overall goal is to translate this program into MARS
//   assembly language.  Proceed using the following steps:
//
//   1. Make sure you know what this C program does.  If you're not
//      sure, add calls to printf.
//
//   2. Translate the program to Goto-C.  If you're not sure your
//      translation is correct, add calls to printf. 
//
//   3. Write down a list of local variables and the registers
//      you need for them.  (You will later type this in as
//      a comment in your MARS source code.)   
//
//   4. Using the products of Steps 2 and 3, write a MARS translation
//      of this program, in a file called exD.asm.  Use comments (a)
//      to describe allocation of local variables to s-registers and
//      (b) to explain what each MARS instruction does.
//
//      Your MARS code must closely match the C code.  In particular,
//      the translation of the for loop should should include
//      generation of the address of foo[j] by adding 4 times j to the
//      address of foo[0], and the translation of the do/while loop
//      should use pointer arithmetic.
//
//   5. Test your translation using MARS.


int foo[8] = {0xd3, 0xe3, 0xf3, 0xc3, 0x83, 0x93, 0xa3, 0xb3};
int bar[8] = {0x80, 0x70, 0x60, 0x50, 0x40, 0x30, 0x30, 0x10};

int main(void)
{
  int *p;
  int *q;
  int *stop;
  int max, j;

  // Put value of largest element of foo into min.
  max = foo[0];
  for (j = 1; j < 8; j++)
    if (foo[j] > max)
      max = foo[j];

  // Copy elements from bar to foo in reverse order,
  // writing over the initial values in foo.
  p = bar;
  q = foo + 8;
  stop = p + 8;
  do {
    q--;
    *q = *p;
    p++;
  } while (p != stop);
  
  return 0;
}
