#include <render/Scene.h>


render::Scene s;

int main(int argc,char* argv[])
{
  //refresh();
  s.init();
  while(1)
  {
    s.refresh();
  }
}
