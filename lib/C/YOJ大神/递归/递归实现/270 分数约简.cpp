//辗转相处
int mmn(int a,int b){
	if(b==0) return a;
	return mmn(b,a%b);
}
//辗转相除