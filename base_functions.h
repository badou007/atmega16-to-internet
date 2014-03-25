void ht1632_write(unsigned char x)
//ecrit un char; on mettra write_id avant ; commence par le lsb
//en write continuous mode pas besoin de couper le char D7D6D5D4D3D2D1D0 en 2 groupes ;
//ht1632 ecrit D3D2D1D0 sur le haut puis D7D6D5D4 dessous  dans chaque colonne: aide Ã  crÃ©er les fontes .
{
write_low();
if(x&0x01){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x02){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x04){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x08){data_hight();}
else {data_low();}
write_hight();
//************************
write_low();
if(x&0x10){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x20){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x40){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x80){data_hight();}
else {data_low();}
write_hight();
}
//***********************************
void ht1632_adr(unsigned char x)
//ecrire une adresse; le code write_id est mis devant ;
//on en aura besoin que d'une fois pour l'adresse 0
{
write_id();
write_low();
if(x&0x40){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x20){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x10){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x08){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x04){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x02){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x01){data_hight();}
else {data_low();}
write_hight();

}
//************************
void command(unsigned int x)
{
command_id();
write_low();
if(x&0x100){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x80){data_hight();}
else {data_low();}
write_hight();
write_low();
if(x&0x40){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x20){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x10){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x08){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x04){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x02){data_hight();}
else {data_low();}
write_hight();

write_low();
if(x&0x01){data_hight();}
else {data_low();}
write_hight();
}

//*****************************************
void ht1632_master_command(unsigned int x)
//ecriturecomplÃ¨te d'une commande pour le panneau1.
{
cs_hight();
cs_low();
command(x);
cs_hight();
}
//*****************************************
void ht1632_slave_command(unsigned int x)//pour le panneau2
//ecriturecomplÃ¨te d'une commande .
{
cs1_hight();cs2_hight();cs3_hight();
cs1_low();cs2_low();cs3_low();
command(x);
cs1_hight();cs2_hight();cs3_hight();
}
void ht1632_init(void)
{
//on initialise le ht1632
ht1632_master_command(sys_en);
ht1632_master_command(master_rc);
ht1632_master_command(commons);//dans le commons on prend ab=10 (voir le data sheet)
ht1632_master_command(led_on);
ht1632_master_command(pwm_16);
ht1632_slave_command(sys_en);
ht1632_slave_command(slave_rc);
ht1632_slave_command(commons);//dans le commons on prend ab=10 (voir le data sheet)
ht1632_slave_command(led_on);
ht1632_slave_command(pwm_16);

}
