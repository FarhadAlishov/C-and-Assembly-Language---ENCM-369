// bin_and_hex.c
// ENCM 369 Winter 2019 Lab 4 Exercise E


#include <stdio.h>

 
void write_in_hex(char *str, unsigned int word);
// REQUIRES: str points to the beginning of an array of at least 12 elements.
// PROMISES: The base sixteen representation of word, with underscores 
//   separating groups of four hex digits, is written as a string in the array.
// NOTE: The function assumes that int is a 32-bit type.
    

void write_in_binary(char *str, unsigned int word);
// REQUIRES: str points to the beginning of an array of at least 40 elements.
// PROMISES: The base two representation of word, with underscores 
//   separating groups of four bits, is written as a string in the array.
// NOTE: The function assumes that int is a 32-bit type.

 
void test(unsigned int test_value);
// Function to test write_in_binary and write_in_hex.

int main(void)
{
  test(0x76543210);
  test(0x89abcdef);
  test(0);
  test(0xffffffff);
  return 0;
}

void test(unsigned int test_value)
{
  char str[40];
  write_in_hex(str, test_value);
  printf("%s\n", str);
  write_in_binary(str, test_value);
  printf("%s\n\n", str);
}


void write_in_hex(char *str, unsigned int word)
{
  char *digit_list;

  str[0] = '0';
  str[1] = 'x';
  str[6] = '_';
  str[11] = '\0';

  digit_list = "0123456789abcdef";

  str[2] = digit_list[(word >> 28) & 0xf];
  str[3] = digit_list[(word >> 24) & 0xf];
  str[4] = digit_list[(word >> 20) & 0xf];
  str[5] = digit_list[(word >> 16) & 0xf];

  str[7] = digit_list[(word >> 12) & 0xf];
  str[8] = digit_list[(word >> 8) & 0xf];
  str[9] = digit_list[(word >> 4) & 0xf];
  str[10] = digit_list[word & 0xf];
}


void write_in_binary(char *str, unsigned int word)
{
  int bn;                       // bit number within word
  unsigned int mask;            // pattern to isolate a single bit
  int index;                    // index into str
  int digit0, digit1, under;

  digit0 = '0';
  digit1 = '1';
  under = '_';

  str[39] = '\0';
  index = 38;
  mask = 1;            // in binary: [ 31 zeros ]_1
  while (1) {
    if ((word & mask) == 0)
      str[index] = digit0;
    else
      str[index] = digit1;
    index--;
    bn++;
    mask = mask << 1;
    if (bn == 32)
      break;
    if ((bn & 3) == 0) {  // if bn is a multiple of 4 ...
      str[index] = under;
      index--;
    }
  }
}
