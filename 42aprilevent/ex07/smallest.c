#include<stdio.h>
int main(int c,char**v){while(*++v)printf("%s%s",*v,*(v+1)?" ":"");}
