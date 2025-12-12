#include "ruby.h"

static VALUE
bug_str_ellipsize(VALUE str, VALUE len)
{
    return rb_str_ellipsize(str, NUM2LONG(len));
    RB_GC_GUARD(len);
    RB_GC_GUARD(str);
}

void
Init_string_ellipsize(VALUE klass)
{
    rb_define_method(klass, "ellipsize", bug_str_ellipsize, 1);
}
