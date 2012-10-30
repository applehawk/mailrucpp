#include <stdio.h>

class A {  
public:
  A() { printf("class A\n"); }
  void foo() { printf("This is foo\n"); }
};

class B : virtual public A {
public:
  B() { printf("class B\n"); }
};

class C : virtual public A {
public:
  C() { printf("class C\n"); }
};

class D : virtual public B, virtual public C{
public:
  D() { printf("class D\n"); }
};

int main(int argc, char ** argv)
{
  D* obj = new D();
  obj->foo();
}
