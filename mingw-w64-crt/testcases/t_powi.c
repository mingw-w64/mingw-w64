#include <math.h>
#include <stdio.h>

int main(int argc, void **argv)
{
    int i;
    double x, x2, z = pow(10.0, 15);
    for(i =-300; i < -290; i++) {
	x = pow(10.0, i); x2 = pow(10.0, i-15);
	printf("%6g: %6g %6g\n", x, x2, x2 * z);
    }
}

