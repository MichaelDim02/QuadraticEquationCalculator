#include <iostream>
#include <cmath>
#include <conio.h>
#include <unistd.h>

using namespace std;

 /*   
 /    Quadratic Equation Calculator v0.1
 /    By Michael Constantine Dimopoulos
 /    Just a small >100 lines project I decided to do because I was bored :P
 /    Feel free to modify & redistribute the code
 /    GNU GPL 3.0
*/

// Declaring Functions
void banner();
void get_values();
void cal_discriminatory(float a, float b, float c);
void cal_roots(float a, float b, float c, float D);
void vieta(float a, float b, float c, float x1, float x2);

int main(int argc, char** argv) {
	banner();
	get_values();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	sleep(2);
	cin;
	return 0;
}

//Getting the values (basic input)
void get_values(){
	float a,b,c;
	cout << "Enter the value of a: ";
	cin>>a;
	cout << "Enter the value of b: ";
	cin>>b;
	cout << "Enter the value of c: ";
	cin>>c;
	cout << "Values a,b,c: " << a << ", " << b << ", " << c << endl << endl;
	cal_discriminatory(a, b, c);
}
void banner()
{
	cout << "Quadratic Equation Calculator v0.1" << endl << "By Michael Constantine Dimopoulos" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Form = ax^2 + bx + c = 0" << endl;
	
}

//Calculating discriminant with formulas
void cal_discriminatory(float a, float b, float c){
	// D = b^2-4ac
	float D = (b*b)-(4*a*c);
	cout << "[+] Discriminant: " << D << endl;
	//How many roots
	if (D > 0) {
		cout << "[+] Two unequal roots" << endl;
	} else if (D == 0) {
		cout << "[+] Two equal roots" << endl;
	} else {
		cout << "[!] No possible roots" << endl;
		exit(0);
	}
	cal_roots(a, b, c, D);
}

// Calculating the roots based on the known formulas
void cal_roots(float a, float b, float c, float D)
{
	float x1 = (-b + sqrt(D)) / (a * 2);
	float x2 = (-b - sqrt(D)) / (a * 2);
	cout << endl << "[+] First root x1: " << x1 << endl << "[+] Second root x2: " << x2;
	vieta(a,b,c,x1,x2);
}

// EXTRA ;) - Vieta's formulas
void vieta(float a, float b, float c, float x1, float x2)
{
	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Vieta's formulas:" << endl << endl;
	float sum = x1 + x2;
	float product = x1 * x2;
	cout << "Sum of roots (-b/a) : " << sum << endl;
	cout << "Pro. of roots (c/a) : " << product << endl;
}
