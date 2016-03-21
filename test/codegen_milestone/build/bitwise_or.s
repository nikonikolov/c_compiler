	.globl  glob1
	.data   
	.align  2
	.type   glob1, @object
	.size   glob1, 4
glob1:
	.word   10

	.globl  glob2
	.align  2
	.type   glob2, @object
	.size   glob2, 4
glob2:
	.word   67

	.globl  glob3
	.align  2
	.type   glob3, @object
	.size   glob3, 4
glob3:
	.word   80

	.globl  a
	.align  2
	.type   a, @object
	.size   a, 4
a:
	.word   57

	.text   
	.align	2
	.globl fn
	.ent fn
	.type fn, @function
fn:
	addiu   $sp, $sp, -24		# Allocate memory on the stack
	sw      $fp, 20($sp)		# Store value of $fp on the bottom of the stack
	addiu   $fp, $sp, 16		# Point $fp to the bottom of the available memory
	sw      $ra, 0($fp)		# Store the return address for the current subroutine
	sw      $a0, -4($fp)
	sw      $a1, -8($fp)
	sw      $a2, -12($fp)
	addiu   $sp, $sp, -28		# Allocate more memory
	sw      $a3, -16($fp)
	lui     $t8, %hi(glob1)
	lw      $t0, %lo(glob1)($t8)
	lui     $t9, %hi(glob2)
	lw      $t1, %lo(glob2)($t9)
	or      $t2, $t0, $t1
	sw      $t2, -20($fp)
	lw      $t0, -20($fp)
	lui     $t8, %hi(glob3)
	sw      $t0, %lo(glob3)($t8)
	addiu   $sp, $sp, -28		# Allocate more memory
	lw      $t0, -4($fp)
	lw      $t1, -8($fp)
	or      $t2, $t0, $t1
	sw      $t2, -48($fp)
	lw      $t0, -48($fp)
	lw      $t1, -12($fp)
	or      $t2, $t0, $t1
	sw      $t2, -44($fp)
	lw      $t0, -44($fp)
	lw      $t1, -16($fp)
	or      $t2, $t0, $t1
	sw      $t2, -40($fp)
	lw      $t0, -40($fp)
	lw      $t1, 24($fp)
	or      $t2, $t0, $t1
	sw      $t2, -36($fp)
	lw      $t0, -36($fp)
	lw      $t1, 28($fp)
	or      $t2, $t0, $t1
	sw      $t2, -32($fp)
	lw      $t0, -32($fp)
	lw      $t1, 32($fp)
	or      $t2, $t0, $t1
	sw      $t2, -28($fp)
	lw      $t0, -28($fp)
	lui     $t9, %hi(glob3)
	lw      $t1, %lo(glob3)($t9)
	or      $t2, $t0, $t1
	sw      $t2, -24($fp)
	lw      $v0, -24($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 80		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end fn

