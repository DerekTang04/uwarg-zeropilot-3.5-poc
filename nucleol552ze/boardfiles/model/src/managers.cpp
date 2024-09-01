#include "drivers.hpp"
#include "managers.hpp"

Manager1 *manager1Handle = nullptr;
Manager2 *manager2Handle = nullptr;

void initManagers()
{
  manager1Handle = new Manager1(ledHandle);
  manager2Handle = new Manager2(printerHandle, FibCounter());
}
