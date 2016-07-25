void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
}
void loop()
{
  String str="";
  while (Serial1.available())
  {
    char c = Serial1.read();
    str += c;
    delay(10);
  }
  if (str != "")
  {
    //Serial1.println(str);
    Serial.println(str);
    str = "";
  }
  while (Serial.available())
  {
    char c = Serial.read();
    str += c;
    delay(10);
  }
  if (str != "")
  {
    Serial.println(str);
    Serial1.println(str);
  }
}
