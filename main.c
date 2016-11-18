#include <stdio.h>
#include <assert.h>
#include "nscanf.h"

int main(int argc,char *argv[])
{
  int a, b, c, i, r, yy, mm, dd;
  float fval;

  r = nscanf("2016/11/18", "%d/%d/%d",&yy,&mm,&dd);
  assert(r == 3);
  assert(yy == 2016);
  assert(mm == 11);
  assert(dd == 18);
  
  r = nscanf("10 ", "%d\f", &i);
  assert(r == 2);
  assert(i == 10);
  
  r = nscanf("10", "%d\f", &i);
  assert(r == 2);
  assert(i == 10);
  
  r = nscanf("10a", "%d\f", &i);
  assert(r == 1);
  assert(i == 10);

  r = nscanf("10","%x", &i);
  assert(r == 1);
  assert(i == 16);
  
  r = nscanf("10 ab -20","%d %x %d", &a, &b, &c);
  assert(r == 3);
  assert(a == 10);
  assert(b == 0xab);
  assert(c == -20);
  
  r = nscanf("abc","%d", &i);
  assert(r == 0);
  
  r = nscanf("  abc","%g", &fval);
  assert(r == 0);

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
