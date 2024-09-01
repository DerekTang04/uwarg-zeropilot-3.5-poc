#include "drivers.hpp"
#include "main.h"

ILEDBlinker *ledHandle  = nullptr;
IPrinter *printerHandle = nullptr;

void initDrivers()
{
  ledHandle = new LEDBlinker(LED_RED_GPIO_Port, LED_RED_Pin);
  printerHandle = new Printer();
}
