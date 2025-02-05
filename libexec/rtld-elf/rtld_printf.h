/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright 2011 Konstantin Belousov <kib@FreeBSD.org>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef RTLD_PRINTF_H
#define RTLD_PRINTF_H 1

#if defined(IN_RTLD) && defined(__CHERI_PURE_CAPABILITY__)
#include <simple_printf.h>
#else

#include <sys/cdefs.h>
#include <stdarg.h>
#include <unistd.h>

__BEGIN_DECLS

int rtld_snprintf(char *buf, size_t bufsize, const char *fmt, ...)
    __printflike(3, 4);
int rtld_vsnprintf(char *buf, size_t bufsize, const char *fmt, va_list ap);
int rtld_vfdprintf(int fd, const char *fmt, va_list ap);
int rtld_fdprintf(int fd, const char *fmt, ...) __printflike(2, 3);
int rtld_fdprintfx(int fd, const char *fmt, ...);
void rtld_fdputstr(int fd, const char *str);
void rtld_fdputchar(int fd, int c);

#define	rtld_printf(...) rtld_fdprintf(STDOUT_FILENO, __VA_ARGS__)
#define	rtld_putstr(str) rtld_fdputstr(STDOUT_FILENO, (str))
#define	rtld_putchar(c) rtld_fdputchar(STDOUT_FILENO, (c))
#define rtld_write(fd, s, n) write(fd, s, n)
__END_DECLS

#endif  /* !defined(__CHERI_PURE_CAPABILITY__) */

#endif
