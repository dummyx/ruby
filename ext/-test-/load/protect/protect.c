#include <ruby.h>

static VALUE
load_protect(int argc, VALUE *argv, VALUE self)
{
    int state;
    VALUE path, wrap;
    rb_scan_args(argc, argv, "11", &path, &wrap);
    rb_load_protect(path, RTEST(wrap), &state);
    if (state) rb_jump_tag(state);
    return Qnil;
    RB_GC_GUARD(self);
    RB_GC_GUARD(wrap);
    RB_GC_GUARD(path);
}

void
Init_protect(void)
{
    VALUE mod = rb_define_module("Bug");
    rb_define_singleton_method(mod, "load_protect", load_protect, -1);
    RB_GC_GUARD(mod);
}
