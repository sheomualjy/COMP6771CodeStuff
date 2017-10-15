#include <iostream> 

class A {          
public:               
	virtual void f(int) { std::cout << "A::f(int)\n"; }
	virtual int g() { std::cout << "A::g()\n"; return 0; }
	void a() { std::cout << "A::a()\n"; }
	virtual ~A() { std::cout << "A::~A()\n"; }
};

class B : public A {   
public:                       
	virtual void f(int) { std::cout << "B::f(int)\n"; }
	virtual int h() { std::cout << "B::h()\n"; return 0; }
};

class C : public B {       
public:                   
	virtual void f(int, int) { std::cout << "C::f(int, int)\n"; }
	virtual void x() { std::cout << "C::x()\n"; }     
	static void b() { std::cout << "C::b()\n"; }
};

int main() {
    A *a = new A();
    B *b = new B();
    C *c = new C();

    std::cout << "-------------\n";
    std::cout << "vtable for A\n";
    std::cout << "-------------\n";
    std::cout << "0 | "; a->f(0);
    std::cout << "1 | "; a->g();
    std::cout << "-------------\n";
    std::cout << "other: "; a->a();
    std::cout << "-------------\n\n\n\n";

    std::cout << "-------------\n";
    std::cout << "vtable for B\n";
    std::cout << "-------------\n";
    std::cout << "0 | "; b->f(0);
    std::cout << "1 | "; b->g();
    std::cout << "2 | "; b->h();
    std::cout << "-------------\n";
    std::cout << "other: "; b->a();
    std::cout << "-------------\n\n\n\n";

    std::cout << "-------------\n";
    std::cout << "vtable for C\n";
    std::cout << "-------------\n";
    std::cout << "0 | "; c->f(0, 0);
    std::cout << "1 | "; c->g();
    std::cout << "2 | "; c->h();
    std::cout << "3 | "; c->x();
    std::cout << "-------------\n";
    std::cout << "other: "; c->a();
    std::cout << "other: "; c->b();
    std::cout << "-------------\n\n\n\n";
}
