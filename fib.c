#include <stdio.h>
#include "bn.h"

int main(void)
{
	struct bn a;
	bignum_from_int(&a, 0);
	struct bn b;
	bignum_from_int(&b, 1);
	char buf[65536];
	int counter = 0;
	while(counter < 94175 * 2)
	{
		counter++;
		//print a
		bignum_to_string(&a, buf, sizeof(buf));
		printf("Fib number %d: %s\n", counter, buf);
		//add b to a
		bignum_add(&a, &b, &a);

		counter++;
		//print b
		bignum_to_string(&b, buf, sizeof(buf));
		printf("Fib number %d: %s\n", counter, buf);
		//add a to b
		bignum_add(&a, &b, &b);
	}
}

