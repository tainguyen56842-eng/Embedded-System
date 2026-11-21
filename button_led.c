#define LED 12
void bt_handler(void){
	if(digitalRead(BT) ==1){
		digitalWrite(LED,HIGH);
	}
	else{
		digitalWrite(LED,LOW);
	}
}
int main(void){
	wiringPiSetupPhy();
	pinMode(BT,INPUT);
	pinMode(LED,OUTPUT);
	wiringPiISR(
