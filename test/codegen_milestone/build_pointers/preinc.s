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
	addiu   $sp, $sp, -40		# Allocate memory on the stack
	sw      $fp, 36($sp)		# Store value of $fp on the bottom of the stack
	addiu   $fp, $sp, 32		# Point $fp to the bottom of the available memory
	sw      $ra, 0($fp)		# Store the return address for the current subroutine
	sw      $a0, -4($fp)
	sw      $a1, -8($fp)
	sw      $a2, -12($fp)
	sw      $a3, -16($fp)
	lw      $t0, -8($fp)
	addiu   $t0, $t0, 1
	sw      $t0, -8($fp)
	sw      $t0, -20($fp)
	lw      $t2, -20($fp)
	lw      $t6, -12($fp)
	sw      $t2, 0($t6)
	lw      $t0, 24($fp)
	addiu   $t0, $t0, 1
	sw      $t0, 24($fp)
	sw      $t0, -24($fp)
	lw      $t2, -24($fp)
	lw      $t6, -12($fp)
	sw      $t2, 0($t6)
	lw      $t0, 28($fp)
	addiu   $t0, $t0, 1
	sw      $t0, 28($fp)
	sw      $t0, -28($fp)
	lw      $t2, -28($fp)
	lw      $t6, -12($fp)
	sw      $t2, 0($t6)
	addiu   $sp, $sp, -28		# Allocate more memory
	lw      $t6, 32($fp)
	lw      $t0, 0($t6)
	addiu   $t0, $t0, 1
	lw      $t6, 32($fp)
	sw      $t0, 0($t6)
	sw      $t0, -32($fp)
	lw      $t2, -32($fp)
	lw      $t6, -12($fp)
	sw      $t2, 0($t6)
	lw      $t6, -12($fp)
	lw      $t0, 0($t6)
	addiu   $t0, $t0, 1
	lw      $t6, -12($fp)
	sw      $t0, 0($t6)
	sw      $t0, -36($fp)
	lw      $t2, -36($fp)
	lui     $t9, %hi(glob3)
	sw      $t2, %lo(glob3)($t9)
	lui     $t9, %hi(glob3)
	lw      $t0, %lo(glob3)($t9)
	addiu   $t0, $t0, 1
	lui     $t9, %hi(glob3)
	sw      $t0, %lo(glob3)($t9)
	sw      $t0, -40($fp)
	lw      $t2, -40($fp)
	lw      $t6, -12($fp)
	sw      $t2, 0($t6)
	lw      $t6, -12($fp)
	lw      $v0, 0($t6)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 68		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end fn

	.align	2
	.globl fncall
	.ent fncall
	.type fncall, @function
fncall:
	addiu   $sp, $sp, -40		# Allocate memory on the stack
	sw      $fp, 36($sp)		# Store value of $fp on the bottom of the stack
	addiu   $fp, $sp, 32		# Point $fp to the bottom of the available memory
	sw      $ra, 0($fp)		# Store the return address for the current subroutine
	sw      $a0, -4($fp)
	sw      $a1, -8($fp)
	sw      $a2, -12($fp)
	sw      $a3, -16($fp)
	addiu   $t0, $fp, -16
	sw      $t0, -20($fp)
	lw      $a0, -4($fp)
	lw      $a1, -8($fp)
	lw      $a2, -12($fp)
	lw      $a3, 32($fp)
	addiu   $sp, $sp, -36		# Allocate more memory
	lw      $t6, 24($fp)
	lw      $t7, 0($t6)
	sw      $t7, 16($sp)
	lw      $t0, 28($fp)
	sw      $t0, 20($sp)
	lw      $t7, -20($fp)
	sw      $t7, 24($sp)
	la      $t0, fn
	jalr    $t0
	nop     
	sw      $v0, -24($fp)
	lw      $v0, -24($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 76		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end fncall

