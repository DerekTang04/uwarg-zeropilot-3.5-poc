#include "cmsis_os.h"
#include "led.hpp"
#include "utils.hpp"

static const uint32_t LED_ON_TIME_MS = 250U;

LEDBlinker::LEDBlinker(GPIO_TypeDef *bus, uint16_t pin) : bus(bus), pin(pin)
{
  // left blank
}

void LEDBlinker::blinkOnce()
{
  // ensure LED initial state is off
  HAL_GPIO_WritePin(this->bus, this->pin, GPIO_PIN_RESET);

  // turn LED on and wait
  HAL_GPIO_TogglePin(this->bus, this->pin);
  osDelay( timeToTicks(LED_ON_TIME_MS) );

  // turn LED off
  HAL_GPIO_TogglePin(this->bus, this->pin);
}

void LEDBlinker::blinkTwice(uint32_t delay_ms)
{
  this->blinkOnce();
  osDelay( timeToTicks(delay_ms) );
  this->blinkOnce();
}
