class Base {
public:
	const int& getI() const { return i; }
private:
	int i;
};

class Derived : public Base {
public:
	void foo(Derived &o) {
		j = o.getI() + o.j;
	}
private:
	int j;
};

