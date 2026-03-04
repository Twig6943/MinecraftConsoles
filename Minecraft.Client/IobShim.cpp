// Original file is iob_shim.asm
// Rewritten in C because the build system breaks on linux-windows crosscomp with this
#if 0
.code
EXTRN __acrt_iob_func:PROC

__iob_func PROC
    mov     ecx, 0
    jmp     __acrt_iob_func
__iob_func ENDP

END
#endif

#include <cstdio>

extern "C" FILE* __cdecl __iob_func ( void ) {
  static FILE iob [ ] = { *stdin, *stdout, *stderr };
  return iob;
}
