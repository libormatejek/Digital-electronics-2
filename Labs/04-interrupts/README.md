| **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Timer/Counter0 | 8  | 16u | 128u | -- |1024u | -- | 4096u| 16384u |
| Timer/Counter1 | 16 |  4096u |  32768u | -- |262144u| -- |1048576u |4194304u|
| Timer/Counter2 | 8  | 16u | 128u | 512u |1024u | 2048u | 4096u| 16384u |

Shields are boards that can be attached to an Arduino board, significantly expand its capabilities, and makes prototyping much faster. See schematic of [Multi-function shield](../../Docs/arduino_shield.pdf) and find out the connection of four LEDs (D1, D2, D3, D4) and three push buttons (S1-A1, S2-A2, S3-A3).

&nbsp;
![](Images/conn.png)

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

| **Program address** | **Source** | **Vector name** | **Description** |
| :-: | :-- | :-- | :-- |
| 0x0000 | RESET | -- | Reset of the system |
| 0x0002 | INT0  | `INT0_vect` | External interrupt request number 0 |
| 0x0004 | INT1 |  | External interrupt request number 1 |
| 0x0006 | PCINT0 |  | Pin Change Interrupt Request 0 |
| 0x0008 | PCINT1 |  | Pin Change Interrupt Request 1 |
| 0x000A | PCINT2 |  | Pin Change Interrupt Request 2 |
| 0x000C | WDT |  | Watchdog Time-out Interrupt |
| 0x0012 | TIMER2_OVF |  | Timer/Counter2 Overflow |
| 0x0018 | TIMER1_COMPB | `TIMER1_COMPB_vect` | Compare match between Timer/Counter1 value and channel B compare value |
| 0x001A | TIMER1_OVF | `TIMER1_OVF_vect` | Overflow of Timer/Counter1 value |
| 0x0020 | TIMER0_OVF |  | Timer/Counter0 Overflow |
| 0x0024 | USART_RX |  | USART Rx Complete |
| 0x002A | ADC |  | ACD Converseion Complete |
| 0x0030 | TWI |  | 2-wire Serial Interface |
