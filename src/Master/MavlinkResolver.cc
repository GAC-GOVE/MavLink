#include "MavlinkResolver.h"
#include <QDebug>

namespace MavlinkResolver {

bool GetMortorParamMessage(QByteArray message, MotorParam& motor_param) {

    mavlink_message_t motor_message;
    mavlink_status_t status;

    for (int i = 0; i < message.size(); ++i) {
        if (mavlink_parse_char(1, message.at(i), &motor_message, &status)) {
            mavlink_msg_motorparameter_decode(&motor_message, &motor_param);
            return true;
        }
    }
    return false;
}

}  // namespace MavlinkResolver