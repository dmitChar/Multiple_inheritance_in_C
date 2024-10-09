
#include <iostream>
using namespace std;

class B1 {

private:
	int x;
public:
	void SetB1(int);
	int GetB1();
	B1();
	~B1();
	void show_B1();
};

class B2 {
private:
	int x;
public:
	void SetB2(int);
	int GetB2();
	B2();
	~B2();
	void show_B2();
};

class D1 :private virtual B1, public virtual B2 {
private:
	int x;
public:
	D1(int, int, int);
	~D1();
	void show_D1();
};

class D2 :private virtual B2, public virtual B1 {
private:
	int x;
public:
	D2(int, int, int);
	
	~D2();
	void show_D2();
};

class D3 :private virtual D1, public virtual D2 {
private:
	int x;
public:
	D3(int a, int, int, int, int);
	~D3();
	void  show_D3();
};

void B1::SetB1(int a){
	this->x = a;
}

void B2::SetB2(int a) {
	this->x = a;
}

B1::B1() {

	this->x = 0;
	cout << "Работает конструктор по умолчанию B1: параметр = "<<x<<endl;
}

B2::B2() {
	this->x = 0;
	cout << "Работает конструктор по умолчанию B2: параметр = "<<x<<endl;
}

int B1::GetB1() {
	return x;
}

int B2::GetB2() {
	return x;
}

D1::D1(int a, int b, int c) : B1(), B2() {
	this->x = a;
	SetB1(b);
	SetB2(c);
	cout << "Работает конструктор D1: параметр = " << this->x << endl;
}

D2::D2(int a, int b, int c) : B1(), B2() {
	this->x = a;
	SetB1(b);
	SetB2(c);
	cout << "Работает конструктор D2: параметр = " << this->x << endl;
}

D3::D3(int a, int b, int c, int d, int e) : D1(c, a, b), D2(d, a, b) {
	this->x = e;
	cout << "Работает конструктор D3: параметр = " << this->x << endl;

}

B1::~B1() {
	cout << "Работа деструктора B1"<<endl;
}

B2::~B2() {
	cout << "Работа деструктора B2"<<endl;
}

D1::~D1() {
	cout << "Работа деструктора D1"<<endl;
}

D2::~D2() {
	cout << "Работа деструктора D2" << endl;
}

D3::~D3() {
	cout << "Работа деструктора D3" << endl;
}

void B1::show_B1() {
	cout << "B1 = " << x << endl;
}

void B2::show_B2() {
	cout << "B2 = " << x << endl;
}

void D1::show_D1() {
	cout << "D1 = " << x << endl; show_B1(); show_B2();
}

void D2::show_D2() {
	cout << "D2 = " << x << endl; show_B1(); show_B2();
}

void D3::show_D3() {
	cout << "D3 = " << x << endl; show_D1(); show_D2();
}

int main() {

	setlocale(LC_ALL, "ru");

	/*
	 Формат передачи параметров:
	 D3 obj(B1, B2, D1, D2, D3)
	 */


	D3 obj(1, 2, 3, 4, 5);
	cout << endl;

	obj.show_D3(); cout << endl;
}
