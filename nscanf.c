#include <stdlib.h>
#include <stdarg.h>
#include "nscanf.h"

#define EOS_MATCHER_CHAR	'\\'

static int n_isspace(char c)
{
  return c == ' ' || c == 't' || c == '\n' || c == '\r';
}


int nscanf(const char *str, const char *fmt, ...)
{
  int cSuccess = 0;
  const char *rp = str;
  const char *fp = fmt;
  va_list ap;
  char *ep;
  char sc,fc;
  long v;
  
  va_start(ap, fmt);

  while(*rp && *fp){
    fc = *fp++;
    if(n_isspace(fc))
      continue;
    else if(fc != '%'){
      sc = *rp++;
      while(n_isspace(sc))
	sc = *rp++;
      if(sc == 0){
	rp--; fp--;
	break;
      } else if(fc != sc) 
	break;
      
    } else {  /* fc == '%' */
      fc = *fp++;
      if(fc == 'd' || fc == 'x'){
	int *ip = va_arg(ap, int *);
	v = strtol(rp, &ep, fc == 'd' ? 10 : 16);
	if(rp == ep) break;
	rp = ep;
	*ip = v;
	cSuccess++;
      } else if(fc == 'f' || fc == 'g' || fc == 'e'){
	double fv = strtod(rp, &ep);
	if(ep == rp)
	  break;
	float *vp = va_arg(ap, float *);
	*vp = fv;
	cSuccess++;
	rp = ep;
      }
    }
  }
#ifdef EOS_MATCHER_CHAR
  if(*rp == 0 && *fp == EOS_MATCHER_CHAR)
    cSuccess++;
#endif
  
  va_end(ap);
  return cSuccess;
}
