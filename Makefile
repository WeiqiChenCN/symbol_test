
.PHONY : all

all : test1 test2 libb-3.so libb-4.so


test1 : a.o libb-1.so
	gcc -o $@ a.o -L. -lb-1 -ldl

test2 : a.o libb-2.so
	gcc -o $@ a.o -L. -lb-2 -ldl


libb-1.so : b.o libcshared.so
	gcc -shared -fPIC -o $@ b.o -L$(shell pwd) -lcshared


libb-2.so : b.o libcstatic.a
	gcc -shared -fPIC -o $@ b.o -L$(shell pwd) -lcstatic

libb-3.so : b.o libcshared.so
	gcc -shared -fPIC -o $@ b.o -L$(shell pwd) -lcshared

libb-4.so : b.o libcstatic.a
	gcc -shared -fPIC -o $@ b.o -L$(shell pwd) -lcstatic

libcshared.so : c.o
	gcc -shared -fPIC -o $@ $<

libcstatic.a : c.o
	ar rcs $@ $<


a.o : a.c
	gcc  -c $< -o $@


b.o : b.c
	gcc -fPIC -c $< -o $@

c.o : c.c
	gcc -fPIC -c $< -o $@

.PHONY : clean

clean : 
	-rm *.o *.so *.a test1 test2
