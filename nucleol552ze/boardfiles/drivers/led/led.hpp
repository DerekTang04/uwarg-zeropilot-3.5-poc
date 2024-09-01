#pragma once

#include "led_iface.hpp"
#include "stm32l5xx_hal.h"

class LEDBlinker : public ILEDBlinker
{
private:
  GPIO_TypeDef *bus;
  uint16_t pin;

public:
  LEDBlinker() = delete;

  LEDBlinker(GPIO_TypeDef *bus, uint16_t pin);

  void blinkOnce() override;

  void blinkTwice(uint32_t delay_ms) override;
};
