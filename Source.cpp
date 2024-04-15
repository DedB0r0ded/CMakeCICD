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

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	

	return RUN_ALL_TESTS();
}

