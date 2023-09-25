#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
LiquidCrystal_I2C lcd(39,16,2);

const byte row = 4;
const byte col = 4; 
char Keys[row][col] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[row] = {2, 3, 4, 5};
byte colPins[col] = {6, 7, 8, 9}; 
Keypad myKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, row, col);

char pass[6] = {};
byte counter = 0;

void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Password : ");}
  
void loop(){
  char key = myKeypad.getKey();
  if(key)
  {
    if(counter <=5)
    {
    pass[counter] = key;
    lcd.setCursor(counter+10, 0);
    lcd.print(key);
    counter++;
    }
    else {counter = 0;}
    
    if(key == 'A')
    {
      reset(); 
    }
    char enter = myKeypad.getKey();
    if(counter == 6)
    {
    while(!enter)
    enter = myKeypad.getKey();
    }
    if(pass[0] == '1' && pass[1] =='2' && pass[2] == '3' && pass[3] == '4' && pass[4] =='5' && pass[5] == '6'&& enter == 'D')
    {
    correct(); 
    }
    if(pass[0] != '1' && enter == 'D')
    {
    incorrect(); 
    }
   }
  }
void correct()
{    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password : ");
    lcd.setCursor(0, 1);
    lcd.print("Correct :)");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password : ");
}
void incorrect()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password : ");
    lcd.setCursor(0, 1);
    lcd.print("Try Again :(");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password : ");
}
void reset()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Password : ");
  pass[6] = {};
}