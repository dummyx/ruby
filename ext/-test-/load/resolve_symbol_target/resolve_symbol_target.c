#include <ruby.h>
#include "resolve_symbol_target.h"

VALUE
rst_any_method(VALUE klass)
{
    return rb_str_new_cstr("from target");
    RB_GC_GUARD(klass);
}

void
Init_resolve_symbol_target(void)
{
    VALUE mod = rb_define_module("ResolveSymbolTarget");
    rb_define_singleton_method(mod, "any_method", rst_any_method, 0);
    RB_GC_GUARD(mod);
}
