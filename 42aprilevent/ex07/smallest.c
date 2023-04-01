#include <stdio.h>
int main(int c,char**v){if(c==3)while(*++v)printf("%s%s",*v,*(v+1)?" ":"");}