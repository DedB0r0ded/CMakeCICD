#include "Header.h"

enum struct Color : int {Cyan, Magenta, Yellow, Black};

std::istream& operator>>(std::istream& is, Color& color) {
	std::underlying_type_t<Color> input;
	is >> input;
	switch ((Color)input) {
		case Color::Cyan:			color = Color(input); break;
		case Color::Magenta:	color = Color(input); break;
		case Color::Yellow:		color = Color(input); break;
		case Color::Black:		color = Color(input); break;
		default:			std::cout << "Invalid color input.";
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
	switch (color) {
		case Color::Cyan:			os << "Cyan"; break;
		case Color::Magenta:	os << "Magenta"; break;
		case Color::Yellow:		os << "Yellow"; break;
		case Color::Black:		os << "Black"; break;
		default:							std::cout << "Unknown color.";
	}
	return os;
}

int* foo(const int& size) {
	int* arr = (int*)malloc(size*sizeof(int));
	return arr;
}

class A {
public:
	int x, y;
	A() { x = y = 5; }
};

class B {
public:
	A* Ass;
	int n;
	B() {
		Ass = nullptr; n = 0;
	}
	B(int n) {
		Ass = new A[n]; this->n = n;
	}
	~B() {
		delete Ass;
	}
};

int main(int argc, char** argv)
{
	int x{ 0 };
	auto l = [&x]() {
		std::cout << (x += 100) << std::endl;
		};

	l();
	l();

	int* a;
	a = foo(10);

	for(int i = 0; i < 10; i++)
		std::cout << a[i] << std::endl;

	free(a);

	//testing::InitGoogleTest(&argc, argv);
	return 0; // RUN_ALL_TESTS();
}

