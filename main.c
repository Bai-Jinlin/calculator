#include <stdio.h>
#include <stdlib.h>
#define mal (struct Calentry)malloc(sizeof(struct Calentry));
struct Calentry
{
    float value;
    char sym;
    struct Calentry * prev;
    struct Calentry * next;

}
struct Calentry * head;
void foo(const char *in)
{
    head=mal;
}
int main()
{
    head=null;
}