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
	lw      $t1, -8($fp)
	subu    $t2, $t0, $t1
	blez    $t2, $LKDHGF3
	nop     
	move    $t2, $0
	sw      $t2, -32($fp)
	b       $LKDHGF4
	nop     
$LKDHGF3:
	li      $t2, 1
	sw      $t2, -32($fp)
	b       $LKDHGF4
	nop     
$LKDHGF4:
	lw      $t0, -12($fp)
	lw      $t1, -16($fp)
	subu    $t2, $t0, $t1
	blez    $t2, $LKDHGF5
	nop     
	move    $t2, $0
	sw      $t2, -36($fp)
	b       $LKDHGF6
	nop     
$LKDHGF5:
	li      $t2, 1
	sw      $t2, -36($fp)
	b       $LKDHGF6
	nop     
$LKDHGF6:
	lw      $t0, -32($fp)
	beq     $0, $t0, $LKDHGF7
	nop     
	lw      $t1, -36($fp)
	beq     $0, $t1, $LKDHGF7
	nop     
	li      $t2, 1
	sw      $t2, -28($fp)
	b       $LKDHGF8
	nop     
$LKDHGF7:
	move    $t2, $0
	sw      $t2, -28($fp)
	b       $LKDHGF8
	nop     
$LKDHGF8:
	lw      $t0, 24($fp)
	lw      $t1, 28($fp)
	subu    $t2, $t0, $t1
	bltz    $t2, $LKDHGF9
	nop     
	move    $t2, $0
	sw      $t2, -40($fp)
	b       $LKDHGF10
	nop     
$LKDHGF9:
	li      $t2, 1
	sw      $t2, -40($fp)
	b       $LKDHGF10
	nop     
$LKDHGF10:
	lw      $t0, -28($fp)
	bne     $0, $t0, $LKDHGF11
	nop     
	lw      $t1, -40($fp)
	bne     $0, $t1, $LKDHGF11
	nop     
	move    $t2, $0
	sw      $t2, -24($fp)
	b       $LKDHGF12
	nop     
$LKDHGF11:
	li      $t2, 1
	sw      $t2, -24($fp)
	b       $LKDHGF12
	nop     
$LKDHGF12:
	lw      $t0, -24($fp)
	bne     $0, $t0, $LKDHGF13
	nop     
	lw      $t1, 32($fp)
	bne     $0, $t1, $LKDHGF13
	nop     
	move    $t2, $0
	sw      $t2, -20($fp)
	b       $LKDHGF14
	nop     
$LKDHGF13:
	li      $t2, 1
	sw      $t2, -20($fp)
	b       $LKDHGF14
	nop     
$LKDHGF14:
	lw      $v0, -20($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 52		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end f

