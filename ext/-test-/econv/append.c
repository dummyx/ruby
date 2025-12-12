#include "ruby/ruby.h"
#include "ruby/encoding.h"

static VALUE
econv_append(VALUE self, VALUE src, VALUE dst)
{
    rb_econv_t *ec = DATA_PTR(self);
    StringValue(src);
    StringValue(dst);
    return rb_econv_str_append(ec, src, dst, 0);
    RB_GC_GUARD(dst);
    RB_GC_GUARD(src);
    RB_GC_GUARD(self);
}

void
Init_econv_append(VALUE klass)
{
    rb_define_method(klass, "append", econv_append, 2);
}
