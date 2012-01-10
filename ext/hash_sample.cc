#include <ruby.h>

// support 1.9 and 1.8
#ifndef RSTRING_PTR
#define RSTRING_PTR(v) RSTRING(v)->ptr
#endif

extern "C" {
void Init_hash_sample() {
  VALUE m_hs = rb_define_module("HashSample");
}
}
