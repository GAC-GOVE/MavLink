#pragma once
// MESSAGE MotorParameter PACKING

#define MAVLINK_MSG_ID_MotorParameter 996


typedef struct __mavlink_motorparameter_t {
 uint32_t Speed; /*<   Mortor Speed */
 uint8_t ID; /*<   Mortor ID*/
} mavlink_motorparameter_t;

#define MAVLINK_MSG_ID_MotorParameter_LEN 5
#define MAVLINK_MSG_ID_MotorParameter_MIN_LEN 5
#define MAVLINK_MSG_ID_996_LEN 5
#define MAVLINK_MSG_ID_996_MIN_LEN 5

#define MAVLINK_MSG_ID_MotorParameter_CRC 112
#define MAVLINK_MSG_ID_996_CRC 112



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MotorParameter { \
    996, \
    "MotorParameter", \
    2, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_motorparameter_t, ID) }, \
         { "Speed", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_motorparameter_t, Speed) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MotorParameter { \
    "MotorParameter", \
    2, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_motorparameter_t, ID) }, \
         { "Speed", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_motorparameter_t, Speed) }, \
         } \
}
#endif

/**
 * @brief Pack a motorparameter message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID   Mortor ID
 * @param Speed   Mortor Speed 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motorparameter_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ID, uint32_t Speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MotorParameter_LEN];
    _mav_put_uint32_t(buf, 0, Speed);
    _mav_put_uint8_t(buf, 4, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MotorParameter_LEN);
#else
    mavlink_motorparameter_t packet;
    packet.Speed = Speed;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MotorParameter_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MotorParameter;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MotorParameter_MIN_LEN, MAVLINK_MSG_ID_MotorParameter_LEN, MAVLINK_MSG_ID_MotorParameter_CRC);
}

/**
 * @brief Pack a motorparameter message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID   Mortor ID
 * @param Speed   Mortor Speed 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motorparameter_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ID,uint32_t Speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MotorParameter_LEN];
    _mav_put_uint32_t(buf, 0, Speed);
    _mav_put_uint8_t(buf, 4, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MotorParameter_LEN);
#else
    mavlink_motorparameter_t packet;
    packet.Speed = Speed;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MotorParameter_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MotorParameter;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MotorParameter_MIN_LEN, MAVLINK_MSG_ID_MotorParameter_LEN, MAVLINK_MSG_ID_MotorParameter_CRC);
}

/**
 * @brief Encode a motorparameter struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motorparameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motorparameter_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motorparameter_t* motorparameter)
{
    return mavlink_msg_motorparameter_pack(system_id, component_id, msg, motorparameter->ID, motorparameter->Speed);
}

/**
 * @brief Encode a motorparameter struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motorparameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motorparameter_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motorparameter_t* motorparameter)
{
    return mavlink_msg_motorparameter_pack_chan(system_id, component_id, chan, msg, motorparameter->ID, motorparameter->Speed);
}

/**
 * @brief Send a motorparameter message
 * @param chan MAVLink channel to send the message
 *
 * @param ID   Mortor ID
 * @param Speed   Mortor Speed 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motorparameter_send(mavlink_channel_t chan, uint8_t ID, uint32_t Speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MotorParameter_LEN];
    _mav_put_uint32_t(buf, 0, Speed);
    _mav_put_uint8_t(buf, 4, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorParameter, buf, MAVLINK_MSG_ID_MotorParameter_MIN_LEN, MAVLINK_MSG_ID_MotorParameter_LEN, MAVLINK_MSG_ID_MotorParameter_CRC);
#else
    mavlink_motorparameter_t packet;
    packet.Speed = Speed;
    packet.ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorParameter, (const char *)&packet, MAVLINK_MSG_ID_MotorParameter_MIN_LEN, MAVLINK_MSG_ID_MotorParameter_LEN, MAVLINK_MSG_ID_MotorParameter_CRC);
#endif
}

/**
 * @brief Send a motorparameter message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motorparameter_send_struct(mavlink_channel_t chan, const mavlink_motorparameter_t* motorparameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motorparameter_send(chan, motorparameter->ID, motorparameter->Speed);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorParameter, (const char *)motorparameter, MAVLINK_MSG_ID_MotorParameter_MIN_LEN, MAVLINK_MSG_ID_MotorParameter_LEN, MAVLINK_MSG_ID_MotorParameter_CRC);
#endif
}

#if MAVLINK_MSG_ID_MotorParameter_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motorparameter_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ID, uint32_t Speed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, Speed);
    _mav_put_uint8_t(buf, 4, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorParameter, buf, MAVLINK_MSG_ID_MotorParameter_MIN_LEN, MAVLINK_MSG_ID_MotorParameter_LEN, MAVLINK_MSG_ID_MotorParameter_CRC);
#else
    mavlink_motorparameter_t *packet = (mavlink_motorparameter_t *)msgbuf;
    packet->Speed = Speed;
    packet->ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorParameter, (const char *)packet, MAVLINK_MSG_ID_MotorParameter_MIN_LEN, MAVLINK_MSG_ID_MotorParameter_LEN, MAVLINK_MSG_ID_MotorParameter_CRC);
#endif
}
#endif

#endif

// MESSAGE MotorParameter UNPACKING


/**
 * @brief Get field ID from motorparameter message
 *
 * @return   Mortor ID
 */
static inline uint8_t mavlink_msg_motorparameter_get_ID(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field Speed from motorparameter message
 *
 * @return   Mortor Speed 
 */
static inline uint32_t mavlink_msg_motorparameter_get_Speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a motorparameter message into a struct
 *
 * @param msg The message to decode
 * @param motorparameter C-struct to decode the message contents into
 */
static inline void mavlink_msg_motorparameter_decode(const mavlink_message_t* msg, mavlink_motorparameter_t* motorparameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    motorparameter->Speed = mavlink_msg_motorparameter_get_Speed(msg);
    motorparameter->ID = mavlink_msg_motorparameter_get_ID(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MotorParameter_LEN? msg->len : MAVLINK_MSG_ID_MotorParameter_LEN;
        memset(motorparameter, 0, MAVLINK_MSG_ID_MotorParameter_LEN);
    memcpy(motorparameter, _MAV_PAYLOAD(msg), len);
#endif
}
