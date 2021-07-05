String A= "$GPRMC,201547.000,A,3014.5527,N,09749.5808,W,0.24,163.05,040109,,*1A";
String B= "$GPGGA,201548.000,3014.5529,N,09749.5808,W,1,07,1.5,225.6,M,-22.5,M,18.8,0000*78";
String C = "$GPRMC,201548.000,A,3014.5529,N,09749.5808,W,0.17,53.25,040109,,*2B";
String D = "$GPGGA,201549.000,3014.5533,N,09749.5812,W,1,07,1.5,223.5,M,-22.5,M,18.8,0000*7C";
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println(A);
  Serial.println(B);
  Serial.println(C);
  Serial.println(D);
  delay(1000);
}
