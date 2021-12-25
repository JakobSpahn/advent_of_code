#include <stdio.h>
#include <stdint.h>

//compile with gcc -03 x.c -ox
//decompile with ghidra

#define add(a,b) (a) += (b)
#define mul(a,b) (a) *= (b)
#define div(a,b) (a) /= (b)
#define mod(a,b) (a) %= (b)
#define eql(a,b) (a) = ((a)==(b))
#define inp(a) 	 (a) = (input[i++])

unsigned input[14];

int main(void) {
	long x, y, z, w;
	int i;

	for (int zzz = 0; zzz < 14; zzz++)
		scanf("%u", input + zzz);

	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,1);
	add(x,11);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,8);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,1);
	add(x,14);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,13);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,1);
	add(x,10);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,2);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,26);
	add(x,0);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,7);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,1);
	add(x,12);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,11);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,1);
	add(x,12);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,4);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,1);
	add(x,12);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,13);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,26);
	add(x,-8);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,13);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,26);
	add(x,-9);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,10);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,1);
	add(x,11);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,1);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,26);
	add(x,0);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,2);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,26);
	add(x,-5);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,14);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,26);
	add(x,-6);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,6);
	mul(y,x);
	add(z,y);
	inp(w);
	mul(x,0);
	add(x,z);
	mod(x,26);
	div(z,26);
	add(x,-12);
	eql(x,w);
	eql(x,0);
	mul(y,0);
	add(y,25);
	mul(y,x);
	add(y,1);
	mul(z,y);
	mul(y,0);
	add(y,w);
	add(y,14);
	mul(y,x);
	add(z,y);

	printf("z: %ld\n", z);
}
