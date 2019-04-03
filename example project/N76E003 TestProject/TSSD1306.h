extern uint8_t OLED_currLine,OLED_currCol;
extern uint8_t OLED_ADD;
void OLED_Settings(uint8_t oAdd,uint8_t width, uint8_t height);
void OLED_SetFont(uint8_t fnt);
void OLED_Init();
void OLED_Write(char const* str);
void OLED_WriteChar(uint8_t oled_char);
void OLED_Clear();
void OLED_ClearField(uint8_t line, uint8_t bgn, uint8_t end);
void OLED_ClearLine(uint8_t line);
void OLED_SetCursor(uint8_t line,uint8_t column);
void OLED_WriteINT(int);
void OLED_SetContrast(uint8_t cntr);