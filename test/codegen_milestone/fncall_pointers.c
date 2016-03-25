int fn(int a, int b, int* c, int d, int e, int f, int* g);


int fncall(int a, int b, int* c, int d, int* e, int f, int g)
{
   return fn(a, b, c, g, *e, f, &d);
}
