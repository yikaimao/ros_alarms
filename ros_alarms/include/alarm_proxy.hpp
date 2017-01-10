#pragma once 

#include <ros/ros.h>
#include <ros_alarms/Alarm.h>

#include <string>

struct AlarmProxy
{
  AlarmProxy(std::string alarm_name,
        bool raised,
        std::string node_name,
        std::string problem_description,
        std::string json_parameters,
        uint8_t severity)
  {
    alarm_name = alarm_name;
    raised = raised;
    node_name = node_name;
    problem_description = problem_description;
    json_parameters = json_parameters;
    severity = severity;
  }

  AlarmProxy(std::string alarm_name,
        bool raised,
        std::string problem_description,
        std::string json_parameters,
        uint8_t severity)
  {
    *this = AlarmProxy(alarm_name, raised, ros::this_node::getName(), problem_description,
                  json_parameters, severity);
  }

  AlarmProxy(ros_alarms::Alarm msg)
  {
    alarm_name = msg.alarm_name;
    raised = msg.raised;
    node_name = msg.node_name;
    problem_description = msg.problem_description;
    json_parameters = msg.parameters;
    severity = msg.severity;
  }

  ros_alarms::Alarm as_msg()
  {
    ros_alarms::Alarm a;
    a.alarm_name = alarm_name;
    a.raised = raised;
    a.node_name = node_name;
    a.problem_description = problem_description;
    a.parameters = json_parameters;
    a.severity = severity;
    return a;
  }

  std::string alarm_name;
  bool raised;
  std::string node_name;
  std::string problem_description;
  std::string json_parameters;
  uint8_t severity;
};