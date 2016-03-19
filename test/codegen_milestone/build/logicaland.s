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
	lui     $t8, %hi(glob1)
	lw      $t0, %lo(glob1)($t8)
	beq     $0, $t0, $LKDHGF3
	nop     
	lui     $t9, %hi(glob2)
	lw      $t1, %lo(glob2)($t9)
	beq     $0, $t1, $LKDHGF3
	nop     
	li      $t2, 1
	sw      $t2, -20($fp)
	b       $LKDHGF4
	nop     
$LKDHGF3:
	move    $t2, $0
	sw      $t2, -20($fp)
	b       $LKDHGF4
	nop     
$LKDHGF4:
	lw      $t0, -20($fp)
	lui     $t8, %hi(glob3)
	sw      $t0, %lo(glob3)($t8)
	addiu   $sp, $sp, -28		# Allocate more memory
	lw      $t0, -4($fp)
	beq     $0, $t0, $LKDHGF5
	nop     
	lw      $t1, -8($fp)
	beq     $0, $t1, $LKDHGF5
	nop     
	li      $t2, 1
	sw      $t2, -48($fp)
	b       $LKDHGF6
	nop     
$LKDHGF5:
	move    $t2, $0
	sw      $t2, -48($fp)
	b       $LKDHGF6
	nop     
$LKDHGF6:
	lw      $t0, -48($fp)
	beq     $0, $t0, $LKDHGF7
	nop     
	lw      $t1, -12($fp)
	beq     $0, $t1, $LKDHGF7
	nop     
	li      $t2, 1
	sw      $t2, -44($fp)
	b       $LKDHGF8
	nop     
$LKDHGF7:
	move    $t2, $0
	sw      $t2, -44($fp)
	b       $LKDHGF8
	nop     
$LKDHGF8:
	lw      $t0, -44($fp)
	beq     $0, $t0, $LKDHGF9
	nop     
	lw      $t1, -16($fp)
	beq     $0, $t1, $LKDHGF9
	nop     
	li      $t2, 1
	sw      $t2, -40($fp)
	b       $LKDHGF10
	nop     
$LKDHGF9:
	move    $t2, $0
	sw      $t2, -40($fp)
	b       $LKDHGF10
	nop     
$LKDHGF10:
	lw      $t0, -40($fp)
	beq     $0, $t0, $LKDHGF11
	nop     
	lw      $t1, 24($fp)
	beq     $0, $t1, $LKDHGF11
	nop     
	li      $t2, 1
	sw      $t2, -36($fp)
	b       $LKDHGF12
	nop     
$LKDHGF11:
	move    $t2, $0
	sw      $t2, -36($fp)
	b       $LKDHGF12
	nop     
$LKDHGF12:
	lw      $t0, -36($fp)
	beq     $0, $t0, $LKDHGF13
	nop     
	lw      $t1, 28($fp)
	beq     $0, $t1, $LKDHGF13
	nop     
	li      $t2, 1
	sw      $t2, -32($fp)
	b       $LKDHGF14
	nop     
$LKDHGF13:
	move    $t2, $0
	sw      $t2, -32($fp)
	b       $LKDHGF14
	nop     
$LKDHGF14:
	lw      $t0, -32($fp)
	beq     $0, $t0, $LKDHGF15
	nop     
	lw      $t1, 32($fp)
	beq     $0, $t1, $LKDHGF15
	nop     
	li      $t2, 1
	sw      $t2, -28($fp)
	b       $LKDHGF16
	nop     
$LKDHGF15:
	move    $t2, $0
	sw      $t2, -28($fp)
	b       $LKDHGF16
	nop     
$LKDHGF16:
	lw      $t0, -28($fp)
	beq     $0, $t0, $LKDHGF17
	nop     
	lui     $t9, %hi(glob3)
	lw      $t1, %lo(glob3)($t9)
	beq     $0, $t1, $LKDHGF17
	nop     
	li      $t2, 1
	sw      $t2, -24($fp)
	b       $LKDHGF18
	nop     
$LKDHGF17:
	move    $t2, $0
	sw      $t2, -24($fp)
	b       $LKDHGF18
	nop     
$LKDHGF18:
	lw      $v0, -24($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 80		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end f

