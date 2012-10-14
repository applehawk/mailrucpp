#include <stdio.h>

class A {  
public:
  A() { printf("class A\n"); }
};

class B : public A {
public:
  B() { printf("class B\n"); }
};

class C : public A {
public:
  C() { printf("class C\n"); }
};

class D : public B, public C{
public:
  D() { printf("class D\n"); }
};

int main(int argc, char ** argv)
{
  D* obj = new D();
}
