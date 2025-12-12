#include "ruby/ruby.h"

static VALUE
eval_string(VALUE self, VALUE str)
{
    return rb_eval_string(StringValueCStr(str));
    RB_GC_GUARD(str);
    RB_GC_GUARD(self);
}

void
Init_eval(void)
{
    rb_define_global_function("rb_eval_string", eval_string, 1);
}
