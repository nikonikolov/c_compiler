int glob1=10;
int glob2=67;
int glob3=80;
int fn(int a, int b, int *c, int d, int e, int f, int *g){
 	if(b) return b;
 	else if(*g) return *g;
 	else return *c;
}
