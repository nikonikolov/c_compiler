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
	.text   
	.align	2
	.globl f
	.ent f
	.type f, @function
f:
	addiu   $sp, $sp, -24		# Allocate memory on the stack
	sw      $fp, 20($sp)		# Store value of fp on the bottom of the stack
	addiu   $fp, $sp, 16		# Modify fp to point to the the bottom of the available stack memory
	sw      $ra, 0($fp)		# Store the return address for the current subroutine
	sw      $a0, -4($fp)
	sw      $a1, -8($fp)
	sw      $a2, -12($fp)
	addiu   $sp, $sp, -28		# Allocate more memory
	sw      $a3, -16($fp)
	lw      $t0, -4($fp)
	beq     $t0, $0, $LKDHGF4
	addiu   $sp, $sp, -28		# Allocate more memory
	lw      $t0, -20($fp)
	lw      $t1, -24($fp)
	addu    $t2, $t0, $t1
	sw      $t2, -48($fp)
	lw      $t0, -48($fp)
	lw      $t1, -32($fp)
	addu    $t2, $t0, $t1
	sw      $t2, -44($fp)
	lw      $t0, -44($fp)
	lw      $t1, -36($fp)
	addu    $t2, $t0, $t1
	sw      $t2, -40($fp)
	lw      $t0, -40($fp)
	sw      $t0, -36($fp)
	li      $t0, 10
	sw      $t0, -52($fp)
	lw      $v0, -52($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 80		# Restore the value of the stack pointer
	j       $ra
	nop     
	b       $LKDHGF3
	addiu   $sp, $sp, 28
$LKDHGF4:
	lw      $v0, -8($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 52		# Restore the value of the stack pointer
	j       $ra
	nop     
$LKDHGF3:
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 52		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end f

