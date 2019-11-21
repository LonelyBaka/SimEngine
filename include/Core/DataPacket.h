#pragma once
#include <vector>
/// ����� ����������� ������������ ���������
class TDataPacket
{
protected:
  /// ������ ������
  char* data;
  /// ������ ������� ������ � ������
  int size;
public:
  TDataPacket(int* _data, int _size = 1);
  TDataPacket(double* _data, int _size = 1);
  TDataPacket(char* _data, int _size = 1);
  TDataPacket(const TDataPacket& packet);
  ~TDataPacket();

  virtual char* GetData();
  virtual int GetSize();
  virtual void Setdata(char* _data);
  virtual void SetSize(int _size);
  virtual int* GetInts();
  virtual double* GetDoubles();
};