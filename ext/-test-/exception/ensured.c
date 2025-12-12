#include <ruby.h>

static VALUE
begin(VALUE object)
{
    return rb_funcall(object, rb_intern("try_method"), 0);
    RB_GC_GUARD(object);
}

static VALUE
ensure(VALUE object)
{
    return rb_funcall(object, rb_intern("ensured_method"), 0);
    RB_GC_GUARD(object);
}

static VALUE
ensured(VALUE module, VALUE object)
{
    return rb_ensure(begin, object, ensure, object);
    RB_GC_GUARD(object);
    RB_GC_GUARD(module);
}

static VALUE
exc_raise(VALUE exc)
{
    rb_exc_raise(exc);
    return Qnil;
    RB_GC_GUARD(exc);
}

static VALUE
ensure_raise(VALUE module, VALUE object, VALUE exc)
{
    return rb_ensure(rb_yield, object, exc_raise, exc);
    RB_GC_GUARD(exc);
    RB_GC_GUARD(object);
    RB_GC_GUARD(module);
}

void
Init_ensured(VALUE klass)
{
    rb_define_module_function(klass, "ensured", ensured, 1);
    rb_define_module_function(klass, "ensure_raise", ensure_raise, 2);
}
