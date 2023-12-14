/** @file
 *	@brief MAVLink comm testsuite protocol generated from motor_param.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "motor_param.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(motor_param, MotorParameter)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::motor_param::msg::MotorParameter packet_in{};
    packet_in.ID = 17;
    packet_in.Speed = 963497464;

    mavlink::motor_param::msg::MotorParameter packet1{};
    mavlink::motor_param::msg::MotorParameter packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.ID, packet2.ID);
    EXPECT_EQ(packet1.Speed, packet2.Speed);
}

#ifdef TEST_INTEROP
TEST(motor_param_interop, MotorParameter)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_motorparameter_t packet_c {
         963497464, 17
    };

    mavlink::motor_param::msg::MotorParameter packet_in{};
    packet_in.ID = 17;
    packet_in.Speed = 963497464;

    mavlink::motor_param::msg::MotorParameter packet2{};

    mavlink_msg_motorparameter_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.ID, packet2.ID);
    EXPECT_EQ(packet_in.Speed, packet2.Speed);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
