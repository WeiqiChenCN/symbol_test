#include <stdio.h>
#include <dlfcn.h>

void a(){
	printf( "main.c\n" );
}

int main(){
	void *handler_1, *handler_2;
	handler_1 = dlopen( "liba.so", RTLD_LAZY );
	handler_2 = dlopen( "libb.so", RTLD_LAZY );
	if( handler_1 && handler_2 ){

	}else{
		fprintf( stderr, "Error when dlopen.\n" );
		return 1;
	}
	void(*func1)(void) = dlsym( handler_1, "func1" );
	void(*func2)(void) = dlsym( handler_2, "func2" );
	func1();
	func2();
	return 0;
}
