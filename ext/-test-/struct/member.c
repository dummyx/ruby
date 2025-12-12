#include "ruby.h"

static VALUE
bug_struct_get(VALUE obj, VALUE name)
{
    ID id = rb_check_id(&name);

    if (!id) {
        rb_name_error_str(name, "'%"PRIsVALUE"' is not a struct member", name);
    }
    return rb_struct_getmember(obj, id);
    RB_GC_GUARD(name);
    RB_GC_GUARD(obj);
}

void
Init_member(VALUE klass)
{
    rb_define_method(klass, "get", bug_struct_get, 1);
}
