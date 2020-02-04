# ex4D.asm
# ENCM 369 Winter 2019 Lab 4 Exercise D

	.text
	# Put some bit patterns into $t8 and $t9
	lui	$t8, 0x5700
	ori	$t8, 0x00ad
	lui	$t9, 0x3c01
	ori	$t9, 0x8074
	
	# Use various logical instruction to give values to $t0-$t5,
	or	$t0, $t8, $t9
	and	$t1, $t8, $t9
	xor	$t2, $t8, $t9
	nor	$t3, $t8, $zero
	sll	$t4, $t8, 4
	srl	$t5, $t9, 2
	
	# Terminate the program.
	addi	$v0, $zero, 10
	syscall
