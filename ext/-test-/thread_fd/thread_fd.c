#include "ruby/ruby.h"

static VALUE
thread_fd_close(VALUE ign, VALUE fd)
{
    rb_thread_fd_close(NUM2INT(fd));
    return Qnil;
    RB_GC_GUARD(fd);
    RB_GC_GUARD(ign);
}

static VALUE
thread_fd_wait(VALUE ign, VALUE fd)
{
    int ret = rb_thread_wait_fd(NUM2INT(fd));
    return INT2NUM(ret);
    RB_GC_GUARD(fd);
    RB_GC_GUARD(ign);
}

static VALUE
thread_fd_writable(VALUE ign, VALUE fd)
{
    int ret = rb_thread_fd_writable(NUM2INT(fd));
    return INT2NUM(ret);
    RB_GC_GUARD(fd);
    RB_GC_GUARD(ign);
}

void
Init_thread_fd(void)
{
    rb_define_singleton_method(rb_cIO, "thread_fd_close", thread_fd_close, 1);
    rb_define_singleton_method(rb_cIO, "thread_fd_wait", thread_fd_wait, 1);
    rb_define_singleton_method(rb_cIO, "thread_fd_writable", thread_fd_writable, 1);
}
