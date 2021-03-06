/* 
NTOUCS_Home_Network_51AVR.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	/* self header */
		#include "NTOUCS_Home_Network_51AVR.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	void initializeSystem(
		/* 初始化系統，初始化／停用所有元件 */
			void){
		unsigned int shared_i;				
		/* 關閉 LED 顯示 */
			led = 0xFF;
		/* 停用 7 段顯示器 */
			/* 關閉數位顯示開關 */
				seven_seg_latch_position_enable = LOGIC_HIGH;
				seven_seg = 0x00;
				seven_seg_latch_position_enable = LOGIC_LOW;
				/* delay(400); */{
					for(shared_i = 0; shared_i < 200; ++shared_i){
						;
					}
					for(shared_i = 0; shared_i < 200; ++shared_i){
						;
					}
				}
			/* 清空數位字型內容 */
				seven_seg_latch_font_enable = LOGIC_HIGH;
				seven_seg = 0x00;
				seven_seg_latch_font_enable = LOGIC_LOW;				
		/* 停用 ADC 對匯流排的輸出 */
			adc_chip_select_bar_read_bar = LOGIC_HIGH;
		/* 停用 DIP 對匯流排的輸出 */
			dip_sw_chip_enable_bar = LOGIC_HIGH;

		/* 設定 LCD 物理模式 */{
			lcd_busy = LOGIC_HIGH;
			lcd_register_select = LCD_REG_INSTRUCTION;
			lcd_read_write_bar = LOGIC_HIGH;
			lcd_enable = LOGIC_HIGH;
			while(lcd_busy == LOGIC_HIGH){
				/* do nothing */;
			}
			lcd_enable = LOGIC_LOW;
			
			lcd_register_select = LCD_REG_INSTRUCTION;
			lcd_read_write_bar = LOGIC_LOW;
			lcd = LCD_PHYSICAL_MODE;
			lcd_enable = LOGIC_HIGH;
			/* delay(LCD_INST_GENERIC_TIME); */{
				for(shared_i = 0; shared_i < LCD_INST_GENERIC_TIME; ++shared_i){
					/* do nothing */;
				}
			}			
			lcd_enable = LOGIC_LOW;
		}

		/* 清空 LCD 內容（包含游標位置歸零） */{
			lcd_busy = LOGIC_HIGH;
			lcd_register_select = LCD_REG_INSTRUCTION;
			lcd_read_write_bar = LOGIC_HIGH;
			lcd_enable = LOGIC_HIGH;
			while(lcd_busy == LOGIC_HIGH){
				/* do nothing */;
			}
			lcd_enable = LOGIC_LOW;
			
			lcd_register_select = LCD_REG_INSTRUCTION;
			lcd_read_write_bar = LOGIC_LOW;
			lcd = 0x01;			
			lcd_enable = LOGIC_HIGH;
			/* delay(LCD_INST_GENERIC_TIME); */{
				for(shared_i = 0; shared_i < LCD_INST_GENERIC_TIME; ++shared_i){
					/* do nothing */;
				}
			}
			/* delay(LCD_INST_CLEAR_TIME); */{
				for(shared_i = 0; shared_i < LCD_INST_CLEAR_TIME; ++shared_i){
					/* do nothing */;
				}
			}
			lcd_enable = LOGIC_LOW;
		}

		/* 關閉 LCD */{
			lcd_busy = LOGIC_HIGH;
			lcd_register_select = LCD_REG_INSTRUCTION;
			lcd_read_write_bar = LOGIC_HIGH;
			lcd_enable = LOGIC_HIGH;
			while(lcd_busy == LOGIC_HIGH){
				/* do nothing */;
			}
			lcd_enable = LOGIC_LOW;
						
			lcd_register_select = LCD_REG_INSTRUCTION;
			lcd_read_write_bar = LOGIC_LOW;
			lcd = 0x08;			
			lcd_enable = LOGIC_HIGH;
			/* delay(LCD_INST_GENERIC_TIME); */{
				for(shared_i = 0; shared_i < LCD_INST_GENERIC_TIME; ++shared_i){
					/* do nothing */;
				}
			}			
			lcd_enable = LOGIC_LOW;
		}

		/* 停用計時器(timer)／計數器(counter) */
			tmr_ctr1_run = LOGIC_LOW;
			tmr_ctr0_run = LOGIC_LOW;

		/* prompt */{
			for(shared_i = 0, led = 0x55; BTN_SW4 != BTN_SW_PRESSED; ++shared_i){
				if(shared_i == 12345){
					shared_i = 0;
					led = ~led;
				}
			}
			led = 0xff;
			shared_i = BTN_SW_CLICK_DELAY;
			while(shared_i != 0){
				/* do nothing */;
				--shared_i;
			}
		}
		return;
	}
