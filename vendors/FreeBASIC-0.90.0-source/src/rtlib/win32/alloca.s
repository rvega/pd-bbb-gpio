/* alloca() implementation for win32, as it's not part of msvcrt.
   Note: Code from MinGW. */

/* MinGW now includes it's own alloca() */
#if __GNUC__ < 4

		.intel_syntax noprefix
/*		.arch i386 */ /* This option is only for ALPHA */


.section .text

/* void _alloca( size_t size -- passed in EAX! ); */
.globl __alloca
__alloca:
		push	ecx
		mov 	ecx ,esp
		add 	ecx ,8
_loop:		cmp 	eax, 1000
		jb 	_rem
		sub 	ecx, 1000
		or 	dword ptr [ecx], 0
		sub 	eax, 1000
		jmp 	_loop

_rem:		sub 	ecx, eax
		or 	dword ptr [ecx], 0
		mov 	eax, esp
		mov 	esp, ecx
		mov 	ecx, [eax]
		mov 	eax, [eax+4]
		jmp 	eax

#endif
