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
	li      $t0, 1
	li      $t1, 0xFFFFFFFF
	xor     $t0, $t0, $t1
	addi    $t0, $t0, 1
	sw      $t0, -20($fp)
	li      $t0, 1
	sw      $t0, -24($fp)
	lw      $t0, -4($fp)
	lw      $t1, -8($fp)
	beq     $t0, $t1, $LKDHGF3
	move    $t2, $0
	sw      $t2, -28($fp)
	b       $LKDHGF4
$LKDHGF3:
	li      $t2, 1
	sw      $t2, -28($fp)
$LKDHGF4:
	lw      $t0, -28($fp)
	beq     $0, $t0, $LKDHGF5
	lw      $t1, -20($fp)
	b       $LKDHGF6
	nop     
$LKDHGF5:
	lw      $t1, -24($fp)
$LKDHGF6:
	sw      $t1, -32($fp)
	lw      $t0, -4($fp)
	lw      $t1, -8($fp)
	subu    $t2, $t0, $t1
	bgtz    $t2, $LKDHGF7
	move    $t2, $0
	sw      $t2, -36($fp)
	b       $LKDHGF8
$LKDHGF7:
	li      $t2, 1
	sw      $t2, -36($fp)
$LKDHGF8:
	lw      $t0, -36($fp)
	beq     $0, $t0, $LKDHGF9
	lw      $t1, -4($fp)
	b       $LKDHGF10
	nop     
$LKDHGF9:
	lw      $t1, -32($fp)
$LKDHGF10:
	sw      $t1, -40($fp)
	lw      $v0, -40($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 52		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end fn

	.align	2
	.globl fncall
	.ent fncall
	.type fncall, @function
fncall:
	addiu   $sp, $sp, -24		# Allocate memory on the stack
	sw      $fp, 20($sp)		# Store value of $fp on the bottom of the stack
	addiu   $fp, $sp, 16		# Point $fp to the bottom of the available memory
	sw      $ra, 0($fp)		# Store the return address for the current subroutine
	sw      $a0, -4($fp)
	sw      $a1, -8($fp)
	sw      $a2, -12($fp)
	addiu   $sp, $sp, -28		# Allocate more memory
	sw      $a3, -16($fp)
	lw      $a0, -4($fp)
	lw      $a1, -8($fp)
	lw      $a2, -12($fp)
	lw      $a3, -16($fp)
	addiu   $sp, $sp, -20		# Allocate more memory
	lw      $t0, 24($fp)
	sw      $t0, 16($sp)
	lw      $t0, 28($fp)
	sw      $t0, 20($sp)
	lw      $t0, 32($fp)
	sw      $t0, 24($sp)
	la      $t0, fn
	jalr    $t0
	nop     
	sw      $v0, -20($fp)
	lw      $v0, -20($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 72		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end fncall

