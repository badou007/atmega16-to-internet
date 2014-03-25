

#include "the_defines.h"
#include "the_fonts.h"


unsigned int longueur(unsigned char *x);

unsigned char *tab[]={A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,vide,vide};
//*tab permet un balayage facile : A=tab[0] etc....
unsigned char J1[128];//car y a 128 colonnes pour 4 panneaux

unsigned char I1[8],I2[8],I3[8],I4[8],I5[8],toto,tonton;
unsigned int longueur(unsigned char *x);
void nop(void);
void write_low(void);
void write_hight(void);
void data_low(void);
void data_hight(void);
void cs_low(void);
void cs1_low(void);
void cs2_low(void);
void cs_hight(void);
//**********************
void cs3_low(void);
void cs3_hight(void);
//******************************
void cs1_hight(void);
void cs2_hight(void);
void write_id(void);
void command_id(void);
void ht1632_write(unsigned char x);
void ht1632_adr(unsigned char x);
void ht1632_master_command(unsigned int x);
void ht1632_slave_command(unsigned int x);
void ht1632_init(void);
void init(void);
void clear(void);
void permute(void);
void tourner(unsigned char *x,unsigned char *y,unsigned char *z,unsigned char *u,unsigned char *s);
void afficher(unsigned char x[]);
void afficher1(unsigned char x[]);
void afficher2(unsigned char x[]);
void afficher3(unsigned char x[]);
void command(unsigned int x);
unsigned int longueur(unsigned char *x);

void pause(unsigned int s);

void nop(void)
{
_delay_us(1);
}

void write_low(void)
{
ht1632_port&=~(1<<wr);nop();
}
void write_hight(void)
{
ht1632_port|=(1<<wr);nop();
}

void data_low(void)
{
ht1632_port&=~(1<<data);nop();
}
void data_hight(void)
{
ht1632_port|=(1<<data);nop();
}

void cs_low(void)
{
ht1632_port&=~(1<<cs);nop();
}
void cs_hight(void)
{
ht1632_port|=(1<<cs);nop();
}
void cs1_low(void)
{
ht1632_port&=~(1<<cs1);nop();
}
void cs1_hight(void)
{
ht1632_port|=(1<<cs1);nop();
}

void cs2_low(void)
{
ht1632_port&=~(1<<cs2);nop();
}
void cs2_hight(void)
{
ht1632_port|=(1<<cs2);nop();
}

void cs3_low(void)
{
ht1632_port&=~(1<<cs3);nop();
}
void cs3_hight(void)
{
ht1632_port|=(1<<cs3);nop();
}

void write_id(void)//code pour ecrire
{

write_hight();
write_low();
data_hight();//envoie 1
write_hight();

write_low();
data_low();//envoie 0
write_hight();

write_low();
data_hight();//envoie 1
write_hight();

}

void command_id(void)//code pour une commande
{

write_hight();
write_low();
data_hight();//envoie 1
write_hight();

write_low();
data_low();//envoie 0
write_hight();

write_low();
data_low();//envoie 0
write_hight();

}
















