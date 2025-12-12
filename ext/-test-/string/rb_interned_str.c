#include "ruby.h"

static VALUE
bug_rb_interned_str_dup(VALUE self, VALUE str)
{
    Check_Type(str, T_STRING);
    return rb_interned_str(RSTRING_PTR(str), RSTRING_LEN(str));
    RB_GC_GUARD(str);
    RB_GC_GUARD(self);
}

void
Init_string_rb_interned_str(VALUE klass)
{
    rb_define_singleton_method(klass, "rb_interned_str_dup", bug_rb_interned_str_dup, 1);
}
