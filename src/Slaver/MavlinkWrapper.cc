#include "MavlinkWrapper.h"
#include "../Mavlink/motor_param/mavlink.h"

namespace MavlinkWrapper {

//encode motor param message
QByteArray EncodeMotorParamMessage(int id, int speed) {
    // mavlink_message_t message;
    const uint8_t system_id{123}, component_id{124};
    mavlink_motorparameter_t motor_param{id, speed};
    mavlink_message_t message; 
    mavlink_msg_motorparameter_encode(system_id, component_id, &message,
                                      &motor_param);
   
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    const int len = mavlink_msg_to_send_buffer(buffer, &message);

    return QByteArray(reinterpret_cast<char*>(buffer), len);
}

}  // namespace MavlinkWrapper
