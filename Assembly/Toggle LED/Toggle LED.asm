 include <p16f887.inc>

 ORG 0 
 CLRWDT
 goto init 
 ORG 4
 goto isr 
 ORG 5

 
init: 

	BANKSEL IOCB

	CLRF IOCB
	BSF IOCB, 0x0 
	BANKSEL TRISB

	MOVLW 0x80
	MOVWF TRISB
	BANKSEL PORTB

	CLRF 0x20
	CLRF PORTB
	
	goto main

main: 
	NOP
	goto main 

isr:
	INCF 0x20 
	MOVFW 0x20
	MOVWF PORTB
	RETFIE 	