#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
const int delayTime = 300; //ms

String displayString = "";
const int displayWidth = 15;

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(displayWidth, 2);
  // Print a message to the LCD.
  lcd.print("  Welcome to ");
  lcd.setCursor(0, 1); //Display position
  lcd.print("    Arduino");
  delay(500);
  lcd.clear();
  Serial.begin(9600);
}
void printLCD(String string0, String string1) {

  //上の段はセンタリング
  if (string0.length() < displayWidth - 1) {
    String tmp = "";
    for (int i = 0; i < (displayWidth - string0.length()) / 2; i++) {
      tmp += ' ';
    }
    string0 = tmp + string0;
  }
  //下の段の文字列生成
  for (int i = 0; i < displayWidth + string1.length(); i++) {
    lcd.clear();
    displayString = "";
    if (i < 16) {
      for (int j = 0; j < displayWidth - i + 1; j++) {
        displayString += ' ';
      }
      for (int k = 0; k < i; k++) {
        displayString += string1[k];
      }
    }
    else  if (i < string1.length()) {
      displayString = "";
      for (int k = 0; k <=  displayWidth; k++) {
        displayString += string1[i - displayWidth + k];
      }
    }
    else {
      displayString = "";
      for (int k = 0; i - displayWidth + k < string1.length(); k++) {
        displayString += string1[i - displayWidth + k];
      }
    }
    //printする
    lcd.setCursor(0, 0);
    lcd.print(string0);
    lcd.setCursor(0, 1);
    lcd.print(displayString);
    delay(delayTime);
  }

}
void loop()
{
  String string0 = "Hatena blog";
  String string1 = "https://s51517765.hatenadiary.jp/";
  printLCD(string0, string1);
  string0 = "GitHub";
  string1 = "https://github.com/s51517765";
  printLCD(string0, string1);
  string0 = "Twitter";
  string1 = "https://twitter.com/s51517765";
  printLCD(string0, string1);
}
