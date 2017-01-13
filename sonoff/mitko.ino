void do_cmnd_identify()
{
  IPAddress ip = WiFi.localIP();
  int decs = ip[3] / 10;
  int ones = ip[3] % 10;
  //Serial.println(decs);
  //Serial.println(ones);
  digitalWrite(LED_PIN, (LED_INVERTED) ? 1 : 0);
  delay(600); // just in case - make it more visible
  blinkCount(decs);
  delay(1600); // 1600 + 400 = 2000 = more than enough
  blinkCount(ones);
  delay(400);
  // now return it back (don't know if it necessary, but just in case)
  if (sysCfg.ledstate &0x01) {
      digitalWrite(LED_PIN, (LED_INVERTED) ? !power : power);
  }
}

void blinkCount(int count) {
  int i;
  for (i = 1; i <= count; i++) {
    delay(400);
    digitalWrite(LED_PIN, (LED_INVERTED) ? 0 : 1);
    delay(200);
    digitalWrite(LED_PIN, (LED_INVERTED) ? 1 : 0);
  }
}

