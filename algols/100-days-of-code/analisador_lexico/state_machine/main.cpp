#include <iostream>
#include <list>
#include <stdint.h>
#include <vector>

struct SparseNode {
  std::size_t line;
  std::size_t column;
  uint64_t value;
  SparseNode *down;
  SparseNode *left;
};

class SparseMatrix final {
private:
  std::size_t n_lines;
  std::size_t n_columns;
  std::vector<SparseNode *> lines;
  std::vector<SparseNode *> columns;

protected:
public:
};

int main(int argc, char **argv) {
  std::cout << "Hello World!" << std::endl;

  return 0;
}
