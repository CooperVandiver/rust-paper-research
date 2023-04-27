#include <stdio.h>
#include <stdlib.h>

#include "err.h"

void errx(int code, const char *err) {
	fprintf(stderr, "%s\n", err);
	exit(code);
}

