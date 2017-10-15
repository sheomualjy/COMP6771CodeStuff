class Base {
protected:
    int i;
};

class Derived : public Base {
public:
    void foo(Derived &o) {
        j = o.i + o.j;
    }
private:
    int j;
};
