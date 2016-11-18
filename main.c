#include <stdio.h>
#include <assert.h>
#include "nscanf.h"

int main(int argc,char *argv[])
{
  int i, r, yy, mm, dd;
  float fval;

  r = nscanf("2016/11/18", "%d/%d/%d",&yy,&mm,&dd);
  assert(r == 3);
  assert(yy == 2016);
  assert(mm == 11);
  assert(dd == 18);
  
  r = nscanf("89.4","%f", &fval);
  assert(r == 1);
  assert(fval > 89.4 - 0.001 && fval < 89.4 + 0.001);
  
  r = nscanf("-89.4","%f", &fval);
  assert(r == 1);
  assert(fval > -89.4 - 0.001 && fval < -89.4 + 0.001);
  
  r = nscanf("-1234","%d", &i);
  assert(r == 1);
  assert(i == -1234);

  r = nscanf("1234","%d", &i);
  assert(r == 1);
  assert(i == 1234);
  
  return 0;
}
