// exG.c
// ENCM 369 Winter 2019 Lab 1 Exercise G

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ABS_F (5.0e-12)
#define POLY_DEGREE 4

double polyval(const double *a, int n, double x);
// Return a[0] + a[1] * x + ... + a[n] * pow(x, n).

int main(void)
{
    double f[ ] = {1.5, 0.7, -3.1, -1.2, 1.0};
    double dfdx[POLY_DEGREE];

    double guess;
    int max_updates;
    int update_count;
    int scan_count;
    int i;
    int close_enough = 0;
    
    double current_x, current_f, current_dfdx;

    printf("This program demonstrates use of Newton's Method to find\n"
           "approximate roots of the polynomial\nf(x) = ");
    printf("%.2f", f[0]);
    for (i = 1; i <= POLY_DEGREE; i++)
        if (f[i] >= 0)
            printf(" + %.2f*pow(x,%d)", f[i], i);
        else
            printf(" - %.2f*pow(x,%d)", -f[i], i);

    printf("\nPlease enter a guess at a root, and a maximum number of\n"
           "updates to do, separated by a space.\n");
    scan_count = scanf("%lf%d", &guess, &max_updates);
    if (scan_count != 2) {
        printf("Sorry, I couldn't understand the input.\n");
        exit(1);
    }
  
    if (max_updates < 0)  {
        printf("Sorry, a negative limit on updates does not make sense.\n");
        exit(1);
    }
    printf("Running with initial guess %f.\n", guess);

    for (i = POLY_DEGREE - 1; i >= 0; i--)
        dfdx[i] = (i + 1) * f[i + 1];   // Calculus!
    current_x = guess;
    update_count = 0;

    while (1) {
        current_f = polyval(f, POLY_DEGREE, current_x);
        printf("%d update(s) done; x is %.15f; f(x) is %.15e\n",
               update_count, current_x, current_f);

        if (fabs(current_f) < MAX_ABS_F) {
            close_enough = 1;
            break;
        }
        if (update_count == max_updates)
            break;

        current_dfdx = polyval(dfdx, POLY_DEGREE - 1, current_x);
        current_x -= current_f / current_dfdx;
        update_count++;
    }
        
    if (close_enough)
        printf("Stopped with approximate solution of %.12f.\n", 
               current_x);
    else
        printf("%d updates performed, |f(x)| still >= %g.\n", 
               update_count, MAX_ABS_F);
    return 0;
}

double polyval(const double *a, int n, double x)
{
    double result = a[n];
    int i;
    for (i = n - 1; i >= 0; i--)
        result = x * result + a[i];
    return result;
}
