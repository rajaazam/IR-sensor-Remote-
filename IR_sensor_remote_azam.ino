#include <IRremote.h>
 
#define first_key  16582903 
#define second_key  16615543 
#define fifth_key  16623703
#define eight_key  16619623 
int receiver_pin = 2;   

int first_led_pin = 3;
int second_led_pin = 4;
int fifth_led_pin = 5;
int eight_led_pin = 6;

int led[] = {0,0,0,0}; 
IRrecv receiver(receiver_pin); 
decode_results output;
 
void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn();  
  pinMode(first_led_pin, OUTPUT);
  pinMode(second_led_pin, OUTPUT);
  pinMode(fifth_led_pin, OUTPUT);
  pinMode(eight_led_pin, OUTPUT);
  }
 
void loop() {
  if (receiver.decode(&output)) 
  {
    unsigned int value = output.value;
    switch(value) 
    {
       case first_key:    
         if(led[0] == 1) 
         {       
            digitalWrite(first_led_pin, LOW);
            led[0] = 0;           
         } 
         else 
         {                      
             digitalWrite(first_led_pin, HIGH); 
             led[0] = 1;          
         }
         break; 
          
         case second_key:
       
         if(led[1] == 1) 
         {
            digitalWrite(second_led_pin, LOW);
            led[1] = 0;
         } 
         else 
         {
             digitalWrite(second_led_pin, HIGH);
             led[1] = 1;
         }
         break;
          
         case fifth_key:
         if(led[2] == 1) 
         {
            digitalWrite(fifth_led_pin, LOW);
            led[2] = 0;
         } 
         else 
         {
             digitalWrite(fifth_led_pin, HIGH);
             led[2] = 1;
         }
         break;   
         
         case eight_key:
         if(led[3] == 1) 
         {       
            digitalWrite(eight_led_pin, LOW);
            led[3] = 0;           
         } 
         else 
         {                      
             digitalWrite(eight_led_pin, HIGH); 
             led[3] = 1;          
         }
         break;        
    }
    Serial.println(value); 
    receiver.resume(); 
  }
}
