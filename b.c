
#include <stdio.h>

extern void other_func();

void func(){
	printf("[%s] from [%s] is be called.\n", __func__, __FILE__ );
	printf( "calling other_func() from [%s].\n", __FILE__ );
	other_func();
}
