#include "A.h"
#include "B.h"

A::A(const B &b) { b_ptr = std::make_unique<B>(b); }

int A::returnBB() const { return b_ptr->bb; }
