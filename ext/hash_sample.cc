#include <ruby.h>

// support 1.9 and 1.8
#ifndef RSTRING_PTR
#define RSTRING_PTR(v) RSTRING(v)->ptr
#endif

namespace {
  VALUE hs_make_hash() {
    VALUE h = rb_hash_new();
    return h;
  }

  VALUE hs_is_hash_val_nil(VALUE self, VALUE h, VALUE key) {
    Check_Type(h, T_HASH);
    // VALUE val = rb_hash_aref();
    return h;
  }
}

extern "C" {
void Init_hash_sample() {
  VALUE c_hs = rb_define_class("HashSample", rb_cObject);
  rb_define_method(c_hs, "make_hash", (VALUE (*)(...))hs_make_hash, 0);
  rb_define_method(c_hs, "hash_val_nil?", (VALUE (*)(...))hs_is_hash_val_nil, 2);
}
}
