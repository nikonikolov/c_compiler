	.text   
	.align	2
	.globl main
	.ent main
	.type main, @function
main:
	addiu   $sp, $sp, -24		# Allocate memory on the stack
	sw      $fp, 20($sp)		# Store value of fp on the bottom of the stack
	addiu   $fp, $sp, 16		# Modify fp to point to the the bottom of the available stack memory
	sw      $ra, 0($fp)		# Store the return address for the subroutine
	li      $t0, 1
	sw      $t0, 4($fp)
	li      $t0, 2
	sw      $t0, 8($fp)
	li      $t0, 3
	sw      $t0, 12($fp)
	addiu   $sp, $sp, -28		# Allocate more memory
	lw      $t0, 4($fp)
	sw      $t0, 24($fp)
	lw      $t0, 8($fp)
	sw      $t0, 28($fp)
	lw      $t0, 24($fp)
	lw      $t1, 28($fp)
	addu    $t2, $t0, $t1
	sw      $t2, 20($fp)
	lw      $t0, 12($fp)
	sw      $t0, 32($fp)
	lw      $t0, 20($fp)
	lw      $t1, 32($fp)
	subu    $t2, $t0, $t1
	sw      $t2, 16($fp)
	lw      $t0, 16($fp)
	sw      $t0, 36($fp)
	lw      $v0, 36($fp)
	lw      $ra, 0($fp)		# Load return address in register 31
	lw      $fp, -4($fp)		# Restore the value of the frame pointer
	addiu   $sp, $sp, 52		# Restore the value of the stack pointer
	j       $ra
	nop     

	.end main

