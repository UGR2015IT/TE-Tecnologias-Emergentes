// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// initialize the potentiometer PIN and potentiometer Value
const int potPIN = A0;
float potValue = 0;

// initialize LEDs
int ledPIN[] = {8,9,10};

// initialize buttons
const int button = 13;

void setup(){
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // set up the serial communications:
  Serial.begin(9600);
  // set up LEDs as Output
  for (int i=0; i < 3; i++)
    pinMode(ledPIN[i], OUTPUT);
  // set up button as input
  pinMode(button, INPUT);
  
  lcd.print("Welcome! Drink");
  lcd.setCursor(0,1);
  lcd.print("more, drive less.");
  delay(3000);
  
}

void loop()
{
  lcd.clear();
  
  //Check for button press to start reading
  if (digitalRead(button) == HIGH){
    
      lcd.setCursor(0,0);
      lcd.print("Breath deeply.");
      lcd.setCursor(0,1);
      lcd.print("Reading value ..");
      
      delay(1000);

      while ((potValue = analogRead(potPIN)) == 0) potValue = analogRead(potPIN);
      lcd.clear();
      float alcoholLevel=potValue/1000;
      if (alcoholLevel < 0.3){
        // Led GREEN ON
        digitalWrite(ledPIN[0], HIGH);
        lcd.setCursor(0,0);
        lcd.print("You can still");
        lcd.setCursor(0,1);
        lcd.print("drink! Lvl: ");
      } else if (alcoholLevel > 0.3 && alcoholLevel < 0.499){
        //age check
        //Led YELLOW ON
        digitalWrite(ledPIN[1], HIGH);
        lcd.setCursor(0,0);
        lcd.print("You've drunk");
        lcd.setCursor(0,1);
        lcd.print("enough. Lvl: ");
      } else {
        //Led RED ON
        digitalWrite(ledPIN[2], HIGH);
        lcd.setCursor(0,0);
        lcd.print("You're a champ,");
        lcd.setCursor(0,1);
        lcd.print("mate! Lvl: ");
      }
        lcd.print(alcoholLevel);
      
      //Waiting  
      delay(10000);
      
      //Wiping section
      lcd.clear();
      for (int i=0;i<3;i++)
        digitalWrite(ledPIN[i], LOW);
  }
}
