#include "ruby.h"
#include "ruby/encoding.h"

VALUE
bug_rb_define_dummy_encoding(VALUE self, VALUE name)
{
    int idx = rb_define_dummy_encoding(RSTRING_PTR(name));
    return rb_enc_from_encoding(rb_enc_from_index(idx));
    RB_GC_GUARD(name);
    RB_GC_GUARD(self);
}

void
Init_string_enc_dummy(VALUE klass)
{
    rb_define_singleton_method(klass, "rb_define_dummy_encoding", bug_rb_define_dummy_encoding, 1);
}
