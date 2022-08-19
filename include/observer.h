#ifndef OBSERVER_H
#define OBSERVER_H

#include "base.h"
namespace robosense
{
namespace lidar
{
class Observe : public ObserveBase
{
public:
  Observe(SubjectBase* _subject);
  ~Observe();

  void update();

private:
  SubjectBase* subject_;
};

}  // namespace lidar
}  // namespace robosense
#endif  //OBSERVER_H