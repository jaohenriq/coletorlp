#include "contref.h"

struct ref
{
    void *ptr;
    unsigned int cont;
};

struct lista{
    struct ref *ptr;
    struct lista *prox;
};

struct gc{
    struct lista *refs;
};

struct lista* __init()
{
    return NULL;
}

bool vazio(struct lista* l)
{
    return l == NULL;
}

struct lista* _insere(struct lista* l, struct ref *info)
{
    struct lista *ret;
    ret = (struct lista*)malloc(sizeof(struct lista));
    ret->ptr = info;
    ret->prox = l;
    return ret;
}

struct lista* _remove(struct lista* l, void *info)
{
    struct lista *p, *t;
    struct ref *_;
    if(!vazio(l)){
        if(l->ptr->ptr == info){
            p = l->prox;
            _ = l->ptr;
            free(_->ptr);
            free(l);
            l = p;
        }else{
            for(p = l->prox, t = l, _ = p->ptr; p != NULL && _->ptr != info; t = p, p = p->prox);
            if(p != NULL){
                free(_->ptr);
                t->prox = p->prox;
                free(p);
            }
        }
    }
    return l;
}

struct gc* init()
{
    struct gc *ret = (struct gc*)malloc(sizeof(struct gc));
    ret->refs = __init();
    return ret;
}

void* malloc2(struct gc *mem, size_t tam)
{
    void *ptr = malloc(tam);
    struct ref *info = (struct ref*)malloc(sizeof(struct ref));
    info->cont = 1;
    info->ptr = ptr;
    mem->refs = _insere(mem->refs, info);
    return ptr;
}

void* attrib(struct gc *mem, void *orig, void *dest)
{
    struct lista *refs = mem->refs;
    struct lista *p;
    if(orig != NULL){
        for(p = refs; p != NULL && p->ptr->ptr != orig; p = p->prox);
        if(p != NULL){
            p->ptr->cont--;
            if(p->ptr->cont == 0){
                refs = _remove(refs, orig);
                mem->refs = refs;
            }
        }
    }
    if(dest != NULL){
        for(p = refs; p != NULL && p->ptr->ptr != dest; p = p->prox);
        if(p != NULL)
            p->ptr->cont++;
    }
    return dest;
}

void dump(GC mem)
{
    for(struct lista *l = mem->refs; l != NULL; l = l->prox){
        printf("Endereço: %p -> contagem: %u\n", l->ptr->ptr, l->ptr->cont);
    }
}

struct gc* dealloc(struct gc *mem)
{
    free(mem);
    return NULL;
}
