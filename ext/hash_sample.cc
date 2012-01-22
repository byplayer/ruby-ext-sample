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
    VALUE val = rb_hash_aref(h, key);
    if(NIL_P(val)) {
      return Qfalse;
    } else {
      return Qtrue;
    }
  }

  VALUE hs_has_test_sym(VALUE self, VALUE h) {
    Check_Type(h, T_HASH);
    VALUE val = rb_hash_aref(h, ID2SYM(rb_intern("test")));
    if(NIL_P(val)) {
      return Qfalse;
    } else {
      return Qtrue;
    }
  }
}

extern "C" {
void Init_hash_sample() {
  VALUE c_hs = rb_define_class("HashSample", rb_cObject);
  rb_define_method(c_hs, "make_hash", (VALUE (*)(...))hs_make_hash, 0);
  rb_define_method(c_hs, "hash_val_nil?", (VALUE (*)(...))hs_is_hash_val_nil, 2);
  rb_define_method(c_hs, "has_test_sym?", (VALUE (*)(...))hs_has_test_sym, 1);
}
}
