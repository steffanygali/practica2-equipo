#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int inputPin = 7;

int value = 0;
int currentIndex = 0;

String matriculas[] = {
  "Alexis Linares Cortes Matricula: (202232365)",
  "Steffany Paola Galicia Arriaga Matricula: (202222697)",
  "Richar Matricula: (202238597)",
  "Gonzalez García Angel Omar Matricula: (202230985)",
  "Javier Matricula: (202232567)",
  "Jorge Castillo Matricula: (202237277)"
};

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("0: 100530248");  
  pinMode(inputPin, INPUT);
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);

  value = digitalRead(inputPin);

  if (value) {
    lcd.clear();
    currentIndex = (currentIndex + 1) % 6;  
    lcd.setCursor(0, 0);
    lcd.print(matriculas[currentIndex]);
    delay(2000);
  }
}