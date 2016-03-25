int glob1=10;
int glob2=67;
int glob3=80;
int a=57;
int fn(int a, int b, int c, int d, int e, int f, int g){
	int* ptr;
	int var=10;
	ptr=&(*(&var));
	*ptr=50;
  	return var;
}
