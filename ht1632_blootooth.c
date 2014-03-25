//marche trop bien avec simplewrite4
// avec localhost on envoie des messages!!
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "4panneaux.h"
#include "base_functions.h"
//#include "message.h"

unsigned int nombre_de_zoom;
//*****************************************blutooth
unsigned char  *receive_str(unsigned char *n);
void envoyer_chaine(unsigned char *p1);
void usart_transmit(unsigned char dodo);
void usart_init(unsigned int ubrr);
void usart_flush(void);
unsigned char usart_receive(void);
//unsigned char *receive_str(void);
unsigned char p[]="\nentrer une chaine de 40 caracteres \n",*s,message[42];
unsigned int mama;
unsigned char pipi;
//***************

void init(void);
void uart_close(void);

#define FOSC 4000000
#define BAUD 9600
//#define MYUBRR FOSC/16/BAUD-1
unsigned int MYUBRR;

void usart_flush(void)
{
unsigned char dummy;
while(UCSRA&(1<<RXC)) ;
dummy=UDR;
}

void usart_init(unsigned int ubrr)
{
UBRRL=(unsigned char)ubrr;
UBRRH=(unsigned char)(ubrr>>8);

UCSRB=(1<<RXEN)|(1<<TXEN);
UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}


unsigned char usart_receive(void)
{

while(!(UCSRA&(1<<RXC)));
pipi=UDR;
//usart_transmit(pipi);
return pipi;

}


void usart_transmit(unsigned char dodo)
{
while(!(UCSRA&(1<<UDRE))) ;
UDR=dodo;
_delay_ms(10);
//usart_flush();
}


void envoyer_chaine(unsigned char *p1)
{
while(*p1) {usart_transmit(*p1) ;_delay_ms(10);p1++;}
}

unsigned char *usart_receive_str(unsigned int haha)
{
unsigned char *titi=0;
unsigned int tt=0;
while(tt<haha-1){titi[tt]=usart_receive();_delay_ms(10);tt++;}
return titi;
}
void uart_close(void)
{
UCSRB&=~(1<<RXEN);
UCSRB&=~(1<<TXEN);
}
//*******************************************fin blutooth
//************************************************ init()
void init(void)
{
tonton=0;
MYUBRR=25;
nombre_de_zoom=0;
ht1632_data_dir|=(1<<cs)|(1<<data)|(1<<wr)|(1<<cs1)|(1<<cs2)|(1<<cs3);
ht1632_port=0xff;
ht1632_init();
usart_init(MYUBRR);

}

void clear(void)//on ecrit des 0 partout pour effacer
{

for(unsigned int j=0;j<32;j++){

ht1632_write(0b0000);_delay_ms(100);

}
//cs_hight();
//_delay_ms(50);
}


void permute(void)// L'ESSENTIEL est lÃ  ;pour défiler !!!
{
unsigned char qq=0;
while(qq<128) {J1[qq]=J1[qq+1];qq++;}
//J1[63]=J1[0];
}

void zoom(unsigned int x)
{
unsigned int coco=0;
while(coco<x) {permute();coco++;}
}

void tourner(unsigned char *x,unsigned char *y,unsigned char *z,unsigned char *u,unsigned char *s)
{
toto=0;
while(toto<8)//pour ne pas modofier les *x...*s on travaille sur les I .
{
I1[toto]=x[toto];I2[toto]=y[toto];I3[toto]=z[toto];I4[toto]=u[toto];I5[toto]=s[toto];toto++;
}
J1[0]=I1[0];zoom(nombre_de_zoom%3+1);//permute();permute();permute();
// décale J1 vers la gauche pour libérer J1[95] Ã 
//recevoir la donnÃ©e suivante.
//On peut initialiser où on veut comme par exemple :
//J&[0]=I1[0] ou I3|4], etc...
// on fait tourner  (on permute vers la gauche)
//les  colonnes des 4 caracteres I1,I2,I3,I4 et on entame I5 le caractère suivant
//pour faire défiler
I1[0]=I1[1];I1[1]=I1[2];I1[2]=I1[3];I1[3]=I1[4];
I1[4]=I1[5];I1[5]=I1[6];I1[6]=I1[7];I1[7]=I2[0];
//*********
I2[0]=I2[1];I2[1]=I2[2];I2[2]=I2[3];I2[3]=I2[4];
I2[4]=I2[5];I2[5]=I2[6];I2[6]=I2[7];I2[7]=I3[0];
//**********
I3[0]=I3[1];I3[1]=I3[2];I3[2]=I3[3];I3[3]=I3[4];
I3[4]=I3[5];I3[5]=I3[6];I3[6]=I3[7];I3[7]=I4[0];
//***************
I4[0]=I4[1];I4[1]=I4[2];I4[2]=I4[3];I4[3]=I4[4];
I4[4]=I4[5];I4[5]=I4[6];I4[6]=I4[7];I4[7]=I5[0];
//********************
I5[0]=I5[1];I5[1]=I5[2];I5[2]=I5[3];I5[3]=I5[4];
I5[4]=I5[5];I5[5]=I5[6];I5[6]=I5[7];
}


