# 1 "test/codegen_milestone/fncall_pointers.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "test/codegen_milestone/fncall_pointers.c"
int fn(int a, int b, int* c, int d, int e, int f, int* g);


int fncall(int a, int b, int* c, int d, int* e, int f, int g)
{
   return fn(a, b, c, g, *e, f, &d);
}
# 1 "test/codegen_milestone/input_pointers/fullconditional.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "test/codegen_milestone/input_pointers/fullconditional.c"
int glob1=10;
int glob2=67;
int glob3=80;
int fn(int a, int b, int *c, int d, int e, int f, int *g){
  if(b) return b;
  else if(*g) return *g;
  else return *c;
}
