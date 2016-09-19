#include <stdio.h>

void a(){
	printf( "main.c\n" );
}

void func1();
void func2();

int main(){
	func1();
	func2();
	return 0;
}
