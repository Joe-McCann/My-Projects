// Lcd module connections from "Lcd.c"  //
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
///////////////////////////////////////////

////////////// VARIABLES /////////////////

bit flag; //Local flag that is checked for the eoc
unsigned short score;    //Score short
unsigned short trips; //How many times has the beam been tripped?
unsigned short fscore; // The final score
char txt1[5];  // String for the time taken
char txt2[5];  // String for the amount of trips
char txt3[5];  // String for the final score

//////////////////////////////////////////

void init()   //Initialize Variables and registers
{
//Local Variables//
  flag = 0;
  score = 0;
  trips = 0;
  fscore = 0;
 ShortToStr(0,txt1);
 ShortToStr(0,txt2);
 ShortToStr(0,txt3);

//Disable Analog Ports//
  ANSELD = 0;
  ANSELB = 0;
  ANSELC = 0;
  ANSELE = 0;
  
//Set Ports to Outputs or Inputs//
  TRISC = 0x00;
  TRISD = 0x00;
  TRISE = 0x02;
  TRISB = 0xC0;
  
//Set the correct bits to watch for interrupts/
  IOCB7_bit = 1;
  IOCB6_bit = 1;
  
//Enable interrupts//
  RBIE_bit = 1;
  RBIF_bit = 0;
  GIE_bit = 1;
  
//Clear the Output Ports//
  LATD = 0x00;
  PORTC = 0x00;
  PORTE = 0x00;
  
//Initialize the LCD//
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
}

void interrupt(){   //ISR


  if(RBIF_bit == 1) {    //Used to make sure that a PortB interrupt occured
  
  //Detecting which button was pressed
    if (PORTB.F7 == 1) //The lazer was tripped
    {
    
    PORTE.F0 = 1;   //Sound the buzzer for 500ms
    Delay_ms(500);
    PORTE.F0 = 0;
    
    ++trips; //Increment the break counter
   // ShortToStr(trips, txt2);
    
    //Wait for the reset button to be hit
    while(1)
    {
     if(PORTE.F1 == 1)
     {
        break; //Exit loop, reset button has been pressed
     }
    }
    }   
    
    
    if (PORTB.F6 == 1)  //Was the course completed?
    {
    flag = 1;  //Course was completed
    }
    RBIF_bit = 0;              // Interrupt was serviced

  }
}

void main() {    //Main function

  init(); //Initialize all registers and variables


  while ( score <= 180 ) //This will loop for 180 seconds, or 3 minutes
  {
        Delay_ms(1000); //Wait for one second
        ++score; //Increase the score varaible to signify that more time has been taken
        
        ShortToStr(score, txt1);  //Create string versions of my shorts, so they can be displayed on the screen
        ShortToStr(trips, txt2);
        
        Lcd_Out(1,1,"Times Broken: "); //Row for the amount of times broken
        Lcd_Out(1,16, (txt2));  //Display breaks
        Lcd_Out(2,1,"Time Taken: ");  //Row for the amount of time taken so far
        Lcd_Out(2,13,(txt1)); //Display time
        
        if (flag) //Has the course been completed?
        {
        break; //Exit the loop for time, the course has been beaten
        }

  }

  GIE_bit = 0; //Disable interrupts to prevent from score from decreasing after completion
  
  fscore = (180 - score)/trips; //Calculate the final score
  
  ShortToStr(fscore, txt3); //Make the final score into a string for display
  
  while (1) //Keep the program running to display the score
  {
   PORTC = (180 - score) / trips; //Display the score.  FOR TESTING PURPOSES ONLY
   PORTD = trips; //Display the beaks  FOR TESTING PURPOSES ONLY
   
   Lcd_Out(3,1,"Score: ");  //Row to Display the final score
   Lcd_Out(3,8,txt3); //Display the final score
  }
  

}