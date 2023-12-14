#pragma once

#include "../Mavlink/motor_param/mavlink.h"
#include <QString>

using MotorParam = mavlink_motorparameter_t;
namespace MavlinkResolver {

bool GetMortorParamMessage(QByteArray message, MotorParam& motor_param);
	
}