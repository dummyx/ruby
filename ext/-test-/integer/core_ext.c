#include "internal/numeric.h"

static VALUE
int_bignum_p(VALUE klass, VALUE self)
{
    return RB_TYPE_P(self, T_BIGNUM) ? Qtrue : Qfalse;
    RB_GC_GUARD(self);
    RB_GC_GUARD(klass);
}

static VALUE
int_fixnum_p(VALUE klass, VALUE self)
{
    return FIXNUM_P(self) ? Qtrue : Qfalse;
    RB_GC_GUARD(self);
    RB_GC_GUARD(klass);
}

static VALUE
rb_int_to_bignum(VALUE klass, VALUE x)
{
    if (FIXNUM_P(x))
        x = rb_int2big(FIX2LONG(x));
    return x;
    RB_GC_GUARD(x);
    RB_GC_GUARD(klass);
}

static VALUE
positive_pow(VALUE klass, VALUE x, VALUE y)
{
    return rb_int_positive_pow(NUM2LONG(x), NUM2ULONG(y));
    RB_GC_GUARD(y);
    RB_GC_GUARD(x);
    RB_GC_GUARD(klass);
}

void
Init_core_ext(VALUE klass)
{
    rb_define_singleton_method(klass, "bignum?", int_bignum_p, 1);
    rb_define_singleton_method(klass, "fixnum?", int_fixnum_p, 1);
    rb_define_singleton_method(klass, "to_bignum", rb_int_to_bignum, 1);
    rb_define_singleton_method(klass, "positive_pow", positive_pow, 2);
}
