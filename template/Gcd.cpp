//Gcd
int Gcd(int x, int y){
	return !y ? x : Gcd(y, x % y);
}

//Ex_Gcd
int Ex_Gcd(int &x, int &y, int &d, int a, int b){
	if(!y) d = 1, x = 1, y = 0;
	else Ex_Gcd(y, x, d, b, a%b), y -= x * (a / b);
}
