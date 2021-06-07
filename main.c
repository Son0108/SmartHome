#include <main.h>
int8 nhietdo=27,doam=87;
#INT_RDA
void receive_data (void)
{
   char C;
   if(kbhit() == 1) {
      C = getc();
      if(C == '1')
       {
         nhietdo ++;  
          }
       else if( C == '2')
       {
            nhietdo --;
         }
         else if(C == '3')
          {
            doam ++;  
          }
      else if(C == '4')
       {
         doam --;
      }
   }
}
void tu_dong(void) {
   if(doam < gia_tri[0] && gia_tri[2] <= nhietdo) {
      Write(51,1000);
      output_high(PIN_D2);
      output_high(PIN_D3);
      output_high(PIN_C4);
   } else if (gia_tri[0]<= doam && nhietdo < gia_tri[2]) {
      Write(0,1000);
      output_high(PIN_D2);
      output_high(PIN_D3);
      output_high(PIN_C4);
   } else if (doam < gia_tri[0] && nhietdo < gia_tri[2]) {
      Write(0,1000);
      output_high(PIN_D2);
      output_high(PIN_D3);
      output_high(PIN_C4);
      if(gia_tri[0]>= doam && nhietdo >gia_tri[2]){
         Write(51,1000);
         output_high(PIN_D2);
         output_high(PIN_D3);
         output_high(PIN_C4);
      }
   } else {
      Write(51,1000);
      output_low(PIN_D2);
      output_low(Pin_D3);
      output_low(PIN_C4);
   }
}
void main()
{  

   enable_interrupts(INT_RDA);//cho phep ngat uart
   enable_interrupts(GLOBAL);//cho phep ngat toan cuc
   lcd_Init();
   output_float(DHT11_pin);
   delay_ms(1000);
   lcd_gotoxy(1,1);
   lcd_putc(223);
   lcd_putc("C: ");
   lcd_gotoxy(1,2);
   lcd_putc("DO AM:     %   %");
   Write(51,1000);
   output_low(PIN_D2);
   output_low(PIN_D3);
   output_low(PIN_C4);
   while(TRUE)
   {
      get_data();
      lcd_gotoxy(4,1);
      printf(lcd_putc,"%1u.%01u", gia_tri[2], gia_tri[3]);
      lcd_gotoxy(7, 2);                              
      printf(lcd_putc, "%1u.%01u", gia_tri[0], gia_tri[1]);  
      lcd_gotoxy(13,1);
      printf(lcd_putc,"%3u",nhietdo);
      lcd_gotoxy(13,2);
      printf(lcd_putc,"%3u",doam);                  
      delay_ms(1000);
       if(input(PIN_C1)==0) {
         nhietdo++;
      }
      if(input(PIN_C0)==0) {
         nhietdo--;
      }
      if(input(PIN_D0)==0) {
         doam++;
      }
      if(input(PIN_D1)==0) {
         doam--;
      }
      tu_dong();
      printf("%3u  %3u",gia_tri[2],gia_tri[0]);
      printf("%3u  %3u",nhietdo,doam);
   }
}
