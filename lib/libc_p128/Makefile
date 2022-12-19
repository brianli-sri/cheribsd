LIBC_P128=	yes
SHLIBDIR:=	/usr/lib128
LIBDIR:=	/usr/lib128

.if defined(MACHINE_CPU)
MACHINE_CPU:=	${MACHINE_CPU:Ncheri:Nmorello}
.endif

NO_SHARED=

.include "${SRCTOP}/lib/libc/Makefile"
