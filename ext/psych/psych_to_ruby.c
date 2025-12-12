#include <psych.h>

VALUE cPsychVisitorsToRuby;

/* call-seq: vis.build_exception(klass, message)
 *
 * Create an exception with class +klass+ and +message+
 */
static VALUE build_exception(VALUE self, VALUE klass, VALUE mesg)
{
    VALUE e = rb_obj_alloc(klass);

    rb_iv_set(e, "mesg", mesg);

    return e;
    RB_GC_GUARD(mesg);
    RB_GC_GUARD(klass);
    RB_GC_GUARD(self);
    RB_GC_GUARD(e);
}

/* call-seq: vis.path2class(path)
 *
 * Convert +path+ string to a class
 */
static VALUE path2class(VALUE self, VALUE path)
{
    return rb_path_to_class(path);
    RB_GC_GUARD(path);
    RB_GC_GUARD(self);
}

void Init_psych_to_ruby(void)
{
    VALUE psych     = rb_define_module("Psych");
    VALUE class_loader  = rb_define_class_under(psych, "ClassLoader", rb_cObject);

    VALUE visitors  = rb_define_module_under(psych, "Visitors");
    VALUE visitor   = rb_define_class_under(visitors, "Visitor", rb_cObject);
    cPsychVisitorsToRuby = rb_define_class_under(visitors, "ToRuby", visitor);

    rb_define_private_method(cPsychVisitorsToRuby, "build_exception", build_exception, 2);
    rb_define_private_method(class_loader, "path2class", path2class, 1);
    RB_GC_GUARD(psych);
    RB_GC_GUARD(visitor);
    RB_GC_GUARD(visitors);
    RB_GC_GUARD(class_loader);
}
/* vim: set noet sws=4 sw=4: */
