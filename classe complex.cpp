#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
  
  using namespace std;

class complex{
	
	private:
		
		double re;
		double im;
	
	
	public:
		
	complex(double reel,double imaginaire=0){
		this->re=reel;
		this->im=imaginaire;
		
	}
	static double real(complex a1){
		return a1.re;
	}
	static double imag(complex a1){
		return a1.im;
	}
	static complex conj(complex a1){
		a1.im=a1.im*(-1);
		return a1;
	}
	static double norm(complex a1){
		return sqrt(pow(a1.re,2)+pow(a1.im,2));
		
	}
	static double arg(complex a1){
		double tmp=2*atan(a1.im/(a1.re+norm(a1)));
		return tmp;
	}
	
	static complex polar(double mag,double angle=0){
		complex n((double)(mag*cos(angle)),(double)(mag*sin(angle)));
		return n;
	}
	
	complex operator+(complex & c){
		complex tmp(real(*this)+real(c),imag(*this)+imag(c));
		return tmp;
	}
	
	friend complex operator+(double & n ,complex & c){		
		complex tmp(n+real(c),imag(c));
		return tmp;
	}
	
	friend complex operator+(complex & c,double & n){
		complex tmp(n+real(c),imag(c));
		return tmp;
	}
	
	complex operator-(complex & c){
		complex tmp(real(*this)-real(c),imag(*this)-imag(c));
		return tmp;
	}
	
	friend complex operator-(double & n ,complex & c){
		complex tmp(n-real(c),imag(c));
		return tmp;
	}
	
	friend complex operator-(complex & c,double & n){
		complex tmp(real(c)-n,imag(c));
		return tmp;
	}
	
	complex operator*(complex & c){
		complex tmp((real(*this)*real(c))-(imag(*this)*imag(c)),imag(c)*real(*this)+imag(*this)*real(c));
		return tmp;
	}

	friend complex operator*(complex & c,double & n){
		complex tmp(n*real(c),n*imag(c));return tmp;
	}

	friend complex operator*(double & n ,complex & c){
		complex tmp(n*real(c),n*imag(c));return tmp;		
	}
	
	complex operator/(complex & c){
		complex tmp(((real(*this)*real(c))+(imag(*this)*imag(c)))/(pow(real(c),2)+pow(imag(c),2)));
		return tmp;
	}
	
	friend complex operator/(complex & c,double & n){
		complex tmp(real(c)/n,imag(c)/n);return tmp;
	}
	
	friend complex operator/(double & n ,complex & c){
		complex tmp(real(c)/n,imag(c)/n);return tmp;
	}
	
 	bool  operator==(complex & a)
	{
    	if(real(*this)==real(a) && imag(*this)==imag(a))
    		return true;
    		return false;
	}
	
	bool operator!=(complex & a)
	{
    	if(real(a)==real(*this) && imag(a)==imag(*this))
    		return false;
    		return true;
	}
	
	complex operator-(){
		
		complex tmp(real(*this),(-1)*imag(*this));
		return tmp;
	}
	
	friend ostream &operator<<(ostream& ,complex & a);
	friend istream &operator>>(istream& ,complex & a);
};

ostream &operator<<(ostream& outt, complex &a){
	
	if(a.imag(a)==1){
		if(a.real(a)!=0)
			outt << a.real(a)<<"+"<<"i" ;
		else
			outt <<"i" ;
		return outt;
		}
	if(a.imag(a)==-1){
		if(a.real(a)!=0)
			outt << a.real(a)<<"-"<<"i" ;
		else
			outt <<"-"<<"i" ;
		return outt;
	}
	if(a.imag(a)>=1){
		if(a.real(a)!=0)
			outt << a.real(a)<<"+"<<a.imag(a)<<"i" ;
		else
			outt <<a.imag(a)<<"i";
		return outt;
	}
	if(a.imag(a)<0){
		if(a.real(a)!=0)	
			outt << a.real(a)<<a.imag(a)<<"i" ;
		else
				outt <<a.imag(a)<<"i";
		return outt;
	}
	if(a.imag(a)==0){
		if(a.real(a)!=0)	
			outt << a.real(a);
		else
			outt <<a.imag(a);
		return outt;
	}
}

istream& operator>>(istream& inn,complex &a){
	
	cout << "\n Inserer la partie reele ! ";
	inn >> a.re;
	cout << "\n Inserer la partie imaginaire ! ";
	inn >> a.im; 
	return inn;
}

	int main(){
		
		complex a(1,3);
		double pi=3.14,n=2;
		complex b=a.polar(n,pi/2);
		cout <<b<<"\n";	
		
	}
	

