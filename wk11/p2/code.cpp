#include <iostream>

class B {
public:
	virtual void f() { 
		std::cout << "B "; 
	}
};

class D : public B {
public:
	virtual void f() { 
		std::cout << "D "; 
	}
};

int main() {
	B b;
	D d;

	B &rb = d; // q1: what is the object slicing problem? 
	B &pb = b;

	rb.f(); // q2: What is the output of b.f() and why is this output produced?
	pb.f(); // q3: What is the output of pb.f() and why is this output produced?
}

// q4: How can we correct this code to prevent the object slicing problem?
