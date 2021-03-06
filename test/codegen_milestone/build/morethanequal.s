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
	lw      $t0, -4($fp)
	lw      $t1, -8($fp)
	subu    $t2, $t0, $t1
	bgez    $t2, $LKDHGF3
	nop     
	move    $t2, $0
	sw      $t2, -20($fp)
	b       $LKDHGF4
	nop     
$LKDHGF3:
	li      $t2, 1
	sw      $t2, -20($fp)
	b       $LKDHGF4
	nop     
$LKDHGF4:
	lw      $t0, -12($fp)
	lw      $t1, -16($fp)
	subu    $t2, $t0, $t1
	bgez    $t2, $LKDHGF5
	nop     
	move    $t2, $0
	sw      $t2, -24($fp)
	b       $LKDHGF6
	nop     
$LKDHGF5:
	li      $t2, 1
	sw      $t2, -24($fp)
	b       $LKDHGF6
	nop     
$LKDHGF6:
	lw      $t0, -20($fp)
	beq     $0, $t0, $LKDHGF7
	lw      $t1, -24($fp)
	beq     $0, $t1, $LKDHGF7
	li      $t2, 1
	sw      $t2, -28($fp)
	b       $LKDHGF8
$LKDHGF7:
	move    $t2, $0
	sw      $t2, -28($fp)
$LKDHGF8:
	lw      $t0, 24($fp)
	lw      $t1, 28($fp)
	subu    $t2, $t0, $t1
	bgez    $t2, $LKDHGF9
	nop     
	move    $t2, $0
	sw      $t2, -32($fp)
	b       $LKDHGF10
	nop     
$LKDHGF9:
	li      $t2, 1
	sw      $t2, -32($fp)
	b       $LKDHGF10
	nop     
$LKDHGF10:
	lw      $t0, -28($fp)
	bne     $0, $t0, $LKDHGF11
	nop     
	lw      $t1, -32($fp)
	bne     $0, $t1, $LKDHGF11
	nop     
	move    $t2, $0
	sw      $t2, -36($fp)
	b       $LKDHGF12
	nop     
$LKDHGF11:
	li      $t2, 1
	sw      $t2, -36($fp)
	b       $LKDHGF12
	nop     
$LKDHGF12:
	lw      $t0, 32($fp)
	lw      $t1, -4($fp)
	subu    $t2, $t0, $t1
	bgez    $t2, $LKDHGF13
	nop     
	move    $t2, $0
	sw      $t2, -40($fp)
	b       $LKDHGF14
	nop     
$LKDHGF13:
	li      $t2, 1
	sw      $t2, -40($fp)
	b       $LKDHGF14
	nop     
$LKDHGF14:
	addiu   $sp, $sp, -28		# Allocate more memory
	lw      $t0, -36($fp)
	bne     $0, $t0, $LKDHGF15
	nop     
	lw      $t1, -40($fp)
	bne     $0, $t1, $LKDHGF15
	nop     
	move    $t2, $0
	sw      $t2, -44($fp)
	b       $LKDHGF16
	nop     
$LKDHGF15:
	li      $t2, 1
	sw      $t2, -44($fp)
	b       $LKDHGF16
	nop     
$LKDHGF16:
	lui     $t9, %hi(glob3)
	lw      $t0, %lo(glob3)($t9)
	lui     $t9, %hi(glob2)
	lw      $t1, %lo(glob2)($t9)
	subu    $t2, $t0, $t1
	bgez    $t2, $LKDHGF17
	nop     
	move    $t2, $0
	sw      $t2, -48($fp)
	b       $LKDHGF18
	nop     
$LKDHGF17:
	li      $t2, 1
	sw      $t2, -48($fp)
	b       $LKDHGF18
	nop     
$LKDHGF18:
	lw      $t0, -44($fp)
	bne     $0, $t0, $LKDHGF19
	nop     
	lw      $t1, -48($fp)
	bne     $0, $t1, $LKDHGF19
	nop     
	move    $t2, $0
	sw      $t2, -52($fp)
	b       $LKDHGF20
	nop     
$LKDHGF19:
	li      $t2, 1
	sw      $t2, -52($fp)
	b       $LKDHGF20
	nop     
$LKDHGF20:
	lw      $v0, -52($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 80		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end fn

