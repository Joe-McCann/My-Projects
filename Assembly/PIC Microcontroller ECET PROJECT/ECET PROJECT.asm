
_init:

;ECET PROJECT.c,24 :: 		void init()   //Initialize Variables and registers
;ECET PROJECT.c,27 :: 		flag = 0;
	BCF         _flag+0, BitPos(_flag+0) 
;ECET PROJECT.c,28 :: 		score = 0;
	CLRF        _score+0 
;ECET PROJECT.c,29 :: 		trips = 0;
	CLRF        _trips+0 
;ECET PROJECT.c,30 :: 		fscore = 0;
	CLRF        _fscore+0 
;ECET PROJECT.c,31 :: 		ShortToStr(0,txt1);
	CLRF        FARG_ShortToStr_input+0 
	MOVLW       _txt1+0
	MOVWF       FARG_ShortToStr_output+0 
	MOVLW       hi_addr(_txt1+0)
	MOVWF       FARG_ShortToStr_output+1 
	CALL        _ShortToStr+0, 0
;ECET PROJECT.c,32 :: 		ShortToStr(0,txt2);
	CLRF        FARG_ShortToStr_input+0 
	MOVLW       _txt2+0
	MOVWF       FARG_ShortToStr_output+0 
	MOVLW       hi_addr(_txt2+0)
	MOVWF       FARG_ShortToStr_output+1 
	CALL        _ShortToStr+0, 0
;ECET PROJECT.c,33 :: 		ShortToStr(0,txt3);
	CLRF        FARG_ShortToStr_input+0 
	MOVLW       _txt3+0
	MOVWF       FARG_ShortToStr_output+0 
	MOVLW       hi_addr(_txt3+0)
	MOVWF       FARG_ShortToStr_output+1 
	CALL        _ShortToStr+0, 0
;ECET PROJECT.c,36 :: 		ANSELD = 0;
	CLRF        ANSELD+0 
;ECET PROJECT.c,37 :: 		ANSELB = 0;
	CLRF        ANSELB+0 
;ECET PROJECT.c,38 :: 		ANSELC = 0;
	CLRF        ANSELC+0 
;ECET PROJECT.c,39 :: 		ANSELE = 0;
	CLRF        ANSELE+0 
;ECET PROJECT.c,42 :: 		TRISC = 0x00;
	CLRF        TRISC+0 
;ECET PROJECT.c,43 :: 		TRISD = 0x00;
	CLRF        TRISD+0 
;ECET PROJECT.c,44 :: 		TRISE = 0x02;
	MOVLW       2
	MOVWF       TRISE+0 
;ECET PROJECT.c,45 :: 		TRISB = 0xC0;
	MOVLW       192
	MOVWF       TRISB+0 
;ECET PROJECT.c,48 :: 		IOCB7_bit = 1;
	BSF         IOCB7_bit+0, BitPos(IOCB7_bit+0) 
;ECET PROJECT.c,49 :: 		IOCB6_bit = 1;
	BSF         IOCB6_bit+0, BitPos(IOCB6_bit+0) 
;ECET PROJECT.c,52 :: 		RBIE_bit = 1;
	BSF         RBIE_bit+0, BitPos(RBIE_bit+0) 
;ECET PROJECT.c,53 :: 		RBIF_bit = 0;
	BCF         RBIF_bit+0, BitPos(RBIF_bit+0) 
;ECET PROJECT.c,54 :: 		GIE_bit = 1;
	BSF         GIE_bit+0, BitPos(GIE_bit+0) 
;ECET PROJECT.c,57 :: 		LATD = 0x00;
	CLRF        LATD+0 
;ECET PROJECT.c,58 :: 		PORTC = 0x00;
	CLRF        PORTC+0 
;ECET PROJECT.c,59 :: 		PORTE = 0x00;
	CLRF        PORTE+0 
;ECET PROJECT.c,60 :: 		}
L_end_init:
	RETURN      0
; end of _init

_interrupt:

