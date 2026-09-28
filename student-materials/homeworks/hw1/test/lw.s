/* Test lw: read 2 words from .data section (located at 0xA00) */
        .global _start
        .text
        .align 4
_start:
	addi x1, x0, 0x500
	addi x1, x1, 0x500   # x1 = 0xA00
	lw x2, 0(x1)
	lw x3, 4(x1)
	ebreak

	.data
	.word 0xDEADBEEF
	.word 0xFACECAFE
