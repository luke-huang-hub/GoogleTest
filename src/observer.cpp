#include "observer.h"

namespace robosense
{
namespace lidar
{

Observe::Observe(SubjectBase* _subject) { subject_ = _subject; }

Observe::~Observe() {}

void Observe::update()
{
  qDebug() << "aaaaaaaaaaaaaaaaaaaaaa";
  qDebug() << "bbbbbbbbbbbbbbbbbbbbbb";
}

}  // namespace lidar
}  // namespace robosense