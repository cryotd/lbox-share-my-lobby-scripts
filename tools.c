// lpEndpoint = "/sl/v"
// lpParams = 00000042673BDA10         i=59D0CD&u=rijin.ramesh@drof.space..............................  
__int64 __fastcall LB::MakeWebRequest_Wrap(__int64 lpEndpoint, __int64 *a2, __int64 lpParams, __int64 a4, char a5)
{
  __int64 *v7; // rax
  __int64 v8; // r9
  __int64 v9; // r11
  unsigned int v10; // er11
  char *v12[3]; // [rsp+30h] [rbp-18h] BYREF

  v7 = (__int64 *)LB::DecodeString(v12, byte_4000001362C6);
  LB::MakeWebRequest_0(lpEndpoint, a2, v9, v8, a5, *v7);
  LB::DecodeString2(v12);
  return v10;
}

__int64 __fastcall LB::MakeWebRequest_0(__int64 a1, __int64 *a2, __int64 a3, __int64 a4, char a5, __int64 a6)
{
  __int64 *pszDomain; // rax
  unsigned int nRequestLen; // er9
  char *lpRequestData; // r10
  __int64 lpEndpoint; // r11
  int v12; // [rsp+40h] [rbp-18h] BYREF
  char *v13[2]; // [rsp+48h] [rbp-10h] BYREF
  int v14; // [rsp+68h] [rbp+10h] BYREF

  v14 = 0;
  v12 = 0;
  pszDomain = (__int64 *)LB::DecodeString(v13, lmaoboxdotnet);
  *a2 = (__int64)LB::ShareMyLobbyWrap(*pszDomain, lpEndpoint, a6, &v12, (__int64)&v14, lpRequestData, nRequestLen, a5);
  LB::DecodeString2(v13);
  return (unsigned int)(*a2 != 0) - 1;
}

void *__fastcall LB::ShareMyLobbyWrap(
        __int64 pszDomain,
        __int64 lpEndpoint,
        __int64 a3,
        _DWORD *a4,
        __int64 a5,
        char *lpRequestData,
        unsigned int nRequestLen,
        char a8)
{
  __int64 numLeft; // r11
  char *lpEncodedRequestDataPtr; // r10
  char v10; // al

  numLeft = nRequestLen;
  if ( nRequestLen )
  {
    lpEncodedRequestDataPtr = lpRequestData;
    do
    {
      v10 = *lpEncodedRequestDataPtr++;
      --numLeft;
      *(lpEncodedRequestDataPtr - 1) = ~v10;
    }
    while ( numLeft );
  }
  if ( a8 )
    return LB::HttpsRequestToBuffer(pszDomain, lpEndpoint, a3, a4, a5);
  LB::HttpsRequestWithoutResponseRead(pszDomain, lpEndpoint, a3, lpRequestData, nRequestLen);
  return 0i64;
}