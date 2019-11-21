#include "Core/Sensor.h"

TSensor::TSensor(std::string _name) : packet(nullptr)
{
  SetName(_name);
}

TSensor::TSensor(const TSensor& sensor)
{
  this->packet = sensor.packet;
  this->name = sensor.name;
  this->objects = sensor.objects;
}

TDataPacket TSensor::GetDataPacket()
{
  std::vector<std::vector<std::vector<double>>> vals(objects.size());
  int propertyCount = 0;
  for (int i = 0; i < objects.size(); i++)
  {
    if (objects[i] != nullptr)
    {
      objectsProperties[i] = objects[i]->GetProperties();
      vals[i].resize(objectsProperties[i].size());
      for (int j = 0; j < objectsProperties[i].size(); j++)
      {
        if (objectsProperties[i][j] != nullptr)
        {
          vals[i][j] = objectsProperties[i][j]->GetValues();
            propertyCount += vals[i][j].size();
        }
      }
    }
  }
  packet->SetSize(propertyCount * sizeof(double));
  double* data = packet->GetDoubles();
  int t = 0;
  for (int i = 0; i < vals.size(); i++)
  {
    for (int j = 0; j < vals[i].size(); j++)
    {
      for (int k = 0; k < vals[i][j].size(); k++)
      {
        data[t] = vals[i][j][k];
        t++;
      }
    }
  }

  return *packet;
}

void TSensor::AddObject(TObjectOfObservation& object)
{
  for (int i = 0; i < objects.size(); i++)
  {
    if (objects[i] == &object)
      return;
  }
  objects.push_back(&object);
  objectsProperties.resize(objects.size());
}

void TSensor::ExcludeObject(TObjectOfObservation& object)
{
  for (int i = 0; i < objects.size(); i++)
  {
    if (objects[i] == &object)
    {
      objects[i] = nullptr;
      ///�������� �����������
    }
  }
}

void TSensor::ExcludeObject(std::string objectName)
{
  for (int i = 0; i < objects.size(); i++)
  {
    if (objects[i] != nullptr)
    {
      if (objects[i]->GetName() == objectName)
      {
        objects[i] = nullptr;

        ///�������� �����������
      }
    }
  }
}

std::string TSensor::GetName()
{
  return name;
}

void TSensor::SetName(std::string _name)
{
  if (_name.length() > 0)
    name = _name;
  else
    throw - 1;
}