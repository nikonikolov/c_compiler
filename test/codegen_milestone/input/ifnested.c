int glob1=10;
int glob2=67;
int glob3=80;
int glob4=0;
int fn(int a, int b, int c, int d, int e, int f, int g){
 	if(a){
 		if(a&&b) return glob1;
 	}
 	else if(b){
 		if(g||b) return glob2;
 	}
 	else if(c){
	 	return glob3;
 	} 
 	else if(d){
	 	if(glob4&glob2) return g;
 	} 
 	else if(e){
	 	if(glob2) return c;
 	} 
 	else if(f){
	 	if(glob4) return c;
	 	else if(g*glob1) return glob1;
 	} 
 	else if(g){
	 	if(glob4){
	 		return a*b;
	 	}
	 	else if(glob4*10){
	 		return a*b*g;
	 	}
	 	else return glob3;
 	} 
 	else return glob4;
}
