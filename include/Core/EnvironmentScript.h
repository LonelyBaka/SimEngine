#pragma once

#include <string>
#include <vector>


#include "Core/Object.h"
#include "Core/Properties.h"


/**
����� �������� ������� ������������ ������ �������
��� ��������, ����� ������, ����� �����, ��������
*/
class TPropertyInterval
{
public:
  std::string nameProperty;

  std::vector<unsigned long int> startTime;
  std::vector<unsigned long int> endTime;
  std::vector <std::vector<double>> value;

  std::vector<double> GetValue(unsigned long int time)
  {
    for (int i = 0; i < startTime.size(); i++)
    {
      if ((time > startTime[i]) && (time < endTime[i]))
        return value[i];
    }
  }

};

/// ������� ����� ����������� ������� ������������� �� ������� �������� �������
class TEnvironmentScript
{
protected:
  /// ����������� �������
  std::vector<IObject*> objects;
  /// ���(������ ����) �������
  std::string script;
  
  /// ��������� ���������� ����� � ��������������� �������� ��� ������� ��������
  std::vector<std::vector<TPropertyInterval>> objectPropertyIntervals;


  /// ������ �������� ���������� ������� � ������������ �� ��������
  std::vector <IProperties*>& ChangeProperties(int objectIndex, std::vector <IProperties*>& properties, unsigned long int time);


public:
  TEnvironmentScript(std::vector<IObject*> _objects, std::string _script);
  virtual std::vector <IProperties*>& GetObjectProperties(std::string name, unsigned long int time);
  virtual std::vector <IProperties*>& GetObjectProperties(IObject& object, unsigned long int time);
};