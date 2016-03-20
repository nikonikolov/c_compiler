	.text   
	.align	2
	.globl f
	.ent f
	.type f, @function
f:
	addiu   $sp, $sp, -24		# Allocate memory on the stack
	sw      $fp, 20($sp)		# Store value of $fp on the bottom of the stack
	addiu   $fp, $sp, 16		# Point $fp to the bottom of the available memory
	sw      $ra, 0($fp)		# Store the return address for the current subroutine
	sw      $a0, -4($fp)
	sw      $a1, -8($fp)
	li      $t0, 1
	sw      $t0, -12($fp)
	addiu   $sp, $sp, -28		# Allocate more memory
	li      $t0, 2
	sw      $t0, -16($fp)
	li      $t0, 3
	sw      $t0, -20($fp)
	lw      $t0, -12($fp)
	lw      $t1, -16($fp)
	addu    $t2, $t0, $t1
	sw      $t2, -28($fp)
	lw      $t0, -28($fp)
	lw      $t1, -20($fp)
	subu    $t2, $t0, $t1
	sw      $t2, -24($fp)
	lw      $v0, -24($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, 4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 52		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end f

