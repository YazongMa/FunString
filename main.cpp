#include <stdio.h>
#include <stdlib.h>

#include "FunBase.h"
#include "ByteStream.h"


int Test1()
{
  unsigned char byIssuerAuthData[4096] = { 0 };
  const char* pbyData = "9108E148CF7B00800000";
  int wLen = strlen(pbyData);
	
  int j=0;
  char chTmp[3] = {0};
  for (int i=0; i < wLen; i+=2)
  {
      chTmp[0] = *(pbyData + i);
      chTmp[1] = *(pbyData + i + 1);
      chTmp[2] = '\0'; 
      byIssuerAuthData[j++] = static_cast<BYTE>(strtol(chTmp, NULL, 16));
  }
  
  for (int i=0; i<j; ++i)
  {
  	printf("%02X", byIssuerAuthData[i]);	
  }
  printf("\n");

	return 0;	
}


int Test2()
{
  CByteStream cData;
  cData.Write("abcde", 5);
  return 0;  
}


int main()
{
  Test2();
  return 0;
}
