void RTC_SetData(uint8_t item,uint8_t t_val);
uint8_t RTC_GetData(uint8_t item);
uint8_t BCD_toINT(uint8_t hex);
void RTC_init(uint8_t sqw_GPIO_Output, uint8_t sqw_enabel, uint8_t sqw_frq_1_4_8_32);
void RTC_Set(uint8_t secs, uint8_t mins, uint8_t hours, uint8_t DayOfWeek, uint8_t Date, uint8_t month, uint8_t year);
void RTC_Write_GPRAM(uint8_t ramAdd, uint8_t iData);
uint8_t RTC_Read_GPRAM(uint8_t ramAdd);