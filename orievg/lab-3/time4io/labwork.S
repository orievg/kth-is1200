  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.global delay
.global time2string

.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #

  .data
  .align 2
mytime: .word 0x5957
timstr: .ascii "text more text lots of text\0"
  .text
main:
  # print timstr
  la  $a0,timstr
  li  $v0,4
  syscall
  nop
  # wait a little
  li  $a0,2
  jal delay
  nop
  # call tick
  la  $a0,mytime
  jal tick
  nop
  # call your function time2string
  la  $a0,timstr
  la  $t0,mytime
  lw  $a1,0($t0)
  jal time2string
  nop
  # print a newline
  li  $a0,10
  li  $v0,11
  syscall
  nop
  # go back and do it all again
  j main
  nop
# tick: update time pointed to by $a0
tick: lw  $t0,0($a0)  # get time
  addiu $t0,$t0,1 # increase
  andi  $t1,$t0,0xf # check lowest digit
  sltiu $t2,$t1,0xa # if digit < a, okay
  bnez  $t2,tiend
  nop
  addiu $t0,$t0,0x6 # adjust lowest digit
  andi  $t1,$t0,0xf0  # check next digit
  sltiu $t2,$t1,0x60  # if digit < 6, okay
  bnez  $t2,tiend
  nop
  addiu $t0,$t0,0xa0  # adjust digit
  andi  $t1,$t0,0xf00 # check minute digit
  sltiu $t2,$t1,0xa00 # if digit < a, okay
  bnez  $t2,tiend
  nop
  addiu $t0,$t0,0x600 # adjust digit
  andi  $t1,$t0,0xf000  # check last digit
  sltiu $t2,$t1,0x6000  # if digit < 6, okay
  bnez  $t2,tiend
  nop
  addiu $t0,$t0,0xa000  # adjust last digit
tiend:  sw  $t0,0($a0)  # save updated result
  jr  $ra   # return
  nop

delay:
  li $t4,1
   #a0=ms is the input
  li $t2, 0       # int i = 0
  li $t3, 4000000     # const=4711
  while_loop: 
    blez  $a0, finish                                
    nop
  
    sub $a0,$a0,$t4 # ms = ms – 1;
      for_loop:
        beq $t2, $t3, while_loop  #  i < const;
        nop
        
        addi $t2, $t2, 1  # i = i + 1 
        j for_loop 
        nop
        
        #should be going on for "const" times 
  finish:
  jr $ra
  nop

 hexasc:
  # takes last 4 bits in a0 and converts to hexa.
  andi  $t2, $a2, 0xf
  slti  $t0, $t2, 0xa

  bne   $t0, 1, else
  addi  $v0, $t2, 0x30
  j     out
else:
  addi  $v0, $t2, 55
out:
  jr    $ra

time2string:
  PUSH  $ra
  add $t1, $0, $a1 #last second
  srl $t2, $a1, 4  
  srl $t3, $a1, 8 #last 
  srl $t4, $a1, 12  
  andi  $t2,$t2,0xf
  andi  $t1,$t1,0xf
  beq $t2, $0, PRE_DING
  nop
point:  
  move  $a2, $t4 #extract minutes
  
  jal hexasc
  nop
  
  sb  $v0, 0($a0)
  
  move  $a2, $t3
  
  jal hexasc
  nop
  
  sb  $v0, 1($a0)
  
  addi  $t5, $0, 0x3A #print the semicolon
  sb  $t5, 2($a0)
  
  move  $a2, $t2  #extract seconds
  
  jal hexasc
  nop
  
  sb  $v0, 3($a0)
  
  move  $a2, $t1
  
  jal hexasc
  nop
  
  sb  $v0, 4($a0)
  #so text doesnt print
  addi  $t5, $0, 0x0
  sb  $t5, 5($a0)
  POP $ra
  jr  $ra
  nop
PRE_DING:
  beq $t1,$0,DING
  
  nop
  j   point
  nop
DING: 
  addi $t4,$0,0x44
  sb  $t4, 0($a0)
  
  addi $t4,$0, 0x49
  sb  $t4, 1($a0)
  
  addi $t4,$0, 0x4e
  sb  $t4, 2($a0)
  
  addi $t4,$0,  0x47
  sb  $t4, 3($a0)
  
  addi  $t5, $0, 0x0
  sb  $t5, 4($a0)
  
  POP $ra
  jr $ra 
  nop
  

  li    $t0, 0x00
  sb    $t0, 5($a0)
  jr    $ra
  nop


