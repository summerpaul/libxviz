/**
 * @Author: Xia Yunkai
 * @Date:   2024-06-29 13:30:00
 * @Last Modified by:   Xia Yunkai
 * @Last Modified time: 2024-07-24 00:05:58
 */
#ifndef __SUBSCRIBER_H__
#define __SUBSCRIBER_H__
#include <string>
namespace event_bus
{
    class Event;
    class Subscriber
    {
    public:
        virtual void OnNewEvent(Event *evt) = 0;
        virtual bool Subscribe(const std::string &evtName);
        virtual bool Unsubscribe(const std::string &evtName);
    };

} // namespace event_bus
#endif /* __SUBSCRIBER_H__ */
