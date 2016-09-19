
.PHONY : all

all : main main_opendl

main_opendl: main_opendl.o liba.so libb.so
	gcc -o $@ main_opendl.o -ldl

main : main.o liba.so libb.so
	gcc -o $@  main.o -L$(shell pwd) -la -lb


libcshared.so : c.o
	gcc -shared -fPIC -o $@ $<


liba.so : a.o
	gcc -shared -fPIC -o $@ $<
libb.so : b.o
	gcc -shared -fPIC -o $@ $<

a.o : a.c
	gcc -fPIC -c $< -o $@

b.o : b.c
	gcc -fPIC -c $< -o $@

main.o : main.c
	gcc -c $< -o $@

main_opendl.o : main_opendl.c

.PHONY : clean

clean : 
	-rm *.o *.so main main_opendl
