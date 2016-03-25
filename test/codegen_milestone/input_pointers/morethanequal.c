int glob1=10;
int glob2=67;
int glob3=80;
int a=57;
int fn(int a, int b, int *c, int d, int e, int f, int *g){
  return a>=b && *c>=d || e>=f || *g>=a || glob3>=glob2;
}
