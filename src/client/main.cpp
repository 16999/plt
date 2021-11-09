#include <render/Scene.h>


render::Scene s(960,540,"TANKS GAME");

int main(int argc,char* argv[])
{
  //refresh();
  s.init();
  while(1)
  {
    s.refresh();
  }
}
