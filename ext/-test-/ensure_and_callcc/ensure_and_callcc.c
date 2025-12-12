#include "ruby.h"

static VALUE rb_mEnsureAndCallcc;

struct require_data {
    VALUE obj;
    VALUE fname;
};

static VALUE
call_require(VALUE arg)
{
    struct require_data *data = (struct require_data *)arg;
    rb_f_require(data->obj, data->fname);
    return Qnil;
    RB_GC_GUARD(arg);
}

static VALUE
call_ensure(VALUE _)
{
    VALUE v = rb_iv_get(rb_mEnsureAndCallcc, "@ensure_called");
    int called = FIX2INT(v) + 1;
    rb_iv_set(rb_mEnsureAndCallcc, "@ensure_called", INT2FIX(called));
    return Qnil;
    RB_GC_GUARD(_);
    RB_GC_GUARD(v);
}

static VALUE
require_with_ensure(VALUE self, VALUE fname)
{
    struct require_data data = {
        .obj = self,
        .fname = fname
    };
    return rb_ensure(call_require, (VALUE)&data, call_ensure, Qnil);
    RB_GC_GUARD(fname);
    RB_GC_GUARD(self);
}

static VALUE
ensure_called(VALUE self)
{
    return rb_iv_get(rb_mEnsureAndCallcc, "@ensure_called");
    RB_GC_GUARD(self);
}

static VALUE
reset(VALUE self)
{
    rb_iv_set(rb_mEnsureAndCallcc, "@ensure_called", INT2FIX(0));
    return Qnil;
    RB_GC_GUARD(self);
}

void
Init_ensure_and_callcc(void)
{
    rb_mEnsureAndCallcc = rb_define_module("EnsureAndCallcc");
    rb_iv_set(rb_mEnsureAndCallcc, "@ensure_called", INT2FIX(0));
    rb_define_singleton_method(rb_mEnsureAndCallcc, "reset", reset, 0);
    rb_define_singleton_method(rb_mEnsureAndCallcc, "ensure_called", ensure_called, 0);
    rb_define_singleton_method(rb_mEnsureAndCallcc, "require_with_ensure", require_with_ensure, 1);
}
