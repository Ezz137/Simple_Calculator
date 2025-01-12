/*
 * BUZZER.h
 *
 * Created: 02/12/2024 18:30:12
 *  Author: zezom
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_
void Buz_vInit(volatile unsigned char PORT,volatile unsigned char pin);
void Buz_vTurnON(volatile unsigned char PORT,volatile unsigned char pin);
void Buz_vTurnOFF(volatile unsigned char PORT,volatile unsigned char pin);
void Buz_vTog(volatile unsigned char PORT,volatile unsigned char pin);
unsigned char Buz_uRead(volatile unsigned char PORT,volatile unsigned char pin);
#endif /* BUZZER_H_ */