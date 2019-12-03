#include <stdio.h>
#include <string.h>
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


int test4(char* a[], int n)
{
  for(int i=0; i<n; ++i)
  {
    printf("%s\n", a[i]);
  }

  return n;
}

int Test3()
{
  char szArray[][12] = 
  {
    "abcd",
    "dede",
    "24342",
    "f32f4w"
  };

  int n = sizeof(szArray) / sizeof(szArray[0]);
  test4((char **)szArray, n);

  unsigned long a = 0;
  unsigned long b = 0;
  
  
  return 0;  
}


int main()
{
//  Test3();

  char szUserInput[12] = { 0 };
  strcpy(szUserInput, (char *)"##2");

  
  int nSelIndex = -1;
  int nScanRet = -1;
  nScanRet = sscanf((char *)szUserInput, "##%d", &nSelIndex);
  printf("%d, %d\n", nScanRet, nSelIndex);

  return 0;
}
