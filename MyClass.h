//
// Created by Vladimir Moiseiev on 13.07.2020.
//

#ifndef PROJECT_GTEST__MYCLASS_H_
#define PROJECT_GTEST__MYCLASS_H_

#include <memory>

class MyClass {
 public:
  MyClass() : state_(10) {}
 public:
  int getval() {return 1;}

  static std::unique_ptr<MyClass> make() { return std::make_unique<MyClass>();}

  unsigned int GetState() const {
    return state_;
  }
 private:
  unsigned int state_;
};

#endif //PROJECT_GTEST__MYCLASS_H_
