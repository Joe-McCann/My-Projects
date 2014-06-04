#line 1 "C:/Users/Joe/MikroC/ECET PROJECT.c"

sbit LCD_RS at LATB4_bit;
sbit LCD_EN at LATB5_bit;
sbit LCD_D4 at LATB0_bit;
sbit LCD_D5 at LATB1_bit;
sbit LCD_D6 at LATB2_bit;
sbit LCD_D7 at LATB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

bit flag;
unsigned short score;
unsigned short trips;
unsigned short fscore;
char txt1[5];
char txt2[5];
char txt3[5];

void init()
{

 flag = 0;
 score = 0;
 trips = 0;
 fscore = 0;
 ShortToStr(0,txt1);
 ShortToStr(0,txt2);
 ShortToStr(0,txt3);


 ANSELD = 0;
 ANSELB = 0;
 ANSELC = 0;
 ANSELE = 0;


 TRISC = 0x00;
 TRISD = 0x00;
 TRISE = 0x02;
 TRISB = 0xC0;


 IOCB7_bit = 1;
 IOCB6_bit = 1;


 RBIE_bit = 1;
 RBIF_bit = 0;
 GIE_bit = 1;


 LATD = 0x00;
 PORTC = 0x00;
 PORTE = 0x00;
}

void interrupt(){


 if(RBIF_bit == 1) {


 if (PORTB.F7 == 1)
 {

 PORTE.F0 = 1;
 Delay_ms(500);
 PORTE.F0 = 0;

 ++trips;



 while(1)
 {
 if(PORTE.F1 == 1)
 {
 break;
 }
 }
 }


 if (PORTB.F6 == 1)
 {
 flag = 1;
 }
 RBIF_bit = 0;

 }
}

void main() {

 init();
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 while ( score <= 180 )
 {
 Delay_ms(1000);
 ++score;
 ShortToStr(score, txt1);
 ShortToStr(trips, txt2);
 Lcd_Out(1,1,"Times Broken: ");
 Lcd_Out(1,16, (txt2));
 Lcd_Out(2,1,"Time Taken: ");
 Lcd_Out(2,13,(txt1));
 if (flag)
 {
 break;
 }

 }

 GIE_bit = 0;
 fscore = (180 - score)/trips;

 ShortToStr(fscore, txt3);

 while (1)
 {
 PORTC = (180 - score) / trips;
 PORTD = trips;
 Lcd_Out(3,1,"Score: ");
 Lcd_Out(3,8,txt3);
 }


}
