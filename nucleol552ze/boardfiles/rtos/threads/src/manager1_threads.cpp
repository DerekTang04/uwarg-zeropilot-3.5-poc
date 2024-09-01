#include "managers.hpp"
#include "manager1_threads.hpp"
#include "utils.hpp"

osThreadId_t m1MainHandle;

static const osThreadAttr_t m1MainLoopAttr = {
    "m1Main",
    osThreadDetached,
    nullptr,
    0U,
    nullptr,
    0U,
    osPriorityNormal,
    0U,
    0U
};

void m1MainLoopWrapper(void *arg)
{
  while(true)
  {
    manager1Handle->mainLoop();
    osDelay( timeToTicks(1000) );
  }
}

void m1InitThreads()
{
  m1MainHandle = osThreadNew(m1MainLoopWrapper, nullptr, &m1MainLoopAttr);
}
