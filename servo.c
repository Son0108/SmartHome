int16 Ton=752, ChuKy=1000;

void Delay4us(int16 t);
long Convert(float x, float in_min, float in_max, float out_min, float out_max);
void Write(long Goc, signed long t);

void Delay4us(int16 t)
{
   while(t>0) t--;
}

long Convert(float x, float in_min, float in_max, float out_min, float out_max)
{
   float tam = (out_max - out_min)/(in_max - in_min);
   tam = (x - in_min) * tam;
   tam =  tam + out_min;
   return tam;
}

void Write(long Goc, signed long t)
{
   Ton = Convert(Goc,0,180, 247,1250);
   t=t/20;
   for(;t>0;t--)
   {
      output_bit(PIN_C5,1);
      Delay4us(Ton);
      output_bit(PIN_C5,0);
      Delay4us(ChuKy-Ton);       
   }
}
