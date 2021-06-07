#define DHT11_pin PIN_A0
int8 gia_tri[5];
int8 get_byte();
void get_data();

int16 tg_loi;
int8 get_byte() // doc 1 byte du lieu tu dht11
{                
   int8 i; // khai bao bien tao vong lap   
   int8 gia_tri_byte = 0; // khai bao bien gia tri doc duoc
   for(i=0;i<8;i++) // tao vong lap 8 lan de thu 8 bit        
   { 
      gia_tri_byte <<= 1; // dich trai gia tri doc 
      tg_loi=0;
      while(!input(DHT11_pin));
      delay_us(28); // tao thoi gian tre 30us 
      if(input(DHT11_pin)) 
      { 
          gia_tri_byte |= 1; // neu chan cam bien muc 1 thi nhan gia tri bit la 1, mac dinh se la 0 
      } 
      tg_loi=0;
      while(input(DHT11_pin));
   } 
   return gia_tri_byte; // tra ve gia tri doc duoc 
} 
void get_data()
{
   int8 i;
   output_high(DHT11_pin);
   output_low(DHT11_pin);
   delay_ms(18);
   output_high(DHT11_pin);
   delay_us(186);
   for(i=0;i<=4;i++) {
      gia_tri[i] = get_byte();
      }
    output_high(DHT11_pin);
}
