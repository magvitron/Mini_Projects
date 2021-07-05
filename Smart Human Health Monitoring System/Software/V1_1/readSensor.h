float readTemp()
{
  float return_temp = 0;
  for (int count = 1; count <= READ_COUNT; count++)
  {
    return_temp += (analogRead(ANALOG_PIN) * ADC_COUNT);
  }
  return ((return_temp / READ_COUNT )* 100);
}
