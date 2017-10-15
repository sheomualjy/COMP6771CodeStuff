class A {
public:
    int i;
    friend void doSomething();
protected:
    int j;
private:
    int k;
};

class B : public A { 
private: 
    int l;
};

void doSomething() {
    A a;
    a.i = 1;
    a.j = 1;
    a.k = 1;
    a = a;

    B b;
    b.i = 1;
    b.j = 1;
    b.k = 1;
    b = b;
}
