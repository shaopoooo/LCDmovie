#ifndef LCM_H_INCLUDED
#define LCM_H_INCLUDED

#define CleanSet 0x0000

// GPIO Port E, DB0~DB7 (PE0~PE7), R/W (PE8), E (PE9), RS (PE10)
#define RW 0x0100   // read:1 or write:0  bit 8
#define E  0x0200   // execute (enable)   bit 9
#define RS 0x0400   // register select (1: data register or 0: instruction register) bit 10

// instruction to call lcd function  RS=0  RW=0 (Write Instruction Register)
#define LCD_ClearDisplay    0x0001  // clear display buffer (DDRAM)
#define LCD_ReturnHome      0x0002  // return cursor and display to original position
#define LCD_EntryMode       0x0004  // Entry Mode Set,  I/D (Increment/decrement) S (Shift)
#define LCD_DisplayCursor   0x0008  // Set Display(D) on/off and Cursor (C) on/off, B: cursor blinking
#define LCD_Shift           0x0010  // display or cursor shift, S/C (1: display, 0: cursor), R/L (1: shift right, 0: shift left)
#define LCD_Function        0x0020  // set DL (interface data length),  N (number of display lines), F (character font)
#define LCD_SetCGRAM        0x0040  // create font
#define LCD_SetDDRAM        0x0080  // cursor position setting

// RS=0  RW=1  Read Instruction Register
#define LCD_ReadBusyAddress 0x0100  // read busy flag (BF) and address counter content, RS=0, RW=1

// RS=1  RW=0  Write data into CGRAM or DDRAM
#define LCD_WriteData       0x0200  // RS=1, RW=0

// RS=1  RW=1  Read data from CGRAM or DDRAM
#define LCD_ReadData        0x0300  // RS=1, RW=1

// flags
unsigned short LCD_ACShiftDirection = 0x02;   // I/D bit 1, 1: increment, 0: decrement
unsigned short LCD_DisplayAutoShift = 0x01;   // S   bit 0 (1: accompany display shift during data write and read)

unsigned short LCD_Display = 0x04;            // D bit 2 (display on)
unsigned short LCD_Cursor = 0x02;             // C bit 1 (cursor on)
unsigned short LCD_CursorBlink = 0x01;        // B bit 0 (cursor blinking)

unsigned short LCD_ShiftMode = 0x08;          // S/C bit 3 (1: display shift / 0: cursor move)
unsigned short LCD_ShiftDirection = 0x04;     // R/L bit 2 (1: shift right / 0: shift left)

unsigned short LCD_InstructionMode = 0x10;    // DL bit 4 (interface data length, 1: 8 bits, 0: 4bits)
unsigned short LCD_NumLine = 0x08;            // N  bit 3 (number of display lines, 1: 2 lines, 0: 1 line)
unsigned short LCD_FontSize = 0x04;           // F  bit 2 (character font size, 1: 5x10 dots, 0: 5x8 dots)

unsigned short LCD_BusyFlag = 0x080;            // BF bit 7 (busy flag, 1: internally operating, 0: instruction acceptable)

#endif // LCM_H_INCLUDED
