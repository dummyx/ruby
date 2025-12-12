#include "ruby.h"

static VALUE
bug_struct_new_duplicate(VALUE obj, VALUE name, VALUE mem)
{
    const char *n = NIL_P(name) ? 0 : StringValueCStr(name);
    const char *m = StringValueCStr(mem);
    return rb_struct_define(n, m, m, NULL);
    RB_GC_GUARD(mem);
    RB_GC_GUARD(name);
    RB_GC_GUARD(obj);
}

static VALUE
bug_struct_new_duplicate_under(VALUE obj, VALUE name, VALUE mem)
{
    const char *n = StringValueCStr(name);
    const char *m = StringValueCStr(mem);
    return rb_struct_define_under(obj, n, m, m, NULL);
    RB_GC_GUARD(mem);
    RB_GC_GUARD(name);
    RB_GC_GUARD(obj);
}

void
Init_duplicate(VALUE klass)
{
    rb_define_singleton_method(klass, "new_duplicate", bug_struct_new_duplicate, 2);
    rb_define_singleton_method(klass, "new_duplicate_under", bug_struct_new_duplicate_under, 2);
}
