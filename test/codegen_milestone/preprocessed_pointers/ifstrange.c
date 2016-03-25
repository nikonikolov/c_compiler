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
# 1 "test/codegen_milestone/input_pointers/ifstrange.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "test/codegen_milestone/input_pointers/ifstrange.c"
int glob1=10;
int glob2=67;
int glob3=80;
int glob4=0;
int fn(int a, int b, int *c, int d, int e, int f, int *g){
  if(a){
   if(glob4) return *c;
  }
  else return b;
  return 0;
}
