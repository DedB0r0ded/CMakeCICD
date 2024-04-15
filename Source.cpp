#include "Header.h"

using std::cout;
using std::cin;
using std::endl;

template <typename T>
void printList(const std::shared_ptr<List<T>> list) {
	for (int i = 0; i < list->size(); i++)
		cout << list->at(i) << ' ';
}

template <class T>
std::shared_ptr<List<T>> makeList() {
	std::shared_ptr<List<T>> l = std::make_shared<List<int>>();
	return l;
}

int main()
{
	cout << std::boolalpha;
	
	auto l = makeList<int>();

	cout << l->empty();

	for(int i = 0; i < 1000; i++)
		l->push_back(i);

	printList(l);
	

	return 0;
}

