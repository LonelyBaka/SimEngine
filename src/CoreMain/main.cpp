#include <iostream>
#include "Core/main.h"

#include "Core/ObjectOfObservation.h"

int main(int argc, char* argv[])
{
  std::cout << "Hello World!\n";
  main0(argc, argv);

  TCoordinateObject a;
  IProperties& coordinate = a.GetProperty();
  coordinate.SetValues({ 20, 25 });
  a.SetProperty(coordinate); // �� �����������
  coordinate.SetValues({ 40, 45 });
  return 0;
}