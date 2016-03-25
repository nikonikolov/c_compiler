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
