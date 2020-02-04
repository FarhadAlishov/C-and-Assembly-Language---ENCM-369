# array-sum.asm
# ENCM 369 Winter 2019 Lab 2 Exercise C Part 3

# Start-up and clean-up code copied from stub1.asm

# BEGINNING of start-up & clean-up code.  Do NOT edit this code.
	.data
exit_msg_1:
	.asciiz	"***About to exit. main returned "
exit_msg_2:
	.asciiz	".***\n"
main_rv:
	.word	0
	
	.text
	# adjust $sp, then call main
	addi	$t0, $zero, -32		# $t0 = 0xffffffe0
	and	$sp, $sp, $t0		# round $sp down to multiple of 32
	jal	main
	nop
	
	# when main is done, print its return value, then halt the program
	sw	$v0, main_rv	
	la	$a0, exit_msg_1
	addi	$v0, $zero, 4
	syscall
	nop
	lw	$a0, main_rv
	addi	$v0, $zero, 1
	syscall
	nop
	la	$a0, exit_msg_2
	addi	$v0, $zero, 4
	syscall
	nop
	addi	$v0, $zero, 10
	syscall
	nop	
# END of start-up & clean-up code.


# Global variables
	.data
	# int abc[ ] = {-32, -8, -4, -16, -128, -64}
	.globl	abc	
abc:	.word	-32, -8, -4, -16, -128, -64

# Hint for checking that the original program works:
# The sum of the six array elements is -252, which will be represented
# as 0xffffff04 in a MIPS GPR.

# Hint for checking that your final version of the program works:
# The mimimum of the four array elements is -128, which will be represented
# as 0xffffff80 in a MIPS GPR.


# int main(void)
#
# local variable	register
#   int *p		$s0
#   int *end		$s1
#   int sum		$s2
#   int min		$s3  (to be used when students enhance the program)

	.text
	.globl	main
main:
	la	$s0, abc		# p = abc
	addi	$s1, $s0, 24		# end = p + 6
	add	$s2, $zero, $zero	# sum = 0 
L1:
	beq	$s0, $s1, L2		# if (p == end) goto L2
	lw	$t9, ($s0)		# $t9 = *p
	add	$s2, $s2, $t9		# sum += $t9
	addi	$s0, $s0, 4		# p++
	j	L1
L2:		
	add	$v0, $zero, $zero	# return value from main = 0
	jr	$ra
