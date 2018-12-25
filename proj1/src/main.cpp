#include "sample.h"
#include <cstdio>

#ifndef DISABLE_MAIN
int main(int argc, char *argv[])
{
	std::printf("3 * 5 = %d\n", sample::sample2(3, 5));
	std::puts("Run OK");
	return 0;
}
#endif
