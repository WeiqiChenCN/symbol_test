#include <stdio.h>

extern void func();

#define DISABLE_OTHER_FUNC 0

#if ! DISABLE_OTHER_FUNC

void other_func(){
	printf("[%s] from [%s] is be called.\n", __func__, __FILE__ );
}

#else


#endif

int main( int argc, char argv ){
	printf( "calling func() from [%s].\n", __FILE__ );
	func();
#if ! DISABLE_OTHER_FUNC
	printf( "calling other_func() from [%s].\n", __FILE__ );
	other_func();
#else

#endif
	return 0;
}
