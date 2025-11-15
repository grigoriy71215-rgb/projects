	.file	"main.cpp"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
	.section	.rodata
.LC0:
	.string	"F for int: "
#NO_APP
	.text
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
.LFB1984:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1984:
	.size	_Z1fi, .-_Z1fi
	.section	.rodata
.LC1:
	.string	"F for float: "
	.text
	.globl	_Z1ff
	.type	_Z1ff, @function
_Z1ff:
.LFB1985:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movss	%xmm0, -4(%rbp)
	movl	$.LC1, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movl	-4(%rbp), %eax
	movd	%eax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1985:
	.size	_Z1ff, .-_Z1ff
	.globl	main
	.type	main, @function
main:
.LFB1986:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$42, -4(%rbp)
	movss	.LC2(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	_Z1fi
	movl	-8(%rbp), %eax
	movd	%eax, %xmm0
	call	_Z1ff
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1986:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC2:
	.long	1112236543
	.ident	"GCC: (GNU) 15.2.1 20251022 (Red Hat 15.2.1-3)"
	.section	.note.GNU-stack,"",@progbits
