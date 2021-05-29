#include<reg51.h>
#include<string.h>

// ______Motor Control's_______
sbit door_open = P2^0;
sbit door_close = P2^1;
void gate(int open, int close);

// ________LCD port pin________ 
//_register state controller pin
sbit rs = P2^5;
// read and write pin
sbit rw = P2^6; 
// enable pin (Enable pin; latchs data_from the data_ pins)
sbit en = P2^7; 

// ________LCD commands________
// func passing a character to lcd D0 to D7 pins
unsigned int i = 0;
void lcd_data(unsigned char);
// func to pass commands to our lcd
void lcd_cmd(unsigned char);
// To display text on the lcd screen
void display(char* text, int clearPreviousText, unsigned int delayBy);
// init lcd with  basic commands
void init_lcd();
// init serial ports of 8051 microcontroller
void serial_init() {
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = -3;   // baud_rate = 9600
	TR1 = 1;
}


// _________Core functions_________
// check func checks a card's rfid with the rfid's in our list
int check();
// list of rfid's
const char* id[] = {"a2Gp5n8iK79g", "7Hie72n6Fl3w", "9O2nId0KEm23", "k20dl2uGn49n"};
// delay func delay's the excetion of our program
void delay(float V) {
	for (i = 0; i < V * 1526; i++) {}
}
// var's to store rfid as chars
char rfid[12], ch = 0;
// rxdata is a func to recieve data from the virtual terminal 
char rxdata() {
	while(!RI);
  ch = SBUF;    
  RI=0;
  return ch;
}



// P1 connects all D0 to D7 data_pins of lcd
void lcd_data(unsigned char ch) {
	P1 = ch;
	rs = 1;
	en = 1;
	delay(0.015);
	en = 0;
}

void lcd_cmd(unsigned char ch) {
	P1 = ch; 
	rs = 0;
	en = 1;
	delay(0.2);
	en = 0;
}

/*
 * 56 | 0x38 command intializes 8_bit 2 line 5x7 matrix (dots) 
 * 01 | 0x01 command clear's screen
 * 16 | 0x10 command shift's cursor position from left to right
 * 12 | 0x0C command ON's display and OFF's cursor;
 * 128| 0x80 command that set's DDRam address (set cursor position) to LCD display
 */
void init_lcd() {
	rw = 0;
	lcd_cmd(0x38); 
	lcd_cmd(0x01); 
	lcd_cmd(0x10); 
	lcd_cmd(0x0C); 
	lcd_cmd(0x80);
}

// this function is used for a better user experience
void loading_display(char* str) {
	delay(0.5);
	display(str, 1, 2.0);
	display(".", 0, 1.7);
	display(".", 0, 1.4);
	display(".", 0, 1);
	display(".", 0, 0.5);
}

void main() {
	init_lcd();
	serial_init();
	loading_display("Starting");
	while(1){
		delay(0.7);
		display(" PLEASE__VERIFY", 1, 0);
		lcd_cmd(0xc4);
		display("YOUR ID:", 0, 3);
		display("Swipe your card: ", 1, 4); 
		for(i = 0; i < 12; i++)
      rfid[i] = rxdata();
		rfid[i] = '\0';
		if (check()) {
			loading_display("DOOR_OPENING");
			gate(1, 0);
			delay(2);
			gate(0, 0);
			delay(5);
			loading_display("DOOR_CLOSING");
			gate(0 ,1);
			delay(2);
			gate(0, 0);
		} else {
			display("CANNOT VERIFY ID", 1, 2);
			lcd_cmd(0xc3);
			display("TRY AGAIN!", 0, 4);
		}
	}
}

void display(char *str, int clearPreviousText, unsigned int delayBy) {
	if (clearPreviousText >= 1)
		lcd_cmd(0x01);
	while(*str)
		lcd_data(*str++);
	delay(delayBy);
}

int check() {
	unsigned char i = 0;
	loading_display("VERIFYING");
	for (i = 0; i < 4; i++)
		if (memcmp(rfid, id[i], 12) == 0)
			return 1;
	return 0;
}

void gate(int open, int close) {
	door_open = open;
	door_close = close;
}
