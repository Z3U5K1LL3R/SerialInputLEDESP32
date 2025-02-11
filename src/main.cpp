#include <Arduino.h>

#define LEDPIN 5

String inputString = "";

void processInput();

void setup()
{
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  Serial.println("Enter a number (1-5) and press Enter:");
}

void loop()
{
  while (Serial.available())
  {
    char inChar = Serial.read();
    if (inChar == '\n')
    {
      processInput();
    }
    else
    {
      inputString += inChar;
    }
  }
}

void processInput()
{
  int blinkCount = inputString.toInt();
  if (blinkCount >= 1 && blinkCount <= 5)
  {
    Serial.println("Blinking " + String(blinkCount) + " times...");

    for (int i = 0; i < blinkCount; i++)
    {
      digitalWrite(LEDPIN, HIGH);
      delay(500);
      digitalWrite(LEDPIN, LOW);
      delay(500);
      Serial.println("Blink" + String(i+1));
    }
  }
  else
  {
    Serial.println("Invalid input! Enter a number between 1-5.");
  }

  inputString = "";
}
