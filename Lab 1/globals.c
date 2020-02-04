// globals.c
// ENCM 369 Winter 2019 Lab 1 Exercise B

void copy(int *dest, const int *src, int n)
{
  int k;
  for (k = 0; k < n; k++)
    dest[k] = src[k];

  // point one (which is AFTER the loop is finished)

  return;
}

void reverse(int *dest, const int *src, int n)
{
  const int *guard;
  guard = src + n;
  dest += n;
  while (src != guard) {
    dest--;
    *dest = *src;

    // point two

    src++;
  }

  // point three
}

int aa[] = {1001, 2002, 3003, 4004};
int bb[5];
int cc = 500;

void update_cc(int z)
{
  cc += z;
}

int main(void)
{
  int dd[6];
  int ee[5] = {55, 44, 33, 22, 11}; 

  update_cc(20);
  copy(dd, aa, 4);
  update_cc(5);
  reverse(bb, ee, 5);
  update_cc(3);
  return 0;
}
