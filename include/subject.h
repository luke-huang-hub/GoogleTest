#ifndef SUBJECT_H
#define SUBJECT_H

#include "base.h"
namespace robosense
{
namespace lidar
{
class Subject : public SubjectBase
{
public:
  Subject() {};
  ~Subject() {};

  void addObserve(ObserveBase* _observe);
  void deleteObserve(ObserveBase* _observe);
  void notify();

private:
};

}  // namespace lidar
}  // namespace robosense
#endif  //SUBJECT_H
