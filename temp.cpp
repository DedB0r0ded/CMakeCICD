#include <stdint.h>
#include <vector>

typedef int8_t i8;
typedef uint8_t u8;

typedef int64_t i64;
typedef uint64_t u64;

struct row {
  u64 m_value;
  const size_t m_size = 16;
  const size_t m_offset = 4;

  u8 at(size_t id) {
    return m_value >> m_offset * id;
  }

  void operator[](size_t id) {

  }

  row& operator+(const row&) {

  }
};

typedef std::vector<row> matrix;