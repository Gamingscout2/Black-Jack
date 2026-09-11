#include<stdio.h>
/*
Silly little experiment of bitwise deck representation
*/

int initialize_deck(){
	// 12-bits per card
	// MSB, bit 11 - bit 8 used for face value
	// bit 7 leading zero (hex-friendly)
	// bit 6 - bit 4 used for card type (number or royal)
	// bit 3 - bit 2 leading 0s
	// bit 1 and bit 0 for suit
	
	// Ace face value always set to 1, later
	// logic will address adding 11 if you won't bust using
	// type flags
	
	// The deck will be 624 bits long
	int ace_h = 0x110;
	int two_h = 0x200;
	int thr_h = 0x300;
	int fou_h = 0x400;
	int fiv_h = 0x500;
	int six_h = 0x600;
	int sev_h = 0x700;
	int eig_h = 0x800;
	int nin_h = 0x900;
	int ten_h = 0xA00;
	int jac_h = 0xA40;
	int que_h = 0xA30;
	int kin_h = 0xA20;
	
	