void afficher3(unsigned char x[])// afficher sur le panneau esclave3

{//permute();
unsigned int tata=0;// 0 à 32
 cs3_low();cs1_hight();cs2_hight();cs_hight();
 ht1632_adr(0);
while(tata<32)
{
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs3_hight();
}


void afficher2(unsigned char x[])//afficher sur le panneau esclave2

{
unsigned int tata=32;
 cs2_low();cs_hight();cs1_hight();cs3_hight();
 ht1632_adr(0);
while(tata<64)// de 32 à 64
{
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs2_hight();
}

void afficher1(unsigned char x[])//afficher sur le panneau esclave1

{//permute();

unsigned int tata=64;
 cs1_low();cs_hight();cs2_hight();cs3_hight();
 ht1632_adr(0);
while(tata<96)
{
// de 64  à 96
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs1_hight();
}


void afficher(unsigned char x[])// afficher sur le digit maitre

{//permute();
unsigned int tata=96;// de 96 à 128
 cs_low();cs1_hight();cs2_hight();cs3_hight();
 ht1632_adr(0);
while(tata<128)
{
ht1632_write(x[tata]);
_delay_us(100);
tata++;
}
 cs_hight();
}

//*********************


unsigned int longueur(unsigned char *x)
//Pour dÃ©terminer la fin de la lecture du tableau message: longueur de message  .
{
unsigned int count=0;
while(*x){count++;x++;}
return count;
}

void pause(unsigned int s)
{while(s--) _delay_ms(1);}

void charger(void)
{
mama=0;
//envoyer_chaine(p);
//_delay_ms(10);
while(mama<42) {message[mama]=usart_receive();mama++;}

//uart_close();
_delay_ms(10);

}

//*************************************Main


int main(void)
{
init();
_delay_ms(10);
charger();
_delay_ms(10);


unsigned int i=0,j3=5;
unsigned int w=42;//mama;//longueur(message);


while(1){// on tourne 8 fois pour récupérer un tableau 8x8

	tourner(tab[message[i%w]-65],tab[message[(i+1)%w]-65],tab[message[(i+2)%w]-65],tab[message[(i+3)%w]-65],tab[message[(i+4)%w]-65]);
	//cette première permutation donne I1,...I4  et on affiche J1 .
	//puis on continue avec les I;
	// %w permet de rester entre 0 et w-1 sans s'occuper de i++
	//On fait -65 pour partir de 0 avec le A de numero 65 dans la table des ascii .. .
afficher(J1);afficher1(J1);afficher2(J1);afficher3(J1);pause(j3);	//123
	tourner(I1,I2,I3,I4,I5);//2
	//j=j2;

afficher(J1);afficher1(J1);afficher2(J1);afficher3(J1);pause(j3);//123
	tourner(I1,I2,I3,I4,I5);//2
	//j=j2;

afficher(J1);afficher1(J1);afficher2(J1);afficher3(J1);pause(j3);//123
	tourner(I1,I2,I3,I4,I5);//2

afficher(J1);afficher1(J1);afficher2(J1);afficher3(J1);pause(j3);//123
	tourner(I1,I2,I3,I4,I5);//2

afficher(J1);afficher1(J1);afficher2(J1);afficher3(J1);pause(j3);	//123
	tourner(I1,I2,I3,I4,I5);//2

afficher(J1);afficher1(J1);afficher2(J1);afficher3(J1);pause(j3);//123
	tourner(I1,I2,I3,I4,I5);//2

afficher(J1);afficher1(J1);afficher2(J1);afficher3(J1);pause(j3);	//123
	tourner(I1,I2,I3,I4,I5);//2

afficher(J1);afficher1(J1);afficher2(J1);afficher3(J1);pause(j3);//123	//123

i++;
     }

return 1;
}
