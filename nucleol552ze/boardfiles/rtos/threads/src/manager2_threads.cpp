#include "managers.hpp"
#include "manager2_threads.hpp"
#include "utils.hpp"

osThreadId_t m2MainHandle;

static const osThreadAttr_t m2MainLoopAttr = {
    "m2Main",
    osThreadDetached,
    nullptr,
    0U,
    nullptr,
    1024U,
    osPriorityNormal,
    0U,
    0U
};

void m2MainLoopWrapper(void *arg)
{
  while(true)
  {
    manager2Handle->mainLoop();
    osDelay( timeToTicks(3000) );
  }
}

void m2InitThreads()
{
  m2MainHandle = osThreadNew(m2MainLoopWrapper, nullptr, &m2MainLoopAttr);
}
