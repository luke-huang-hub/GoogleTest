#include "subject.h"

namespace robosense
{
namespace lidar
{
void Subject::addObserve(ObserveBase* _observe) { listobserve_.push_back(_observe); }

void Subject::deleteObserve(ObserveBase* _observe)
{
  for (auto it = listobserve_.begin(); it != listobserve_.end(); it++)
  {
    if ((*it) == _observe)
    {
      listobserve_.erase(it);
    }
  }
}

void Subject::notify()
{
  for (auto observe : listobserve_)
  {
    observe->update();
  }
}

}  // namespace lidar
}  // namespace robosense