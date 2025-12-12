#include "ruby.h"

static VALUE
path_to_class(VALUE klass, VALUE path)
{
    return rb_path_to_class(path);
    RB_GC_GUARD(path);
    RB_GC_GUARD(klass);
}

void
Init_path_to_class(void)
{
    VALUE klass = rb_path2class("Test_PathToClass");

    rb_define_singleton_method(klass, "path_to_class", path_to_class, 1);
    RB_GC_GUARD(klass);
}
