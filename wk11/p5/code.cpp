#include<iostream>
#include<typeinfo>

void e(const int &i, int j, int k) {
	std::cout << "1 ";
}

void e(int &i, int j, int k) {
	std::cout << "2 ";
}

template <typename A, typename B, typename C>
void f(A &&a, B &&b, C &&c) {
	// always call std::forward, never forward
	e(std::forward<A>(a), std::forward<B>(b), std::forward<C>(c));
}

int k{1};
int g() { return k; }

int main() {
	f(1,2,3); // f(int&&, int&&, int&&) --> 1
	int i{1};
	f(i,2,3); // f(int, int&&, int&&) --> 2
	const int &j = i;
	f(j,2,3); // f(const int&, i&&, i&&) --> 1
	f(g(),2,3); // f(int&&, int&&, int&&) --> 1
}
