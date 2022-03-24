#ifndef __Memoria__
#define __Memoria__
#include <iostream>
#include <vector>
class Memoria {
 public:
  Memoria(int);
  Memoria();
  ~Memoria();

  int load(int);
  std::vector<int> get_memoria() const { return memoria_; }
  void set_memoria(int, int);
  std::ostream& write(std::ostream& os);

 private:
  std::vector<int> memoria_;
};

#endif