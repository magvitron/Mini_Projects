/**
   @breif Read temperature from LM35 with resoln 1024
    with READ_COUNT
   @return averaged temperature value
   @param none
*/
float readTemp()
{
  float return_temp = 0;
  for (int count = 1; count <= READ_COUNT; count++)
  {
    return_temp += (analogRead(AI_TEMP_PIN) * ADC_COUNT);
  }
  return ((return_temp / READ_COUNT ) * 100);
}
/**
   @breif Read pressure from analog values
   @return averaged pressure value
   @param none
   The transfer function: Vout = Vs x ((0.009 x P) – 0.095) ± Error
  VS = 5.1 ± 0.25 Vdc
  P = pressure in kiloPascals
  Error = ±1.5 (kPa
  Pressure in kPa = (Vout + 0.475)/0.0475; ± Error
*/
float readPress()
{
  float return_press = 0;
  for (int count = 1; count <= READ_COUNT; count++)
  {
    return_press += (analogRead(AI_PRESS_PIN) * ADC_COUNT);
  }
  return_press = (return_press / READ_COUNT );
  Serial.println(return_press);
  return (((return_press + 0.475) / 0.0475) + 3.86);

}
