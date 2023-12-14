#pragma once

#include<QString>


namespace MavlinkWrapper{

QByteArray EncodeMotorParamMessage(int id, int speed);

}