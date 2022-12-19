LIBC_P128=	yes
SHLIBDIR:=	/usr/lib128
LIBDIR:=	/usr/lib128

.if defined(MACHINE_CPU)
MACHINE_CPU:=	${MACHINE_CPU:Ncheri:Nmorello}
.endif

NO_SHARED=

MK_TESTS=	no

.PATH: ${.CURDIR:H}/common

.include <src.opts.mk>

CFLAGS+=	-I${.CURDIR}
CFLAGS+=	-DCRT_IRELOC_RELA

.if ${MACHINE_CPU:Mcheri}
CFLAGS+=	-I${.CURDIR:H}/common-cheri
.endif

CRT1OBJS+=	crt1_s.o

.include <bsd.lib.mk>
