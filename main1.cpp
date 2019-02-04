#include <iostream>
#include "functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double nx = 6;
	double ny = 6;
	double dx = 5;
	double dy = 1;
	
	signal(nx, ny, dx, dy);
	return 0;
}
