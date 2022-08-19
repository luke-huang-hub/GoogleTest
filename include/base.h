#ifndef BASE_H
#define BASE_H

#include <QtCore/QObject>
#include <QtCore/QtDebug>
#include <QtCore/QList>

namespace robosense
{
namespace lidar
{

class ObserveBase
{

public:
  ObserveBase() {};
  ~ObserveBase() {};

  virtual void update() = 0;

protected:
};

class SubjectBase
{

public:
  SubjectBase() {};
  ~SubjectBase() {};

  virtual void addObserve(ObserveBase* _observe)    = 0;
  virtual void deleteObserve(ObserveBase* _observe) = 0;
  virtual void notify()                             = 0;

protected:
  QList<ObserveBase*> listobserve_;
};

}  // namespace lidar
}  // namespace robosense

#endif  // BASE_H