# 1 "test/codegen_milestone/fncall.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "test/codegen_milestone/fncall.c"
int fn(int a, int b, int c, int d, int e, int f, int g);


int fncall(int a, int b, int c, int d, int e, int f, int g)
{
   return fn(a, b, c, d, e, f, g);
}
# 1 "test/codegen_milestone/input/add.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "test/codegen_milestone/input/add.c"
int f(int a, int b){
 int d=50, e=10, c=e+d;
 return c;
}
