#pragma once
#include "Core/ObjectOfObservation.h"
#include "Core/SmartThing.h"
/// ������� ������� �����
class TScene : public TObject
{
protected:
  /// ������� ����������� �� ���� �������� �����
  std::vector<TObjectOfObservation*> objectsOfObservation;
  /// ���� ����������� �� ���� �������� �����
  std::vector<TSmartThing*> smartThings;
  /// ������ �������� ����� ����������� � ���� ��������
  std::vector<TScene*> scenes;
public:
  TScene(std::string _name);
  TScene(const TScene& _scene);
  virtual void AddObject(TObjectOfObservation& obect);
  virtual void AddThing(TSmartThing& obect);
  virtual void ExcludeObject(TObjectOfObservation& obect);
  virtual void AddSceneObject(TScene& obect);
  virtual void ExcludeSceneObject(TScene& obect);
};

