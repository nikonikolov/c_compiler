int glob1=10;
int glob2=67;
int glob3=80;
int glob4=0;
int fn(int a, int b, int c, int d, int e, int f, int g){
 	if(a>0){
 		return fn(a-1,b,c,d,e,f,g);
 	}
 	else return glob3+1;
}
