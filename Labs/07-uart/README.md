
## Preparation tasks (done before the lab at home)

Use schematic of the [LCD keypad shield](../../Docs/arduino_shield.pdf) and find out the connection of LCD display. What data and control signals are used? What is the meaning of these signals?

&nbsp;
![](images/lcd.png)
&nbsp;

&nbsp;

   | **LCD signal(s)** | **AVR pin(s)** | **Description** |
   | :-: | :-: | :-- |
   | RS | PB0 | Register selection signal. Selection between Instruction register (RS=0) and Data register (RS=1) |
   | R/W | GND  |Read/write Signal; 1→Read, 0→ Write|
   | E | PB1 | Enable; Falling edge |
   | D[3:0] | x | Bi-directional data bus, data transfer is performed once, thru DB0 to DB7, in the case of interface data length is 8-bits; and twice, through DB4 to DB7 in the case of interface data length is 4-bits. Upper four bits first then lower four bits. |
   | D[7:4] | PD[7:4] |  |

What is the ASCII table? What are the values for uppercase letters `A` to `Z`, lowercase letters `a` to `z`, and numbers `0` to `9` in this table?

&nbsp;
![](images/asci.png)
&nbsp;

&nbsp;

| **Function name** | **Function parameters** | **Description** | **Example** |
   | :-- | :-- | :-- | :-- |
   | `lcd_init` | `LCD_DISP_OFF`<br>`LCD_DISP_ON`<br>`LCD_DISP_ON_CURSOR`<br>`LCD_DISP_ON_CURSOR_BLINK` | Display off<br>display on, cursor off<br>display on, cursor          on<br>display on, cursor on flashing | `lcd_init(LCD_DISP_OFF);`<br>`lcd_init(LCD_DISP_ON);`<br>`lcd_init(LCD_DISP_ON_CURSOR);`<br>`lcd_init(LCD_DISP_ON_CURSOR_BLINK)` |
   | `lcd_clrscr` | void |Clear display and set cursor to home position. | `lcd_clrscr(void)` |
   | `lcd_gotoxy` | `uint8_t x` <br> `uint8_t y`  |horizontal position (0: left most position) <br> vertical position (0: first line) | `void lcd_gotoxy(uint8_t x,uint8_ty)`	|
   | `lcd_putc` | `char c` | Display character at current cursor position |` void lcd_putc (char c)` |
   | `lcd_puts` | `s`|string to be displayed | `void lcd_puts (const char * s)`|
   | `lcd_command` | `cmd	`| instruction to send to LCD controller, see HD44780 data sheet | `void lcd_command	(uint8_t cmd)`|
   | `lcd_data` | `data	`| byte to send to LCD controller, see HD44780 data sheet| `void lcd_data	(	uint8_t 	data	)`|
