const int trigPin = 9;
const int echoPin = 10;
long int duracion;
int distancia;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  /*
  duracion = pulseIn(echoPin, HIGH);
  distancia = duracion*(0.034/2.0);*/
  distancia = random(0, 100);

  Serial.println(distancia);
  //Serial.print("\n");

  delay(100);

}
