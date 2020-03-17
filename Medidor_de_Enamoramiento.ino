const int Pin_del_Sensor = A0;
const float Temperatura_de_Referencia = -25.0;
void setup() 
{
  Serial.begin(9600);//Abrir el puerto serie
  for (int NumeroPin = 2; NumeroPin < 5; NumeroPin ++)
  {
    pinMode (NumeroPin, OUTPUT);
    digitalWrite (NumeroPin, LOW);
   }   
}
void loop() 
{
  int Valor_del_Sensor = analogRead (Pin_del_Sensor);
  Serial.print ("Valor del Sensor:");
  Serial.print (Valor_del_Sensor);
  // Convertir la lectura ADC a tensión 
  float Tension = (Valor_del_Sensor/1024.0)*5.0;
  Serial.print ("Voltios:");
  Serial.print (Tension);
  Serial.print (", grados C:");
  // Convertir la tensión en temperatura en valores en grados
  float Temperatura = (Tension - 0.5) * 100;
  Serial.println (Temperatura);
  if (Temperatura < Temperatura_de_Referencia)
    {
      digitalWrite (2, LOW);
      digitalWrite (3, LOW);
      digitalWrite (4, LOW);
     }
    else if (Temperatura >= Temperatura_de_Referencia + 2 
            && Temperatura < Temperatura_de_Referencia + 4)
    {
      digitalWrite (2, HIGH);
      digitalWrite (3, LOW);
      digitalWrite (4, LOW);
    }
  else if (Temperatura >= Temperatura_de_Referencia + 4 
          && Temperatura < Temperatura_de_Referencia + 6)
    {
      digitalWrite (2, HIGH);
      digitalWrite (3, HIGH);
      digitalWrite (4, LOW);
     }
   else if (Temperatura >= Temperatura_de_Referencia + 6)
    {
      digitalWrite (2, HIGH);
      digitalWrite (3, HIGH);
      digitalWrite (4, HIGH);
    }
      delay(100);
}
