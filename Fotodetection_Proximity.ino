int A=11; //Sucesivos Leds//
int B=12;
int C=13;
int foto=1; //Fotoresistencia en el pin analogo A1//
int measure=0;
int light=0;
int distancia;
int tiempo;

void setup()
{
  {
  Serial.begin(9600);
  pinMode(9, OUTPUT); //Envio señal//
  pinMode(8, INPUT); //Recuperamos señal//
  pinMode(10,OUTPUT); //Actuador//
  pinMode(A,OUTPUT); //declaramos los leds como salidas//
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
 }
}

void loop() 
{
   {
  digitalWrite(9,LOW); 
  delayMicroseconds(5);
  digitalWrite(9, HIGH); 
  delayMicroseconds(10);
  tiempo=pulseIn(8, HIGH); //Calcula el tiempo que tarda en llegar el pulso//
  distancia= int(0.017*tiempo); //Calculamos la distancia//
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(1000);
  {
    if (distancia < 100)
    digitalWrite(10, HIGH); 
    if (distancia > 100)
    digitalWrite(10, LOW);
  }
  }
 measure=analogRead (foto); //lectura de la fotoresistencia//
 Serial.println("Lectura ");
 Serial.println(measure);
 delay (500); //determina tanto el tiempo de reaccion como la lectura de datos//
 light=(255-measure/4); //Para encender los leds con luminosidad el pin tras la resistencia, para lo contrario entre los dos componentes//
 Serial.println("Luminosidad ");
 Serial.println(light);
 delay (500);
 {
  analogWrite(A,light);
  analogWrite(B,light);
  analogWrite(C,light);
 }
}
