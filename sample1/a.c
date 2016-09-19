#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


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
	//Now, Try dlopen()
	printf( "=========dlopen stuff========\n" );
	void *handle;
	char *error;
	void (*dlfunc)(); 
	handle = dlopen( "libb-3.so", RTLD_LAZY );
	if( NULL==handle ){
		fprintf( stderr, "%s\n", dlerror() );
		return 1;
	}
	dlerror();

	dlfunc = dlsym( handle, "func" );
	if( NULL != (error = dlerror()) ){
		fprintf( stderr, "%s\n", error );
		return 1;
	}
	printf( "calling dlfunc to call 'func'.\n" );
	dlfunc();

	dlfunc = dlsym( handle, "other_func" );
	if( NULL != (error = dlerror()) ){
		fprintf( stderr, "%s\n", error );
		return 1;
	}
	printf( "calling dlfunc to call 'other_func'.\n" );
	dlfunc();

	printf( "=========dlopen stuff========\n" );
	handle = dlopen( "libb-4.so", RTLD_LAZY );
	if( NULL==handle ){
		fprintf( stderr, "%s\n", dlerror() );
		return 1;
	}
	dlerror();

	dlfunc = dlsym( handle, "func" );
	if( NULL != (error = dlerror()) ){
		fprintf( stderr, "%s\n", error );
		return 1;
	}
	printf( "calling dlfunc to call 'func'.\n" );
	dlfunc();

	dlfunc = dlsym( handle, "other_func" );
	if( NULL != (error = dlerror()) ){
		fprintf( stderr, "%s\n", error );
		return 1;
	}
	printf( "calling dlfunc to call 'other_func'.\n" );
	dlfunc();

	return 0;
}
