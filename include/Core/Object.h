#pragma once
#include"Core/Properties.h"

/// ������� ����� ����������� ������ ������� ����� ������� � ���.
class IObject
{
public:

  virtual void SetProperty(IProperties& property, std::string _name) = 0;
  virtual void SetProperty(IProperties& property) = 0;
  virtual std::vector<IProperties*> GetProperties() = 0;
  virtual IProperties& GetProperty(std::string _name = "") = 0;

  virtual std::string GetName() = 0;
  virtual void SetName(std::string _name) = 0;
};

/// ���������� �������� �������
class TObject : public IObject
{
protected:
  /// ����� ������� �������
  std::vector<IProperties*> properties;
  /// ��� �������
  std::string name;
public:
  TObject();
  TObject(const TObject& obj);

  virtual void SetProperty(IProperties& _property);
  virtual void SetProperty(IProperties& property, std::string _name) ;
  virtual std::vector<IProperties*> GetProperties();
  virtual IProperties& GetProperty(std::string _name = "");

  virtual std::string GetName();
  virtual void SetName(std::string _name);
};
