#ifndef INTERLAYER_H
#define INTERLAYER_H

// Сигналы внешней связи

// Аналоговая часть
volatile double m_data_AI_1; // аналоговый вход 1
volatile double m_data_AI_2;
volatile double m_data_AI_3;
volatile double m_data_AI_4;

volatile double m_data_AO_1; // аналоговый выход 1
volatile double m_data_AO_2;
volatile double m_data_AO_3;
volatile double m_data_AO_4;


// Дискретная часть
volatile bool m_data_DI_1; // дискретный вход 1
volatile bool m_data_DI_2;
volatile bool m_data_DI_3;
volatile bool m_data_DI_4;

volatile bool m_data_DO_1; // дискретный выход 1
volatile bool m_data_DO_2;
volatile bool m_data_DO_3;
volatile bool m_data_DO_4;

#endif // INTERLAYER_H
