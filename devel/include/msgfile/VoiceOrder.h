// Generated by gencpp from file msgfile/VoiceOrder.msg
// DO NOT EDIT!


#ifndef MSGFILE_MESSAGE_VOICEORDER_H
#define MSGFILE_MESSAGE_VOICEORDER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace msgfile
{
template <class ContainerAllocator>
struct VoiceOrder_
{
  typedef VoiceOrder_<ContainerAllocator> Type;

  VoiceOrder_()
    : header()
    , name()
    , emotion()
    , DrinkName()
    , CupNum()
    , Temp()
    , OrderFinish(false)  {
    }
  VoiceOrder_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , name(_alloc)
    , emotion(_alloc)
    , DrinkName(_alloc)
    , CupNum(_alloc)
    , Temp(_alloc)
    , OrderFinish(false)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _emotion_type;
  _emotion_type emotion;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _DrinkName_type;
  _DrinkName_type DrinkName;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _CupNum_type;
  _CupNum_type CupNum;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _Temp_type;
  _Temp_type Temp;

   typedef uint8_t _OrderFinish_type;
  _OrderFinish_type OrderFinish;





  typedef boost::shared_ptr< ::msgfile::VoiceOrder_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msgfile::VoiceOrder_<ContainerAllocator> const> ConstPtr;

}; // struct VoiceOrder_

typedef ::msgfile::VoiceOrder_<std::allocator<void> > VoiceOrder;

typedef boost::shared_ptr< ::msgfile::VoiceOrder > VoiceOrderPtr;
typedef boost::shared_ptr< ::msgfile::VoiceOrder const> VoiceOrderConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msgfile::VoiceOrder_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msgfile::VoiceOrder_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace msgfile

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'msgfile': ['/home/kevin/catkin_ws/src/msgfile/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::msgfile::VoiceOrder_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msgfile::VoiceOrder_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msgfile::VoiceOrder_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msgfile::VoiceOrder_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msgfile::VoiceOrder_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msgfile::VoiceOrder_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msgfile::VoiceOrder_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f3495cb493dec155ce56f80a0b3b1959";
  }

  static const char* value(const ::msgfile::VoiceOrder_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf3495cb493dec155ULL;
  static const uint64_t static_value2 = 0xce56f80a0b3b1959ULL;
};

template<class ContainerAllocator>
struct DataType< ::msgfile::VoiceOrder_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msgfile/VoiceOrder";
  }

  static const char* value(const ::msgfile::VoiceOrder_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msgfile::VoiceOrder_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header \n\
string name\n\
string emotion\n\
string DrinkName\n\
string CupNum\n\
string Temp\n\
bool OrderFinish\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::msgfile::VoiceOrder_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msgfile::VoiceOrder_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.name);
      stream.next(m.emotion);
      stream.next(m.DrinkName);
      stream.next(m.CupNum);
      stream.next(m.Temp);
      stream.next(m.OrderFinish);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct VoiceOrder_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msgfile::VoiceOrder_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msgfile::VoiceOrder_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "emotion: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.emotion);
    s << indent << "DrinkName: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.DrinkName);
    s << indent << "CupNum: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.CupNum);
    s << indent << "Temp: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.Temp);
    s << indent << "OrderFinish: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.OrderFinish);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSGFILE_MESSAGE_VOICEORDER_H
