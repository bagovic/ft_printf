#include "ft_printf.h"
#include <fcntl.h>
#include <dlfcn.h>
#include <stdio.h>

void* malloc(size_t sz)
{
	static int count = -1;
    void *(*libc_malloc)(size_t) = dlsym(RTLD_NEXT, "malloc");
	void *p = libc_malloc(sz);
    printf("%i malloc (%p)\n", ++count, p);
    return p;
}

void free(void *p)
{
	static int count = -1;
    void (*libc_free)(void*) = dlsym(RTLD_NEXT, "free");
    printf("%i free (%p)\n", ++count,p);
    libc_free(p);
}

int main()
{
	ft_printf("%x", 9223372036854775807LL);
}
