#include <head.h>


/**
 * main.c
 */
int main(void)
{
    *GIOGCR0 = 0x00000001;
    *GIOENACLR = 0xFF;
    *GIOLVLCLR = 0xFF;
    *GIODIRA = 0xFFFFFFFF;
    *GIODSETA = 0x00000001;
	return 0;
}