;ECET PROJECT.c,62 :: 		void interrupt(){   //ISR
;ECET PROJECT.c,65 :: 		if(RBIF_bit == 1) {    //Used to make sure that a PortB interrupt occured
	BTFSS       RBIF_bit+0, BitPos(RBIF_bit+0) 
	GOTO        L_interrupt0
;ECET PROJECT.c,68 :: 		if (PORTB.F7 == 1) //The lazer was tripped
	BTFSS       PORTB+0, 7 
	GOTO        L_interrupt1
;ECET PROJECT.c,71 :: 		PORTE.F0 = 1;   //Sound the buzzer for 500ms
	BSF         PORTE+0, 0 
;ECET PROJECT.c,72 :: 		Delay_ms(500);
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_interrupt2:
	DECFSZ      R13, 1, 1
	BRA         L_interrupt2
	DECFSZ      R12, 1, 1
	BRA         L_interrupt2
	DECFSZ      R11, 1, 1
	BRA         L_interrupt2
	NOP
	NOP
;ECET PROJECT.c,73 :: 		PORTE.F0 = 0;
	BCF         PORTE+0, 0 
;ECET PROJECT.c,75 :: 		++trips; //Increment the break counter
	INCF        _trips+0, 1 
;ECET PROJECT.c,79 :: 		while(1)
L_interrupt3:
;ECET PROJECT.c,81 :: 		if(PORTE.F1 == 1)
	BTFSS       PORTE+0, 1 
	GOTO        L_interrupt5
;ECET PROJECT.c,83 :: 		break; //Exit loop, reset button has been pressed
	GOTO        L_interrupt4
;ECET PROJECT.c,84 :: 		}
L_interrupt5:
;ECET PROJECT.c,85 :: 		}
	GOTO        L_interrupt3
L_interrupt4:
;ECET PROJECT.c,86 :: 		}
L_interrupt1:
;ECET PROJECT.c,89 :: 		if (PORTB.F6 == 1)  //Was the course completed?
	BTFSS       PORTB+0, 6 
	GOTO        L_interrupt6
;ECET PROJECT.c,91 :: 		flag = 1;  //Course was completed
	BSF         _flag+0, BitPos(_flag+0) 
;ECET PROJECT.c,92 :: 		}
L_interrupt6:
;ECET PROJECT.c,93 :: 		RBIF_bit = 0;              // Interrupt was serviced
	BCF         RBIF_bit+0, BitPos(RBIF_bit+0) 
;ECET PROJECT.c,95 :: 		}
L_interrupt0:
;ECET PROJECT.c,96 :: 		}
L_end_interrupt:
L__interrupt15:
	RETFIE      1
; end of _interrupt

_main:

;ECET PROJECT.c,98 :: 		void main() {    //Main function
;ECET PROJECT.c,100 :: 		init(); //Initialize all registers and variables
	CALL        _init+0, 0
;ECET PROJECT.c,101 :: 		Lcd_Init();
	CALL        _Lcd_Init+0, 0
;ECET PROJECT.c,102 :: 		Lcd_Cmd(_LCD_CLEAR);
	MOVLW       1
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ECET PROJECT.c,103 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW       12
	MOVWF       FARG_Lcd_Cmd_out_char+0 
	CALL        _Lcd_Cmd+0, 0
;ECET PROJECT.c,104 :: 		while ( score <= 180 ) //This will loop for 180 seconds, or 3 minutes
L_main7:
	MOVF        _score+0, 0 
	SUBLW       180
	BTFSS       STATUS+0, 0 
	GOTO        L_main8
;ECET PROJECT.c,106 :: 		Delay_ms(1000); //Wait for one second
	MOVLW       11
	MOVWF       R11, 0
	MOVLW       38
	MOVWF       R12, 0
	MOVLW       93
	MOVWF       R13, 0
L_main9:
	DECFSZ      R13, 1, 1
	BRA         L_main9
	DECFSZ      R12, 1, 1
	BRA         L_main9
	DECFSZ      R11, 1, 1
	BRA         L_main9
	NOP
	NOP
;ECET PROJECT.c,107 :: 		++score; //Increase the score varaible to signify that more time has been taken
	INCF        _score+0, 1 
;ECET PROJECT.c,108 :: 		ShortToStr(score, txt1);
	MOVF        _score+0, 0 
	MOVWF       FARG_ShortToStr_input+0 
	MOVLW       _txt1+0
	MOVWF       FARG_ShortToStr_output+0 
	MOVLW       hi_addr(_txt1+0)
	MOVWF       FARG_ShortToStr_output+1 
	CALL        _ShortToStr+0, 0
;ECET PROJECT.c,109 :: 		ShortToStr(trips, txt2);
	MOVF        _trips+0, 0 
	MOVWF       FARG_ShortToStr_input+0 
	MOVLW       _txt2+0
	MOVWF       FARG_ShortToStr_output+0 
	MOVLW       hi_addr(_txt2+0)
	MOVWF       FARG_ShortToStr_output+1 
	CALL        _ShortToStr+0, 0
;ECET PROJECT.c,110 :: 		Lcd_Out(1,1,"Times Broken: ");
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr1_ECET_32PROJECT+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr1_ECET_32PROJECT+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ECET PROJECT.c,111 :: 		Lcd_Out(1,16, (txt2));
	MOVLW       1
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       16
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _txt2+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_txt2+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ECET PROJECT.c,112 :: 		Lcd_Out(2,1,"Time Taken: ");
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr2_ECET_32PROJECT+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr2_ECET_32PROJECT+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ECET PROJECT.c,113 :: 		Lcd_Out(2,13,(txt1));
	MOVLW       2
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       13
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _txt1+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_txt1+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ECET PROJECT.c,114 :: 		if (flag) //Has the course been completed?
	BTFSS       _flag+0, BitPos(_flag+0) 
	GOTO        L_main10
;ECET PROJECT.c,116 :: 		break; //Exit the loop for time, the course has been beaten
	GOTO        L_main8
;ECET PROJECT.c,117 :: 		}
L_main10:
;ECET PROJECT.c,119 :: 		}
	GOTO        L_main7
