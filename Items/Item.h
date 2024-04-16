#ifndef MY_ITEM_H
#define MY_ITEM_H
#include <string>

class Item{
private:
  size_t _id;
  std::string _name;
public:
  Item() : _id{ 0 }, _name{"none"}
  {
  }

  size_t id() {
    return _id;
  }

  std::string name() {
    return _name;
  }
};

#endif