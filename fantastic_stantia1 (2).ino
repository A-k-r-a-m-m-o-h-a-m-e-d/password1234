
#include <Keypad.h>
 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 2, 3, 4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = { 6, 7,8,9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String input_pass="";
String mypass="1234";
int pos =0;
int led =12;
void setup(){
  pinMode(12,OUTPUT);
   lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print ("enter your pass");
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
   if(key =='#')
   {
    //code check on password
    if(input_pass==mypass) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("correct password");
       digitalWrite(12,1);
      delay(3000);
       digitalWrite(12,0);
      }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Wrong password");
      delay(3000);
       digitalWrite(12,0);
      
      }
      lcd.clear();
      lcd.setCursor(0,0);
  lcd.print ("enter your pass");
  input_pass="";
  pos=0;
    }
    if(key =='C'){
      
      //code delete on lcd
      pos--;
      lcd.setCursor(pos,1);
      lcd.print(" ");
      input_pass.remove(pos);
      }
      else{
        //code input password
        input_pass+=key ;
         lcd.setCursor(pos,1);
         lcd.print(key);
         delay(150);
         lcd.setCursor(pos,1);
         lcd.print("*");
       pos++;
        }
       
  }
 
}