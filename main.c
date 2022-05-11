#include "contref.h"

int main()
{
    GC refs = init();
    int *v, *w, *y = NULL;
    v = (int *)malloc2(refs, sizeof(int));
    *v = 10;
    w = (int *)malloc2(refs, sizeof(int));
    *w = 20;
    dump(refs);
    puts("");
    y = attrib(refs, y, w);
    dump(refs);
    puts("");
    y = attrib(refs, y, NULL);
    dump(refs);
    puts("");
    w = attrib(refs, w, NULL);
    dump(refs);
    puts("");
    v = attrib(refs, v, NULL);
    dump(refs);
    puts("");
    refs = dealloc(refs);
    return 0;
}
