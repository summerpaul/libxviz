/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-29 13:03:04
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-07-24 00:05:40
 */
#ifndef __EVENT_H__
#define __EVENT_H__
#include <string>

namespace event_bus
{
    class Event
    {
    public:
        virtual ~Event() {}
        virtual std::string GetName()
        {
            return typeid(*this).name();
        }
    };

    template <typename T>
    class TypeIdentifier
    {
    public:
        static std::string name()
        {
            return typeid(T).name();
        }
    };
}
#endif /* __EVENT_H__ */
