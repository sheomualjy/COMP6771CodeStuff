class A {
public:
    virtual void f() { }
};

class B {
public:
    virtual void f() { }
};

class C: public A, B { };

int main () {
    C c;
    c.f();
}
