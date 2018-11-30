#include "printf.h"

int main(void) {
	int a = ft_printf("%.30Lf\n", 15.1);
	int b = printf("%.30Lf\n", 15.1);
	printf("%d, %d\n", a, b);
	return 0;
}
