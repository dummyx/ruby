#include <ruby.h>

static VALUE
bug_gettid(VALUE self)
{
    pid_t tid = gettid();
    return PIDT2NUM(tid);
    RB_GC_GUARD(self);
}

void
Init_id(void)
{
    VALUE klass = rb_define_module_under(rb_define_module("Bug"), "ThreadID");
    rb_define_module_function(klass, "gettid", bug_gettid, 0);
    RB_GC_GUARD(klass);
}
