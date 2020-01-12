// #include "TUN_Scale.cpp"
#include "SCL_Import.cpp"
#include <iostream>

using namespace std;

int main() {
  // CSingleScale test;
  // test.Read("")

  TUN::CSCL_Import test2;
  test2.ReadSCL("/Users/tp3/Downloads/scl/amity53pure.scl");

  TUN::CSingleScale scale;
  test2.SetSingleScale(scale);

  scale.Write("./test_scale_out");
  cout << scale.GetBaseNote() << " " << scale.GetBaseFreqHz()
    << " " << scale.GetMIDINoteFreqHz(70) << endl;
  scale.Reset();
  cout << scale.GetBaseNote() << " " << scale.GetBaseFreqHz()
    << " " << scale.GetMIDINoteFreqHz(70) << endl;
}