L_main8:
;ECET PROJECT.c,121 :: 		GIE_bit = 0; //Disable interrupts to prevent from score from decreasing after completion
	BCF         GIE_bit+0, BitPos(GIE_bit+0) 
;ECET PROJECT.c,122 :: 		fscore = (180 - score)/trips;
	MOVF        _score+0, 0 
	SUBLW       180
	MOVWF       R0 
	CLRF        R1 
	MOVLW       0
	SUBWFB      R1, 1 
	MOVF        _trips+0, 0 
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_S+0, 0
	MOVF        R0, 0 
	MOVWF       _fscore+0 
;ECET PROJECT.c,124 :: 		ShortToStr(fscore, txt3);
	MOVF        R0, 0 
	MOVWF       FARG_ShortToStr_input+0 
	MOVLW       _txt3+0
	MOVWF       FARG_ShortToStr_output+0 
	MOVLW       hi_addr(_txt3+0)
	MOVWF       FARG_ShortToStr_output+1 
	CALL        _ShortToStr+0, 0
;ECET PROJECT.c,126 :: 		while (1) //Keep the program running to display the score
L_main11:
;ECET PROJECT.c,128 :: 		PORTC = (180 - score) / trips; //Display the score.
	MOVF        _score+0, 0 
	SUBLW       180
	MOVWF       R0 
	CLRF        R1 
	MOVLW       0
	SUBWFB      R1, 1 
	MOVF        _trips+0, 0 
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_S+0, 0
	MOVF        R0, 0 
	MOVWF       PORTC+0 
;ECET PROJECT.c,129 :: 		PORTD = trips; //Display the beaks
	MOVF        _trips+0, 0 
	MOVWF       PORTD+0 
;ECET PROJECT.c,130 :: 		Lcd_Out(3,1,"Score: ");
	MOVLW       3
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       1
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       ?lstr3_ECET_32PROJECT+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(?lstr3_ECET_32PROJECT+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ECET PROJECT.c,131 :: 		Lcd_Out(3,8,txt3);
	MOVLW       3
	MOVWF       FARG_Lcd_Out_row+0 
	MOVLW       8
	MOVWF       FARG_Lcd_Out_column+0 
	MOVLW       _txt3+0
	MOVWF       FARG_Lcd_Out_text+0 
	MOVLW       hi_addr(_txt3+0)
	MOVWF       FARG_Lcd_Out_text+1 
	CALL        _Lcd_Out+0, 0
;ECET PROJECT.c,132 :: 		}
	GOTO        L_main11
;ECET PROJECT.c,135 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
