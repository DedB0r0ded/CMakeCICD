#include "Header.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << std::boolalpha;
	List<int> l = List<int>();
	cout << l.empty() << '\t' << l.size() << endl;
	l.push_back(10);
	cout << l.empty() << '\t' << l.size() << endl;
	
	return 0;
}

