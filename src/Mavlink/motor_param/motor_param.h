/** @file
 *  @brief MAVLink comm protocol generated from motor_param.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_MOTOR_PARAM_H
#define MAVLINK_MOTOR_PARAM_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_MOTOR_PARAM.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_MOTOR_PARAM_XML_HASH -1082586939302294804

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{996, 112, 5, 5, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_MOTOR_PARAM

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_motorparameter.h"

// base include



#if MAVLINK_MOTOR_PARAM_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_MotorParameter}
# define MAVLINK_MESSAGE_NAMES {{ "MotorParameter", 996 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_MOTOR_PARAM_H
