// MESSAGE MotorParameter support class

#pragma once

namespace mavlink {
namespace motor_param {
namespace msg {

/**
 * @brief MotorParameter message
 *
 * Motor Parameter.
 */
struct MotorParameter : mavlink::Message {
    static constexpr msgid_t MSG_ID = 996;
    static constexpr size_t LENGTH = 5;
    static constexpr size_t MIN_LENGTH = 5;
    static constexpr uint8_t CRC_EXTRA = 112;
    static constexpr auto NAME = "MotorParameter";


    uint8_t ID; /*<   Mortor ID */
    uint32_t Speed; /*<   Mortor Speed  */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  ID: " << +ID << std::endl;
        ss << "  Speed: " << Speed << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << Speed;                         // offset: 0
        map << ID;                            // offset: 4
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> Speed;                         // offset: 0
        map >> ID;                            // offset: 4
    }
};

} // namespace msg
} // namespace motor_param
} // namespace mavlink
