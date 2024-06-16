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

int main(int argc, char** argv)
{
	int x{ 0 };
	auto l = [&x]() {
		std::cout << (x += 100) << std::endl;
		};

	l();
	l();

	std::underlying_type_t<Color> a;
	a = 2;

	std::cout << Color::Cyan;

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

