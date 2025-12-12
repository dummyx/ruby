#include "ruby.h"

static VALUE
bug_data_new(VALUE self, VALUE super)
{
    return rb_data_define(super, "mem1", "mem2", NULL);
    RB_GC_GUARD(super);
    RB_GC_GUARD(self);
}

void
Init_data(VALUE klass)
{
    rb_define_singleton_method(klass, "data_new", bug_data_new, 1);
}
