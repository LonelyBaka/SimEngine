#pragma once

#include <string>
#include <vector>

#include "Core/DataPacket.h"
#include "Core/ObjectOfObservation.h"

/// ��������� ������ ������� ����� ��������� �� ���������
class ISensor
{
public:
  virtual TDataPacket GetDataPacket() = 0;
  virtual void AddObject(TObjectOfObservation& object) = 0;
  virtual void ExcludeObject(TObjectOfObservation& object) = 0;
  virtual void ExcludeObject(std::string objectName) = 0;

  virtual std::string GetName() = 0;
  virtual void SetName(std::string _name) = 0;
};

class TSensor : public ISensor
{
protected:
  /// ��� �������
  std::string name;
  /// ����������� �������
  std::vector<TObjectOfObservation*> objects;
  /// �������� ���� ����������� ��������
  std::vector<std::vector<IProperties*>> objectsProperties;
  /// ������������ �����
  TDataPacket* packet;
public:
  TSensor(std::string _name);
  TSensor(const TSensor& sensor);

  virtual TDataPacket GetDataPacket();
  virtual void AddObject(TObjectOfObservation& object);
  virtual void ExcludeObject(TObjectOfObservation& object);
  virtual void ExcludeObject(std::string objectName);
  virtual std::string GetName();
  virtual void SetName(std::string _name);

};

