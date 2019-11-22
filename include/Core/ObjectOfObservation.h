#pragma once

#include "Core/Object.h"


/// ������� ���������� ��� ����������� ��������
class TObjectOfObservation : public TObject
{
protected:

  /// ������ ������� �������
  TObjectOfObservation* parentObject;
  /// ������� ������� �������, ���� �������� ���������, ������� �������� ������ ������
  std::vector<TObjectOfObservation*> childObjects;
  /// �������� �������
  std::vector<TObjectOfObservation*> neighboringObject;
  /// ��� �������� ������� ������� � ���� ������
  std::vector<IProperties*> allProperties;
  
public:
  TObjectOfObservation(std::string _name, std::vector<TObjectOfObservation*> _neighboringObject = {nullptr},
    TObjectOfObservation* _parentObject = nullptr, TObjectOfObservation* _childObject = nullptr);
  TObjectOfObservation(const TObjectOfObservation& obj);

  /// �������� ������ ������� �������� ���������� �������� �������
  virtual void AddParentObject(TObjectOfObservation& obect);
  /// �������� �������� ������
  virtual int AddChildObject(TObjectOfObservation& obect);
  /// ���������� ������ �������� ��������, ������ �������� ������ ���� �������
  virtual std::vector<TObjectOfObservation*> GetChildObject();
  /// �������� �������� ������, ����� ���� ����� ����������� ������ ��������� ���������
  virtual void AddNeighboringObject(TObjectOfObservation& obect);
  /// ��������� �������� ������
  virtual void ExcludeChildObject(TObjectOfObservation& obect);
  /// ��������� �������� ������� ������� 
  virtual void Update();
  /// ���������� ��� �������� �������
  virtual std::vector<IProperties*>& GetProperties();
};